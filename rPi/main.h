/********************************************************************
 * Header file for the automatic rolling shutter
 *
 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bcm2835.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PIN_UP RPI_GPIO_P1_07
#define PIN_STOP RPI_GPIO_P1_13
#define PIN_DOWN RPI_GPIO_P1_22

