/*
 * context_switch.S
 *
 *  Created on: Aug 18, 2026
 *      Author: yash
 */


.global PendSV_Handler
.type PendSV_Handler,%function

.global active_tcb

PendSV_Handler:
	CPSID I

	PUSH {R4-R7}

	MOV R4, R8
	MOV R5, R9
	MOV R6, R10
	MOV R7, R11

	PUSH {R4-R7}

	LDR R0, =active_tcb

	LDR R1, [R0]

	MOV R4, SP

	STR R4, [R1]


	LDR R1, [R1,#4]

	STR R1, [R0]

	LDR R4, [R1]

	MOV SP, R4

	POP {R4-R7}

	MOV R8, R4
	MOV R9, R5
	MOV R10, R6
	MOV R11, R7

	POP {R4-R7}

	CPSIE I

	BX LR
