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
#include <stdint.h>
#include <stdio.h>

/* Defines */
#define EVER        (;;)

/* main C entry point - should never return */
int main(void)
{
    uint8_t test[100];
    uint32_t i=0;

    sprintf((char*)&test, "Welcome to Embedded C\n");

    for EVER
    {
        i++;
    }
}

