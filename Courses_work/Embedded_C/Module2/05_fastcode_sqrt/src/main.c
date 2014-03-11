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
#include <../inc/stm32f4xx.h>
#include <../inc/stm32f4xx_gpio.h>

/* Defines */
#define EVER        (;;)

void fast_increment(uint32_t * i);
uint32_t isqrt3(uint32_t n);

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

    uint32_t i=0;
    uint32_t result;
    float wortel = 0.0f;
    int flag = 0;
    int j;

    for EVER
    {
        i++;
        fast_increment(&i);
        result = isqrt3(308025);
        for(j = 0; j < 500000; j++)
          wortel = sinf(0.523534);

        flag = ~flag;
        if(flag)
          GPIOD->ODR = GPIO_Pin_15;
        else
          GPIOD->ODR = GPIO_Pin_12;
    }
}

__attribute__ ((section (".fastcode"))) 
void fast_increment(uint32_t * i)
{
    (*i)++;
}

__attribute__ ((section (".fastcode"))) 
uint32_t isqrt3(uint32_t n)
{
   uint32_t root = 0, bit, trial;
   bit = (n >= 0x10000) ? 1<<30 : 1<<14; /* 16bit or 32 bit? */
   do
   {
      trial = root+bit;
      if (n >= trial)
      {
         n -= trial;
         root = trial+bit;
      }
      root >>= 1;
      bit >>= 2;
   } while (bit);
   return root;
}
