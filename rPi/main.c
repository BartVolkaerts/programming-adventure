/************************************************************
Program for the automatisation of the window rolling shutter.
Program reads input from TCP socket

Hardware: Raspberry Pi (GPIO)
Dependencies: BCM2835-library

After installing bcm2835, you can build this with 
something like:
 gcc -o server main.c -l bcm2835

Version: 0.1
Author: Bart Volkaerts
Copyright (c) 2013 Bart Volkaerts
************************************************************/

#include "main.h"

#define DEBUG_MODE 0
#define MAXRCVLEN 5
#define PORTNUM 2343

void shutterUp();
void shutterStop();
void shutterDown();

int main(int argc, char **argv) 
{
  char buffer[MAXRCVLEN];
  int mysocket;
  struct sockaddr_in dest;
  struct sockaddr_in serv;
  socklen_t socksize = sizeof(struct sockaddr_in);

  // If you call this, it will not actually access the GPIO
  // Use for testing
  bcm2835_set_debug(DEBUG_MODE);

  if(!bcm2835_init())
  {
    fprintf(stderr, "%s: Oops.. Something went wrong during init!\n", argv[0]);
    exit(1);
  }

  // Set pins as output
  bcm2835_gpio_fsel(PIN_UP,   BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(PIN_STOP, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(PIN_DOWN, BCM2835_GPIO_FSEL_OUTP);

  memset(&serv, 0, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = htonl(INADDR_ANY);
  serv.sin_port = htons(PORTNUM);

  // Create a socket
  mysocket = socket(AF_INET, SOCK_STREAM, 0);
  if(-1==mysocket)
  {
    fprintf(stderr, "%s: Unable to create socket\n", argv[0]);
    exit(1);
  }
  // Bind serv info to mysocket
  if(-1==bind(mysocket, (struct sockaddr *)&serv, sizeof(struct sockaddr)))
  {
    fprintf(stderr, "%s: Unable to bind\n", argv[0]);
    exit(1);
  }
  // Start listening; allowing a queue of 1 pending connection
  listen(mysocket, 1);
  int consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);

  while(consocket)
  {
    fprintf(stdout, "%s: Incoming connection from %s\n", argv[0], inet_ntoa(dest.sin_addr));
    if(recv(consocket, buffer, MAXRCVLEN, 0) > 0)
    {
      if(strcmp("UP", buffer) == 0)
        shutterUp();
      else if(strcmp("STOP", buffer) == 0)
        shutterStop();
      else if(strcmp("DOWN", buffer) == 0)
        shutterDown();
      else if(strcmp("QUIT", buffer) == 0)
        break;
      
      printf("\t\t[OK]\n");
    }
    consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
  }

  shutdown(mysocket,0);
  bcm2835_close();
  return EXIT_SUCCESS;
}

void shutterUp()
{
  printf("Sending UP signal..");
  bcm2835_gpio_write(PIN_UP, HIGH);
  bcm2835_delay(500);
  bcm2835_gpio_write(PIN_UP, LOW);
}

void shutterStop()
{
  printf("Sending STOP signal..");
  bcm2835_gpio_write(PIN_STOP, HIGH);
  bcm2835_delay(500);
  bcm2835_gpio_write(PIN_STOP, LOW);
}

void shutterDown()
{
  printf("Sending DOWN signal..");
  bcm2835_gpio_write(PIN_DOWN, HIGH);
  bcm2835_delay(500);
  bcm2835_gpio_write(PIN_DOWN, LOW);
}
