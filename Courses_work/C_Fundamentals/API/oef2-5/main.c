#include <stdio.h>
#include "transport.h"
#include "spi_driver.h"

extern struct spi_driver driver;

int main(int argc, char **argv)
{
  spi_write("TEST", 4);
  return 0;
}
