/*
 * rtos.h
 *
 *  Created on: Sep 10, 2026
 *      Author: yash
 */

#ifndef RTOS_H_
#define RTOS_H_

typedef void (*task_function_t)(void);

typedef enum {
	RTOS_OK,
	RTOS_INVALID_FUNCTION,
	RTOS_NO_FREE_TASK_SLOT,
	RTOS_INIT_FAILED,
	RTOS_START_ERROR
}rtos_status_t;

rtos_status_t rtos_task_create(task_function_t function,const char *name);

rtos_status_t rtos_init(void);

rtos_status_t rtos_start(void);

#endif /* RTOS_H_ */
