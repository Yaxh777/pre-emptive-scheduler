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

