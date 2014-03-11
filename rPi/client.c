#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORTNUM 2343
#define MAXSNDLEN 5

int main(int argc, char *argv[])
{
  if(argc!=2)
  {
    fprintf(stderr, "%s: Usage: ./program UP|STOP|DOWN|QUIT\n", argv[0]);
    exit(1);
  }

  int len, mysocket;
  struct sockaddr_in dest; 
  char buffer[MAXSNDLEN];
  len = strlen(argv[1]);
  memset(buffer, '\0', MAXSNDLEN);
  memcpy(buffer, argv[1], len);

  mysocket = socket(AF_INET, SOCK_STREAM, 0);
  if(-1 == mysocket)
  {
    fprintf(stderr, "%s: Unable to create socket\n", argv[0]);
    exit(1);
  }

  memset(&dest, 0, sizeof(dest));
  dest.sin_family = AF_INET;
  dest.sin_addr.s_addr = inet_addr("192.168.1.106"); 
  dest.sin_port = htons(PORTNUM);

  if(-1==connect(mysocket, (struct sockaddr *)&dest, sizeof(struct sockaddr)))
  {
    fprintf(stderr, "%s: Could not connect to socket\n", argv[0]);
    exit(1);
  }
  
  send(mysocket, buffer, MAXSNDLEN, 0);

  close(mysocket);
  return EXIT_SUCCESS;
}
