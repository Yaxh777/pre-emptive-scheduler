/*
 * timer.c
 *
 *  Created on: Aug 18, 2026
 *      Author: yash
 */

#include "timer.h"

#define COUNTER_LOAD_VALUE 159999  /*Since SYSCLK is 16MHZ, so for 10ms delay*/
#define COUNTER_INIT_VALUE 0
#define SYSTICK_INT_EN (1U<<1)
#define COUNTER_EN (1U<<-0)
#define CLOCK_SOURCE (1U<<2)
#define PENDSV_INT_SET (1U<<28)

void Systick_Conf(){
	SysTick->LOAD = COUNTER_LOAD_VALUE;
	SysTick->VAL = COUNTER_INIT_VALUE;
	SysTick->CTRL = (COUNTER_EN | SYSTICK_INT_EN | CLOCK_SOURCE);
}

void SysTick_Handler(){
	SCB->ICSR = PENDSV_INT_SET;
}
