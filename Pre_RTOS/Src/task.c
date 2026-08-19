/*
 * task.c
 *
 *  Created on: Aug 12, 2026
 *      Author: yash
 */

#include "task.h"
#include <stm32f4xx.h>


tcb_t tcbs[NUM_TASK];

uint32_t tcb_stack[NUM_TASK][STACK_SIZE];

tcb_t *active_tcb = &tcbs[0];

void init_tasks(uint8_t pid,void(*task)()){

	__disable_irq();

	if(pid == 0){
		for(uint8_t i = 0; i< NUM_TASK;i++)
			tcbs[i].next_tcb = &tcbs[(i+1) % NUM_TASK];
}

	tcbs[pid].sp = &tcb_stack[pid][STACK_SIZE - 16];

	tcb_stack[pid][STACK_SIZE - 1] = 0x01000000;

	tcb_stack[pid][STACK_SIZE - 2] = (uint32_t)task;

	__enable_irq();
}
