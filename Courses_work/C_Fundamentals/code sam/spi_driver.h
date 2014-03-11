#ifndef spi_driver
#define spi_driver
#include "transport.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct driver {
	struct transport_layer *transport;
	uint16_t address;
	int size;
};

int spi_write(char *data, int length);
int spi_read(char *buffer, int length);


#endif
