/*
 * main.c
 *
 *  Created on: 14 Feb 2013
 *      Author: Maxime Vincent
 * Description: Framework to get a LED to blink
 *
 *     Purpose: Purpose is to demonstrate the configuration of a peripheral
 *              on the STM32F4 MCU
 *
 *     Context: Written in the context of the Embedded C course by TASS Belgium.
 */

/* Includes */
#include <stdint.h>
#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

static void delay(void);

/* main C entry point - should never return */
void main(void)
{
    /* Enable peripheral clocks */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    /* Configure pins */
    GPIOD->MODER &= ~GPIO_MODER_MODER13_1;
    GPIOD->MODER |= GPIO_MODER_MODER13_0;
    /* Speed mode configuration */
    GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13;
    /* Output mode configuration */
    GPIOD->OTYPER &= ~GPIO_OTYPER_OT_13;
    /* Pull-up Pull down resistor configuration*/
    GPIOD->PUPDR &= ~GPIO_PUPDR_PUPDR13;

    while (1)
    {
        static uint8_t led_val = 0;

        /* toggle the led */
        GPIOD->ODR = GPIO_Pin_13;

        /* wait a bit */
        delay();
    }
}

static void delay(void)
{

}
