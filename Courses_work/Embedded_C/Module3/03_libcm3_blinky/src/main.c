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
#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/f4/gpio.h>

/* Set STM32 to 168 MHz. */
static void clock_setup(void)
{
    rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_168MHZ]);

    /* Enable GPIOD clock. */
    rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPDEN);
}

static void gpio_setup(void)
{
    /* Set GPIO12-15 (in GPIO port D) to 'output push-pull'. */
    gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT,
            GPIO_PUPD_NONE, GPIO12 | GPIO13 | GPIO14 | GPIO15);
}

int main(void)
{
    int i;

    clock_setup();
    gpio_setup();

    /* Set two LEDs for wigwag effect when toggling. */
    gpio_set(GPIOD, GPIO12 | GPIO14);

    /* Blink the LEDs (PD12, PD13, PD14 and PD15) on the board. */
    while (1) {
        /* Toggle LEDs. */
        gpio_toggle(GPIOD, GPIO12 | GPIO13 | GPIO14 | GPIO15);
        for (i = 0; i < 6000000; i++) /* Wait a bit. */
            __asm__("nop");
    }

    return 0;
}
