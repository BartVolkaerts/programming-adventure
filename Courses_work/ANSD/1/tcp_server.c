#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <netdb.h>
#include <string.h>

#define SERVER_PORT 7412
//#define SERVER_PORT 80

struct __attribute__((__packed__)) sensor_t
{
	uint32_t type: 8,
			node_id: 24;
	uint16_t num_sensors;
	uint16_t msg_len;
};

int main(int argc, char **argv)
{
	int s, ret;
	char *hostname;
	struct sockaddr_in server = { 0 };
	struct sockaddr_in *res = NULL;
	struct addrinfo *ai, *orig;

	char text_buf[40];
	if(argc < 2)
	{
		printf("I need one argument\n");
		exit(1);
	}
	hostname = argv[1];
	printf("Hostname: %s\n", hostname);
	s = socket(AF_INET, SOCK_STREAM, 0);

	if(s < 0)
	{
		printf("Failed opening socket\n");
		exit(1);
	}

	server.sin_port = htons(SERVER_PORT);
	ret = getaddrinfo(hostname, NULL, NULL, &ai);

	if(ret != 0)
	{
		printf("Failed getting addr info\n");
		exit(1);
	}

	orig = ai;
	while(ai)
	{
		if(ai->ai_family == AF_INET || ai->ai_family == AF_INET6)
		{
			res = (struct sockaddr_in *) ai->ai_addr;
			break;
		}
		ai = ai->ai_next;
	}

	if(!res)
	{
		printf("Address wasn't found\n");
		exit(1);
	}

	server.sin_addr.s_addr = res->sin_addr.s_addr;
	server.sin_family = res->sin_family;

	freeaddrinfo(orig);

	inet_ntop(server.sin_family, (const void *)&server.sin_addr.s_addr, text_buf, 40);

	printf("Ip is: %s\n", text_buf);

	ret = connect(s, (struct sockaddr *) &server, sizeof(server));
	if(ret != 0)
	{
		printf("Failed to connect\n");
		exit(1);
	}

	while(1)
	{
		struct sensor_t sensor;
		char my_buf[100];
		int i, total_len, str_len;
		sensor.type = 0xAA;
		sensor.node_id = htonl(0xDEADBE);
		sensor.num_sensors = htons(3);
		str_len = strlen("Hello");
		sensor.msg_len = htons(str_len);
		memcpy(my_buf, &sensor, sizeof(sensor));
		total_len = sizeof(sensor);

		for(i = 0; i < 3; i++)
		{
			uint32_t my_val = 1234, net_val;
			net_val = htonl(my_val);
			memcpy(&my_buf[total_len], &net_val, 4);
			total_len += 4;
		}

		strncpy(&my_buf[total_len], "Hello", str_len);
		total_len += str_len;

		ret = write(s, my_buf, total_len);
		if(ret < 0)
		{
			printf("Failed to write data\n");
			exit(1);
		}
		printf("Sent %d bytes\n", total_len);
		sleep(1);
	}
}
