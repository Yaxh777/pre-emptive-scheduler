/*
 * tim.c
 *
 *  Created on: 2 Aug 2026
 *      Author: yash
 */

#include "tim.h"

#define TIM2_RCC_POS (1U << 0)
#define UIE_POS (1U << 0)
#define CEN_POS (1U << 0)

void TIM2_Config_1HZ(){
	RCC->APB1ENR |= TIM2_RCC_POS;
	TIM2->PSC = 1600 - 1;
	TIM2->ARR = 10000 - 1;
	TIM2->CNT = 0;
}

void TIM2_IRQ_EN(){
	TIM2->DIER |= UIE_POS;
	NVIC_EnableIRQ(TIM2_IRQn);
}
void TIM2_Enable(){
	TIM2->CR1 |= CEN_POS;
}

void TIM2_Disable(){
	TIM2->CR1 &= ~CEN_POS;
}
