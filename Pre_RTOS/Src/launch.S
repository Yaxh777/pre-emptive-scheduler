/*
 * Launch.S
 *
 *  Created on: Aug 19, 2026
 *      Author: yash
 */

.global Launch_Scheduler
.type Launch_Scheduler, %function

.global active_tcb

Launch_Scheduler:

	CPSIE I

	LDR R0, =active_tcb

	LDR R1, [R0]

	LDR R4, [R1]

	MOV SP, R4

	POP {R4-R7}

	MOV R8, R4
	MOV R9, R5
	MOV R10, R6
	MOV R11, R7

	POP {R4-R7}

	POP {R0-R3}
	POP {R4}
	MOV R12, R4

	ADD SP, SP, #4

	POP {R4}

	MOV LR, R4

	ADD SP, SP, #4

	CPSIE I

	BX LR
