/*************************************************
 * Advanced Network Solutions Design
 *
 * Author:  Bart Volkaerts
 * Date:    20/01/2014
 * 
 ************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define AANTAL 5
#define LENGTE 5

#pragma pack(1)
struct message_header {
  uint32_t TYPE_nodeID;
  uint16_t n_sensors;
  uint16_t msg_len;
  uint32_t sensors[AANTAL];
  char message[LENGTE];
};

/* error - wrapper for perror */
void error(char *msg) {
  perror(msg);
  exit(1);
}
  
int main(int argc, char **argv)
{
  int i, socketfd;
  struct sockaddr_in servaddr;
  struct message_header msg;

  socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketfd < 0)
    error("ERROR opening socket");

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(atoi(argv[2]));

  msg.TYPE_nodeID = 23456;
  msg.TYPE_nodeID |= 1<<24;
  msg.TYPE_nodeID = htonl(msg.TYPE_nodeID);
  msg.n_sensors = htons(AANTAL);
  for(i=0;i<AANTAL;i++)
    msg.sensors[i] = htonl(i + 50);
  msg.msg_len = htons(LENGTE);
  strcpy(msg.message,"Hello");

  sendto(socketfd, &msg, sizeof(msg), 0,
                          (struct sockaddr *)&servaddr, sizeof(servaddr));
  return 0;
}
