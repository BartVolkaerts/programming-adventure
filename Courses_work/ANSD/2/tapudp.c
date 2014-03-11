/*************************************************
 * TASS Course:
 * Advanced Network Solutions Design
 * TAP over UDP
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
#define BUFSIZE 1500

#pragma pack(1)
struct hdr {
  char text[16];
  char data[];
};

int tap_alloc(char *dev, int flags)
{
  struct ifreq ifr;
  int fd, err, s;
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
  
  s = socket(AF_INET, SOCK_DGRAM,0);

  ifr.ifr_mtu = 1500-sizeof(struct hdr);
  if (ioctl(s, SIOCSIFMTU, &ifr) < 0)  {
    return -1;
  }

  strcpy(dev, ifr.ifr_name);
  return fd;
}

static void usage(char *pname)
{
    fprintf(stderr, "Usage: %s hostname port cypherkey\n", pname);
    exit(1);
}

unsigned char *xorcypher(char *data, int len, char *key)
{
  int i;
  size_t keylen = strlen(key);

  for(i=0; i<len; i++)
  {
    data[i] = data[i]^key[i % keylen];
  }
  
  return data;
}

int main(int argc, char **argv)
{
  int tapfd, socketfd, len;
  struct sockaddr_in local_addr = {};
  struct sockaddr_in rem_addr = {};
  char *a_name = malloc(sizeof(char)*SIZE);
  struct hdr *hdr_buf;
  unsigned char *buf;     /* receive buffer */
  buf = (unsigned char *)malloc(BUFSIZE);

  if (argc != 4)
    usage(argv[0]); /* Implies exit() */

  a_name[0]='\0';
  tapfd = tap_alloc(a_name, IFF_TAP | IFF_NO_PI); 

  socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketfd < 0)
  {
    perror("ERROR opening socket");
    exit(1);
  }

  printf("Binding: IPv4\n");
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
      { tapfd, POLLIN }
    };

    if ( poll(fds,2,500) > 0 )
    {
      if (fds[0].revents & POLLIN) 
      {
        len = sizeof(rem_addr);
        len = recvfrom(socketfd, buf, BUFSIZE, 0, (struct sockaddr *)&rem_addr, &len);
        hdr_buf = (struct hdr *)buf;

        //buf = xorcypher(buf,len, argv[3]);
        hdr_buf = (struct hdr*)xorcypher((char*)hdr_buf,len, argv[3]);

        len = write(tapfd, hdr_buf->data, len-sizeof(struct hdr));
        fprintf(stdout, "Wrote %d bytes from network to tap\n", len);
        fprintf(stdout, "and got '%s' as text\n", hdr_buf->text);
      }
      if (fds[1].revents & POLLIN) 
      {
        len = read(tapfd, buf+sizeof(struct hdr), BUFSIZE);
        hdr_buf = (struct hdr *)buf;
        strcpy(hdr_buf->text,"Helloooo!!");

        //buf = xorcypher(buf,len,argv[3]);
        hdr_buf = (struct hdr*)xorcypher((char*)hdr_buf,len+sizeof(struct hdr),argv[3]);

        len = sendto(socketfd, hdr_buf, len+sizeof(struct hdr), 0, (struct sockaddr *)&rem_addr, sizeof(rem_addr));
        fprintf(stdout, "Wrote %d bytes from tap to network\n", len);
      }
    }
  }

  return 0;
}
