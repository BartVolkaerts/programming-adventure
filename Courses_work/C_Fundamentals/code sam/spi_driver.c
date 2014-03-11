#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spi_driver.h"

extern struct transport_layer transport;

static const uint8_t WRITE = 0x44;
static const uint8_t READ = 0x33;

struct driver my_driver = { &transport, 0x1122, 1024};


int spi_write(char *data, int length) {
	int newLength = length + sizeof(my_driver.address) + sizeof(WRITE);
	printf("newLength = %i", sizeof(WRITE));
	uint8_t *buffer = malloc(newLength);
	buffer[0] = WRITE;
	buffer[1] = (my_driver.address >> 8) & 0xFF;
	buffer[2] = (my_driver.address) & 0xFF;
	memcpy(&buffer[3], data, length);

	my_driver.transport->write(buffer, newLength);
	
	free(buffer);
	return 0;
}

int spi_read(char *buffer, int length) {
	//TODO!
	my_driver.transport->read(buffer, length);
	return 0;
}

