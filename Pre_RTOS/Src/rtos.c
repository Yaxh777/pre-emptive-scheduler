/*
 * rtos.c
 *
 *  Created on: Sep 10, 2026
 *      Author: yash
 */

#include "rtos.h"
#include "task.h"
#include "systick.h"

rtos_status_t rtos_init(){
	return RTOS_OK;
}

rtos_status_t rtos_start(){
	Systick_Conf();
	extern void Launch_Scheduler();
		Launch_Scheduler();
	return RTOS_OK;
}
rtos_status_t rtos_task_create(task_function_t function,const char *name){

	extern tcb_t tcbs[NUM_TASK];

	for(uint8_t i = 0;i<NUM_TASK;i++){

		if(tcbs[i].state == TASK_UNUSED){

			task_init(i,name,function);

			return RTOS_OK;
		}
	}

	return RTOS_NO_FREE_TASK_SLOT;
}
