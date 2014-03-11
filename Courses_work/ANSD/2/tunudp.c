/*************************************************
 * TASS Course:
 * Advanced Network Solutions Design
 * TUN over UDP
 *
 * Author:  Bart Volkaerts
 * Date:    22/01/2014
 * 
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <unistd.h>

#define SIZE 10
#define BUFSIZE 65536

int tun_alloc(char *dev, int flags)
{
  struct ifreq ifr;
  int fd, err;
  char *clonedev = "/dev/net/tun";

  if( (fd = open(clonedev, O_RDWR)) < 0 )
  {
    return fd;
  }
  memset(&ifr, 0, sizeof(ifr));
  ifr.ifr_flags = flags;
  if (*dev)
  {
    strncpy(ifr.ifr_name, dev, SIZE);
  }
  if ( (err = ioctl(fd, TUNSETIFF, (void*)&ifr)) < 0 )
  {
    close(fd);
    return err;
  }
  strcpy(dev, ifr.ifr_name);
  return fd;
}

static void usage(char *pname)
{
    fprintf(stderr, "Usage: %s hostname port\n", pname);
    exit(1);
}

int main(int argc, char **argv)
{
  int tunfd, socketfd, len;
  //struct sockaddr_storage servaddr;
  //socklen_t socklen = sizeof(servaddr);
  //struct addrinfo *ai;
  struct sockaddr_in local_addr = {};
  struct sockaddr_in rem_addr = {};
  char *a_name = malloc(sizeof(char)*SIZE);
  unsigned char buf[BUFSIZE];     /* receive buffer */

  //servaddr.ss_family = AF_LOCAL; /* Error condition */

  if (argc != 3)
    usage(argv[0]); /* Implies exit() */

  a_name[0]='\0';
  tunfd = tun_alloc(a_name, IFF_TUN | IFF_NO_PI); 
  /*
  getaddrinfo(argv[1], NULL, NULL, &ai);
  while(ai) {
    int copy = 0;
    if (ai->ai_family == AF_INET) {
      printf("IPv4 address detected!\n");
      socklen = sizeof(struct sockaddr_in);
      copy = 1;
    }
    if (copy) {
      memcpy(&servaddr, ai->ai_addr, ai->ai_addrlen);
      servaddr.ss_family = ai->ai_family;
      break;
    }
    ai = ai->ai_next;
  }

  if (servaddr.ss_family == AF_LOCAL) {
      fprintf(stderr, "Could not contact host \"%s\"\n", argv[1]);
      exit(6);
  }*/

  socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketfd < 0)
  {
    perror("ERROR opening socket");
    exit(1);
  }
  printf("Binding: IPv4\n");
  //((struct sockaddr_in *)&servaddr)->sin_port = htons(atoi(argv[2])); 
  local_addr.sin_family = AF_INET;
  local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  local_addr.sin_port = htons(atoi(argv[2]));
  bind(socketfd, (struct sockaddr *)&local_addr, sizeof(struct sockaddr_in));

  rem_addr.sin_family = AF_INET;
  rem_addr.sin_addr.s_addr = inet_addr(argv[1]);
  rem_addr.sin_port = htons(atoi(argv[2]));

  for(;;)
  {
    struct pollfd fds[] = {
      { socketfd, POLLIN },
      { tunfd, POLLIN }
    };

    if ( poll(fds,2,0) > 0 )
    {
      if (fds[0].revents & POLLIN) 
      {
        len = recv(socketfd, buf, BUFSIZE, 0);
        if (len < 0)
          return -1;
        
        len = write(tunfd, buf, len);
        fprintf(stdout, "Wrote %d bytes from network to tun\n", len);
      }
      if (fds[1].revents & POLLIN) 
      {
        len = read(tunfd, buf, BUFSIZE);
        len = sendto(socketfd, buf, len, 0, (struct sockaddr *)&rem_addr, sizeof(rem_addr));
        fprintf(stdout, "Wrote %d bytes from tun to network\n", len);
      }
    }
  }

  return 0;
}
