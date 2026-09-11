/*
 * usart.c
 *
 *  Created on: 2 Aug 2026
 *      Author: yash
 */

#include "usart.h"
#include "gpio.h"
#include "tim.h"

#define USART2_RCC_POS (1U<<17)
#define BAUD_RATE 115200
#define APB1_CLK 16000000
#define BRR_VALUE ((APB1_CLK + (BAUD_RATE/2)) / BAUD_RATE)
#define USART_TE (1U << 3)
#define USART_RE (1U << 2)
#define USART_EN (1U << 13)
#define RXNEIE (1U << 5)
#define TXE (1U << 7)

void USART2_Config(){
	RCC->APB1ENR |= USART2_RCC_POS;

	GPIOA_Config(2,GPIO_AF);
	GPIOA_Config(3,GPIO_AF);

	GPIOA->AFR[0] &= ~(0b1111 << 8);
	GPIOA->AFR[0] |= (0b111 << 8);

	GPIOA->AFR[0] &= ~(0b1111 << 12);
	GPIOA->AFR[0] |= (0b111 << 12);

	USART2->BRR = BRR_VALUE;
	USART2->CR1 |= (USART_TE | USART_RE);

	USART2->CR1 |= USART_EN;
}

void USART_Send(uint8_t *data){
	for(uint16_t i = 0;data[i] != '\0';i++){
		while(!(USART2->SR & TXE));
		USART2->DR = data[i];
	}
}

void USART_Manage_Request(uint8_t rq){
	switch(rq){
	case '1':
		TIM2_Enable();
		USART_Send("LD2 is Blinking like a true g\n\r");
		break;
	case '2':
		USART_Send("Hello\n\r");
		break;
	case '3':
		TIM2_Disable();
		USART_Send("LD2 stoped like everything and everyone will one day\n\r");
		break;
	default:
		USART_Send("Can't you read?? faggot!!\n\r");
		break;
	}
}
