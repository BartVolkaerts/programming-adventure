#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include "transport.h"

struct typedef spi_driver {
  Transport *transport;
  uint16_t address; 
  int size;
} spi_driver;

int spi_write(char *data, int length);

#endif
