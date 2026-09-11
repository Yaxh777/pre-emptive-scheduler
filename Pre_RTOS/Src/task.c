/*
 * task.c
 *
 *  Created on: Aug 12, 2026
 *      Author: yash
 */

#include "task.h"
#include <stm32f4xx.h>


tcb_t tcbs[NUM_TASK];						/*Allocating TCBs*/

uint32_t tcb_stack[NUM_TASK][STACK_SIZE];	/*Allocating Stack*/

tcb_t *active_tcb = &tcbs[0];				/*Task0 will be the First active TCB*/

void task_init(uint8_t pid,const char *name,void(*task)()){

	__disable_irq();										/*Disable Maskable Interrupt*/

	if(pid == 0){											/*Establishing Linked List*/
		for(uint8_t i = 0; i< NUM_TASK;i++)
			tcbs[i].next_tcb = &tcbs[(i+1) % NUM_TASK];
}

	tcbs[pid].sp = &tcb_stack[pid][STACK_SIZE - 16];		/*Setting Up The Stack Pointer in the Task Stack*/

	tcb_stack[pid][STACK_SIZE - 1] = 0x01000000;			/*Setting Thumb Mode in XPSR*/

	tcb_stack[pid][STACK_SIZE - 2] = (uint32_t)task	;		/*Setting Program Counter*/

	tcbs[pid].task_name = name;

	tcbs[pid].state = TASK_READY;							/*Marking Task as Ready*/

	__enable_irq();											/*Enable Maskable Interrupt*/
}
