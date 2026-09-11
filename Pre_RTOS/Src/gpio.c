/*
 * gpio.c
 *
 *  Created on: 2 Aug 2026
 *      Author: yash
 */

#include "gpio.h"

#define GPIOA_RCC_POS (1U<<0)
#define SET_BOTH_BITS (0b11U << (pin_no * 2))

void GPIOA_Config(uint8_t pin_no,GPIO_Mode mode){

		RCC->AHB1ENR |= GPIOA_RCC_POS;

	switch (mode) {
		case GPIO_INPUT:
			GPIOA->MODER &= ~SET_BOTH_BITS;
			break;
		case GPIO_OUTPUT:
			GPIOA->MODER &= ~SET_BOTH_BITS;
			GPIOA->MODER |= (1U << (pin_no * 2));
			break;
		case GPIO_AF:
			GPIOA->MODER &= ~SET_BOTH_BITS;
			GPIOA->MODER |= (0b10U << (pin_no * 2));
			break;
		case GPIO_ANALOG:
			GPIOA->MODER &= ~SET_BOTH_BITS;
			GPIOA->MODER |= (0b11U << (pin_no * 2));
			break;
		default:
			return;
			break;
	}
}

