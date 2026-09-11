/*
 * gpio.h
 *
 *  Created on: Aug 20, 2026
 *      Author: yash
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stm32f4xx.h>

typedef enum{
	GPIO_INPUT,
	GPIO_OUTPUT,
	GPIO_AF,
	GPIO_ANALOG
}GPIO_Mode;

void GPIOA_Config(uint8_t,GPIO_Mode);


#endif /* GPIO_H_ */
