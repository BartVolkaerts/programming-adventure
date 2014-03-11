/*
 * main.c
 *
 *  Created on: 14 Feb 2013
 *      Author: Maxime Vincent
 * Description: A list of exception handlers for ARM MCUs.
 *
 *     Purpose: Purpose is to demonstrate an openocd-gdb setup to flash and 
 *              step through code on the target.
 *
 *     Context: Written in the context of the Embedded C course by TASS Belgium.
 */

/* Includes ------------------------------------------------------------------*/
#include "exceptions.h"

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

void NMI_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void HardFault_Handler(uint32_t * hardfault_args)
{
    unsigned int stacked_r0;
    unsigned int stacked_r1;
    unsigned int stacked_r2;
    unsigned int stacked_r3;
    unsigned int stacked_r12;
    unsigned int stacked_lr;
    unsigned int stacked_pc;
    unsigned int stacked_psr;
    unsigned int rBFAR; /* is also MMAR */
    unsigned int rCFSR;
    unsigned int rHFSR;
    unsigned int rDFSR;
    unsigned int rAFSR;

    stacked_r0 = ((unsigned long) hardfault_args[0]);
    stacked_r1 = ((unsigned long) hardfault_args[1]);
    stacked_r2 = ((unsigned long) hardfault_args[2]);
    stacked_r3 = ((unsigned long) hardfault_args[3]);

    stacked_r12 = ((unsigned long) hardfault_args[4]);
    stacked_lr = ((unsigned long) hardfault_args[5]);
    stacked_pc = ((unsigned long) hardfault_args[6]);
    stacked_psr = ((unsigned long) hardfault_args[7]);

    rBFAR = (*((volatile unsigned long *)(0xE000ED38)));
    rCFSR = (*((volatile unsigned long *)(0xE000ED28)));
    rHFSR = (*((volatile unsigned long *)(0xE000ED2C)));
    rDFSR = (*((volatile unsigned long *)(0xE000ED30)));
    rAFSR = (*((volatile unsigned long *)(0xE000ED3C)));

/*
    printf ("[Hard fault handler]\n");
    printf ("R0 = %x\n", stacked_r0);
    printf ("R1 = %x\n", stacked_r1);
    printf ("R2 = %x\n", stacked_r2);
    printf ("R3 = %x\n", stacked_r3);
    printf ("R12 = %x\n", stacked_r12);
    printf ("LR = %x\n", stacked_lr);
    printf ("PC = %x\n", stacked_pc);
    printf ("PSR = %x\n", stacked_psr);
    printf ("BFAR = %x\n", rBFAR);
    printf ("CFSR = %x\n", rCFSR);
    printf ("HFSR = %x\n", rHFSR);
    printf ("DFSR = %x\n", rDFSR);
    printf ("AFSR = %x\n", rAFSR);
*/

  //__ASM volatile("BKPT #01");

  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/* SVCall exception handler */
void SVC_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

void DebugMon_Handler(void)
{
}

/* PendSVC exception handler */
void PendSV_Handler(void)
{
}

/* SysTick Handler */
void SysTick_Handler(void)
{
  __stm32_tick++;
}

