/*************************************************
 * Advanced Network Solutions Design
 *
 * Authors:  TASS People
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
#include <sys/poll.h>

#define AANTAL 5
#define LENGTE 6

#pragma pack(1)
struct message_header {
  uint32_t TYPE_nodeID;
  uint16_t n_sensors;
  uint16_t msg_len;
  uint32_t sensors[AANTAL];
  char message[LENGTE];
};

struct __attribute__((packed)) sensor_data_hdr
{
  uint8_t type;
  uint8_t node_id_arr[3];
  uint16_t n_sensors;
  uint16_t msg_len;
};

/* error - wrapper for perror */
void error(char *msg) {
  perror(msg);
  exit(1);
}

int recv_data(int sock)
{
  struct sockaddr_storage ss;
  socklen_t sockaddr_len = sizeof(ss);
  int ret;
  char cli_info[200];
  char buf[2000];
  struct sensor_data_hdr *hdr;
  uint32_t node_id;

  int i;

  ret = recvfrom(sock, buf, 2000, 0, (struct sockaddr *)&ss, &sockaddr_len);
  if (ret < 0)
    return -1;

  printf("Received data...\n");

  if (ss.ss_family == AF_INET) {
    struct sockaddr_in *sa = (struct sockaddr_in *)&ss;
    inet_ntop(AF_INET, &(sa->sin_addr), cli_info, 200);
  } else if (ss.ss_family == AF_INET6) {
    struct sockaddr_in6 *sa = (struct sockaddr_in6 *)&ss;
    inet_ntop(AF_INET6, &(sa->sin6_addr), cli_info, 200);
  } else {
    fprintf(stderr, "Address family not understood: %d\n", ss.ss_family);
    exit(5);
  }
  hdr = (struct sensor_data_hdr *) buf; 

  node_id = 
    (hdr->node_id_arr[0] << 16) + 
    (hdr->node_id_arr[1] << 8) + 
    (hdr->node_id_arr[2]); 


  printf("Connection from %s. Type: %02x, Node id: %08x Number of sensors: %d\n", cli_info, hdr->type, node_id, ntohs(hdr->n_sensors));
  for (i = 0; i < ntohs(hdr->n_sensors); i ++) {
    uint32_t *val = (uint32_t *)(buf + sizeof(struct sensor_data_hdr) + (i * sizeof(uint32_t)));
    printf("Sensor %d value: %lu\n", i, ntohl(*val));
  }
  if (ntohs(hdr->msg_len) > 0) {
    char *msgbuf = malloc(ntohs(hdr->msg_len) + 1);
    memcpy(msgbuf, buf + sizeof(struct sensor_data_hdr) + hdr->n_sensors * sizeof(uint32_t), ntohs(hdr->msg_len));
    msgbuf[ntohs(hdr->msg_len)] = (char)0;
    printf("Msg: %s \n\n", msgbuf);
    free(msgbuf);
  }

  return 0;  
}

static void usage(char *pname)
{
    fprintf(stderr, "Usage: %s hostname port\n", pname);
    exit(1);
}
  
int main(int argc, char **argv)
{
  int i, socketfd;
  struct sockaddr_storage servaddr;
  struct message_header msg;
  struct addrinfo *ai; 
  struct sockaddr_in6 local_addr6 = {};
  struct sockaddr_in local_addr = {};
  socklen_t socklen;

  servaddr.ss_family = AF_LOCAL; /* Error condition */


  if (argc != 3)
    usage(argv[0]); /* Implies exit() */

  getaddrinfo(argv[1], NULL, NULL, &ai);
  while(ai) {
    int copy = 0;
    if (ai->ai_family == AF_INET6) {
      printf("IPv6 address detected!\n");
      socklen = sizeof(struct sockaddr_in6);
      copy = 1;
    }
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
  }

  socketfd = socket(servaddr.ss_family, SOCK_DGRAM, 0);
  if (socketfd < 0)
    error("ERROR opening socket");

  if (servaddr.ss_family == AF_INET) {
    printf("Binding: IPv4\n");
    ((struct sockaddr_in *)&servaddr)->sin_port = htons(atoi(argv[2])); 
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(7412);
    bind(socketfd, (struct sockaddr *)&local_addr, sizeof(struct sockaddr_in));
  } else {
    printf("Binding: IPv6\n");
    ((struct sockaddr_in6 *)&servaddr)->sin6_port = htons(atoi(argv[2]));
    local_addr6.sin6_family = AF_INET6;
    local_addr6.sin6_port = htons(7412);
    bind(socketfd, (struct sockaddr *)&local_addr6, sizeof(struct sockaddr_in6));
  }


  msg.TYPE_nodeID = 23456;
  msg.TYPE_nodeID |= 1<<24;
  msg.TYPE_nodeID = htonl(msg.TYPE_nodeID);
  msg.n_sensors = htons(AANTAL);
  for(i=0;i<AANTAL;i++)
    msg.sensors[i] = htonl(i + 50);
  msg.msg_len = htons(LENGTE);
  strcpy(msg.message,"Hello");


  for(;;) {
    struct pollfd pfd;
    pfd.fd = socketfd;
    pfd.events = POLLIN;
    if (poll(&pfd, 1, 500) == 0)  {
      sendto(socketfd, &msg, sizeof(msg), 0, (struct sockaddr *)&servaddr, socklen);
    } else {
      recv_data(socketfd);
    }
  }

  return 0;
}
