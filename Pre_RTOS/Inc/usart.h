/*
 * usart.h
 *
 *  Created on: 2 Aug 2026
 *      Author: yash
 */

#ifndef USART_H_
#define USART_H_

#include <stm32f4xx.h>

void USART2_Config();

void USART_Send(uint8_t*);

void USART_Manage_Request(uint8_t);

#endif /* USART_H_ */
