/*
 * main.c
 *
 *  Created on: 14 Feb 2013
 *      Author: Maxime Vincent
 * Description: Virtually the most simple demo that can be run on an ARM MCU.
 *              The target is barely running - all clocks are off, the core is
 *              just executing a few simple instructions.
 *
 *     Purpose: Purpose is to demonstrate an openocd-gdb setup to flash and 
 *              step through code on the target.
 *
 *     Context: Written in the context of the Embedded C course by TASS Belgium.
 */

/* Includes */
#include "main.h"
#include <stdio.h>

/* Defines */
#define EVER        (;;)

extern void  initialise_monitor_handles(void);

/* main C entry point - should never return */
int main(void)
{
    char test[100];
    int i=0;

    initialise_monitor_handles();    /* Needed for newlib SemiHosting */

    sprintf(test, "Welcome to Embedded C\n");
    printf("%s", test);

    for EVER
    {
        i++;
        printf("count = %d       \r", i);
    }
}

