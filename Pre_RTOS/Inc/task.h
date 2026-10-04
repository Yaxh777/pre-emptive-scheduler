/*
 * task.h
 *
 *  Created on: Aug 11, 2026
 *      Author: yash
 */

#ifndef TASK_H_
#define TASK_H_

#define NUM_TASK 2
#define TASK_NAME_MAX 10
#define STACK_SIZE 100

#include <stdint.h>

typedef enum {
	TASK_UNUSED = 0,
	TASK_READY,
	TASK_RUNNING
}task_state_t;

typedef struct tcb {
	uint32_t *sp;
	struct tcb *next_tcb;
	const char *task_name;
	task_state_t state;
}tcb_t;


void task_init(uint8_t pid,const char *,void(*task)());

#endif /* TASK_H_ */
