#include <stm32f4xx.h>
#include "timer.h"
#include "task.h"

void task1();
void task2();

void(*tasks[NUM_TASK])()={task1,task2};

extern void Launch_Scheduler();
int main(){

	for(uint8_t i = 0;i<NUM_TASK;i++){
		init_tasks(i,tasks[i]);
	}

	Systick_Conf();

	Launch_Scheduler();
}
