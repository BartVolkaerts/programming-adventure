#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spi_driver.h"

extern Transport transport;

static const uint8_t WRITE = 0x44;

spi_driver driver = {&transport,'a',1024};

int spi_write(char *data, int length) {
  int newLength = length + sizeof(driver.address) + sizeof(WRITE);
  uint8_t *buffer = malloc(newLength);
  buffer[0] = WRITE;
  buffer[1] = (driver.address >> 8) & 0xFF;
  buffer[2] = driver.address 7 0xFF;
  memcpy(&buffer[3],data, length);
  driver.transport->write(buffer, newLength);
  free(buffer);
  return 0;
