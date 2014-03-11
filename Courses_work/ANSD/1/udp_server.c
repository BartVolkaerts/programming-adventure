/*
 *    UDP server
 *    Author: Maarten Vandersteegen
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include "udp_server.h"

#define MAXMSGLEN     500
#define MAXBUFSIZE    0xFFFF


int main(int argc, char*argv[])
{
  struct sockaddr_in server;
  struct sockaddr_in client;
  socklen_t slen=sizeof(client);
  int sock;
  uint8_t buf[MAXBUFSIZE];
  struct Proto_hdr *hdr_p, hdr;
  Sensortype *sensors;
  char *message;
  int i;

  if ((sock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
    perror("failed to open socket");
    exit(1);
  }
  memset((char *) &server, 0, sizeof(struct sockaddr_in));

  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sock, (struct sockaddr *)&server, sizeof(struct sockaddr_in)) == -1) {
    perror("failed to bind to socket");
    exit(1);
  }

  while(1) {
    /* receive header */
    /* recvfrom does not buffer, we have to buffer our selves */
    if (recvfrom(sock, buf, MAXBUFSIZE, 0, (struct sockaddr *)&client, &slen) == -1) {
      perror("failed to receive");
      exit(1);
    }

    hdr_p = (struct Proto_hdr *)buf;
    hdr.type = hdr_p->type;
    hdr.node_id = ntohl(hdr_p->node_id) >> 8;
    hdr.nr_sensors = ntohs(hdr_p->nr_sensors);
    hdr.msg_len = ntohs(hdr_p->msg_len);

    printf("************ header ************\n");
    printf("type = %d\nnode_id = %d\nnr = %d\nmsg len = %d\n", hdr.type, \
          hdr.node_id, hdr.nr_sensors, hdr.msg_len);

    /* receive sensors */
    sensors = (Sensortype *)(buf + sizeof(struct Proto_hdr));

    printf("************ sensors ************\n");
    for (i=0;i<hdr.nr_sensors;i++) {
      printf("Sensor %d: %d\n",i, ntohl(sensors[i]));
    }

    /* receive message */
    message = (char *)(buf + sizeof(struct Proto_hdr) + (hdr.nr_sensors * sizeof(Sensortype)));
    message[hdr.msg_len] = '\0';

    printf("************ message ************\n");
    printf("%s\n", message);
  }

  close(sock);
  return 0;
}
