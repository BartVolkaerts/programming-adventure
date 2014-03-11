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

/* libopencm3 */
#include "libopencm3/stm32/f4/rcc.h"
#include "libopencm3/stm32/f4/gpio.h"

/* FreeRTOS */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* Defines */
#define EVER        (;;)

void vTest1Task(void *pvParameters);
void vLEDTask(void *pvParmeters);

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


/* main C entry point - should never return */
int main(void)
{
    uint32_t i=0;

    clock_setup();
    gpio_setup();

    xTaskCreate( vTest1Task, ( signed char * ) "Test1",
                    configMINIMAL_STACK_SIZE, ( void * ) NULL,
                    tskIDLE_PRIORITY, NULL );
    xTaskCreate( vLEDTask, ( signed char * ) "LED_Blink",
                    configMINIMAL_STACK_SIZE, ( void * ) NULL,
                    tskIDLE_PRIORITY+1, NULL );
		
    vTaskStartScheduler();

    for EVER
    {
        i++;
    }
}

void vTest1Task(void *pvParameters)
{
    uint32_t j = 0;
    void * param = pvParameters;
    for EVER
    {
        j++;
    }
}

void vLEDTask(void *pvParmeters)
{
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    for EVER
    {
        static uint8_t run_loop = 0;
        // Wait for the next cycle.
        vTaskDelayUntil(&xLastWakeTime, 250u); /* in ms */

        // Toggle LED
        switch (run_loop)
        {
            case 0:
                gpio_set(GPIOD, GPIO12);
                gpio_clear(GPIOD, GPIO13 | GPIO14 | GPIO15);
                run_loop++;
                break;
            case 1:
                gpio_set(GPIOD, GPIO13);
                gpio_clear(GPIOD, GPIO12 | GPIO14 | GPIO15);
                run_loop++;
                break;
            case 2:
                gpio_set(GPIOD, GPIO14);
                gpio_clear(GPIOD, GPIO12 | GPIO13 | GPIO15);
                run_loop++;
                break;
            case 3:
                gpio_set(GPIOD, GPIO15);
                gpio_clear(GPIOD, GPIO12 | GPIO13 | GPIO14);
                run_loop=0;
                break;
            default:
                run_loop=0;
        }
    }
}
