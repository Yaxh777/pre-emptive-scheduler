/*
 * Launch.S
 *
 *  Created on: Aug 19, 2026
 *      Author: yash
 */

.global Launch_Scheduler
.type Launch_Scheduler, %function

.global active_tcb 			/*Symbol present in task.c*/

Launch_Scheduler:

	CPSID I         		/*Disable Maskable Interrupts*/

	LDR R0, =active_tcb		/*Loading Address of active_tcb into R0*/

	LDR R1, [R0]			/*Loading Address stored in active_tcb(address of tcbs[0]) into R1*/

	LDR R4, [R1]			/*Loading Address of Value of Stack Pointer(in tbcs[0]) into R4*/

	MOV SP, R4				/*Moving the value of R4(Stack Pointer) into SP*/

							/*
							* Now since the stack pointer is loaded
							* We can restore the intial fake context
							*/

							/*
							* The stack frame is like this:
							*	XPSR
							*	PC
							*	LR
							*	R12
							*	R3
							*	R2
							*	R1
							*	R0
							*	R7
							*	R6
							*	R5
							*	R4
							*	R11
							*	R10
							*	R9
							*	R8        <-SP
							*/

	POP {R4-R7}			/*Popin' R8-R11*/
	MOV R8, R4
	MOV R9, R5
	MOV R10, R6
	MOV R11, R7

	POP {R4-R7}			/*Popin' R4-R7*/

	POP {R0-R3}			/*Popin' R0-R3*/

	POP {R4}			/*Popin' R12*/
	MOV R12, R4

	ADD SP, SP, #4		/*Skipin' LR*/

	POP {R4}			/*Popin' PC*/

	MOV LR, R4			/*Moving PC Pointer to LR*/

	ADD SP, SP, #4		/*Skipin' XPSR*/

	CPSIE I				/*Enable Maskable Interrupts*/

	BX LR				/*Branch to Thread*/
