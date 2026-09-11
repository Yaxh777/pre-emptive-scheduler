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
	Systick_Conf();       /*Initializing SysTick*/
	return RTOS_OK;
}

rtos_status_t rtos_start(){
	extern void Launch_Scheduler();			/*Symbol Present in launch.S*/
		Launch_Scheduler();					/*Creating cortex M exception frame*/
	return RTOS_OK;
}
rtos_status_t rtos_task_create(task_function_t function,const char *name){

	extern tcb_t tcbs[NUM_TASK];			/*Symbol Present in task.c*/

	for(uint8_t i = 0;i<NUM_TASK;i++){		/*Finding Unused TCB and Stack*/

		if(tcbs[i].state == TASK_UNUSED){

			task_init(i,name,function);

			return RTOS_OK;
		}
	}

	return RTOS_NO_FREE_TASK_SLOT;
}
