/*
 * tim.h
 *
 *  Created on: 2 Aug 2026
 *      Author: yash
 */

#ifndef TIM_H_
#define TIM_H_

#include <stm32f4xx.h>

void TIM2_Config_1HZ();

void TIM2_IRQ_EN();

void TIM2_Enable();

void TIM2_Disable();

#endif /* TIM_H_ */
