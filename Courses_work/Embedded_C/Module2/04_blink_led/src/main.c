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
#include <../inc/stm32f4xx.h>
#include <../inc/stm32f4xx_gpio.h>

static void delay(void);

/* main C entry point - should never return */
void main(void)
{
    /* Enable peripheral clocks */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    /* Configure pins */
    GPIOD->MODER |= GPIO_MODER_MODER15_0;
    GPIOD->OTYPER &= ~GPIO_OTYPER_OT_15;
    GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15;
    GPIOD->PUPDR &= ~GPIO_PUPDR_PUPDR15;
    
    GPIOD->MODER |= GPIO_MODER_MODER12_0;
    GPIOD->OTYPER &= ~GPIO_OTYPER_OT_12;
    GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12;
    GPIOD->PUPDR &= ~GPIO_PUPDR_PUPDR12;

    while (1)
    {
        static uint8_t led_val = 0;

        /* toggle the led */
        GPIOD->ODR = GPIO_Pin_15 | GPIO_Pin_12;
        /* wait a bit */
        delay();
    }
}

static void delay(void)
{
  int i;
  for(i=0;i<1000;i++)
  {
  
  }
}
