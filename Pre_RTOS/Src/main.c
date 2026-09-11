#include <stm32f4xx.h>
#include "rtos.h"
/*
 * All of these are example tasks
 *
 * One can easily add their own
 *
 */
#include "gpio.h"
#include "tim.h"
#include "usart.h"


volatile uint8_t UIE = 0;

void ld2_blink(){
	GPIOA_Config(5,GPIO_OUTPUT);
	TIM2_Config_1HZ();
	TIM2_Enable();

	while(1){
		if(TIM2->SR & (1<<0)){
			TIM2->SR = 0;
			UIE = 1;
			GPIOA->ODR ^= (1U<<5);
		}
	}
}
void send_hi(){
	USART2_Config();

	while(1){
		if(UIE){
			UIE = 0;
			USART_Send("Hello\r\n");
		}
	}
}
int main(){
	rtos_task_create(ld2_blink,"blink");
	rtos_task_create(send_hi,"hi");

	rtos_init();

	rtos_start();
}
