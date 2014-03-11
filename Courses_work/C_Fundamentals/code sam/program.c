#include <stdio.h>
#include <stdlib.h>
#include "transport.h"
#include "spi_driver.h"

extern struct driver my_driver;

int main(int argc, char const *argv[])
{
	spi_write("TEST", 4);
	return 0;
}