#include <stdio.h>
#include "transport.h"
#include <assert.h>

struct transport_layer transport = {
	&write,
	&read,
};

int write(char *data, int length) {
	assert(data);
	assert(length > 0);
	printf("Data to write received at transport layer:\n");
	for(int i=0; i<length; i++) {
		printf("0x%X ", data[i]);
	}
	printf("\n");
	return 0;
}

int read(char *buffer, int length) {
	assert(buffer);
	char tmp[length+1];
	printf("Enter some input: ");
	fgets(buffer, length, stdin);
	memcpy(buffer, tmp, length);
	return 0;
}