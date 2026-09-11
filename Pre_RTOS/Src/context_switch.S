/*
 * context_switch.S
 *
 *  Created on: Aug 18, 2026
 *      Author: yash
 */


.global PendSV_Handler
.type PendSV_Handler,%function

.global active_tcb 				/*Symbol Present in task.c*/

PendSV_Handler:

	CPSID I						/*Disable Maskable Interrupt*/

	PUSH {R4-R7}				/*Pushing R4-R7*/

	MOV R4, R8
	MOV R5, R9
	MOV R6, R10
	MOV R7, R11

	PUSH {R4-R7}				/*Pushing R8-R11*/

	LDR R0, =active_tcb			/*Loading address of active_tcb in R0*/

	LDR R1, [R0]				/*Loading Address stored in active_tcb into R1*/

	MOV R4, SP					/*Moving Current SP value to R4*/

	STR R4, [R1]				/*Storing Current SP value stored in R4 to tcbs[i].sp*/


	LDR R1, [R1,#4]				/*Loading address of next TCB in R1*/

	STR R1, [R0]				/*Making the new TCB active one*/

	LDR R4, [R1]				/*Loading new SP value in R4*/

	MOV SP, R4					/*Moving new stack pointer value to SP*/

	POP {R4-R7}					/*Popin' R8-R11*/

	MOV R8, R4
	MOV R9, R5
	MOV R10, R6
	MOV R11, R7

	POP {R4-R7}					/*Popin' R4-R7*/

	CPSIE I						/*Enable Maskable Interrupts*/

	BX LR						/*EXC_RETURN*/
