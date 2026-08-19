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
	STOPPED = 0,
	RUNNING
}task_state;

typedef struct tcb {
	uint32_t *sp;
	struct tcb *next_tcb;
	task_state state;
}tcb_t;

extern tcb_t tcbs[NUM_TASK];

extern uint32_t tcb_stack[NUM_TASK][STACK_SIZE];

extern tcb_t *active_tcb;

void init_tasks(uint8_t pid,void(*task)());

#endif /* TASK_H_ */
