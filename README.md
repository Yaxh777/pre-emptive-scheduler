# preemptive-scheduler

# A preemptive round robin scheduler for the STM32F4 with CMSIS support 

This Scheduler uses the PendSV exception to switch the context triggered by the systick interrupt

# Configurations

User can change the number of tasks according to their need by Changing the NUM_TASK macro
in inc/task.h

# Boilerplate and API
Necessary Headers :
```
#include <stm32f4xx.h>
#include "rtos.h"
```
RTOS API is exposed by:

```
#include "rtos.h"
```


To create a new task:

```
rtos_status_t rtos_task_create(task_function_t function,const char *name);
```

To Initialise the clock (Systick):

```
rtos_status_t rtos_init(void);
```
By default the time quantum is 10ms

User can configure it in src/systick.c

To start the Scheduler:

```
rtos_status_t rtos_start(void);
```

# Example
The default working of src/main.c

```
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
```





https://github.com/user-attachments/assets/7a6a6971-6be3-4322-b0fb-758d9e6ad396

