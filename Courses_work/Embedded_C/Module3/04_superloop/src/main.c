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
#include "stm32f4xx.h"
#include "main.h"

/* Defines */
#define EVER        (;;)

static int flag = 0;

/* Prototypes */
int main(void);

void TIM2_IRQHandler(void);
void INTTIM_Config(void);

/* main C entry point */
int main(void)
{
    int start = 0;
    int count = 0;
    int cpu_usage = 0;
    int max_cpu_usage = 0;
    int j;

    INTTIM_Config();

    for EVER
    {
      start = TIM2->CNT = 100;
      for(j=0; j<65565*8; j++)
        sin(0.443f);
      count = TIM2->CNT;
      cpu_usage = 100-count;
      while(!flag);
      flag = 0;
      if(cpu_usage>max_cpu_usage)
        max_cpu_usage = cpu_usage;
      cpu_usage = 0;
    }
}

void TIM2_IRQHandler(void)
{
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  flag = 1;
}

void INTTIM_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_TimeBaseStructure.TIM_Period = 100 - 1; 
  TIM_TimeBaseStructure.TIM_Prescaler = 42000 - 1; 
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM2, ENABLE);
}

