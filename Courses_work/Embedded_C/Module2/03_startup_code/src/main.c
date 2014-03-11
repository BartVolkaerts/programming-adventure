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

/* Defines */
#define EVER        (;;)

static uint32_t hallo_ik_ben_static = 0x1337;
uint32_t hallo_ik_ben_niet_static = 0x1338;

/* main C entry point - should never return */
void main(void)
{
    int i=0;

    for EVER
    {
        i++;
    }
}

