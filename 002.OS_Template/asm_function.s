	.include "4412addr.inc"
	.include "option.inc"

	.code	32
	.text

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ UTILITY FUNCTIONS
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global Init_App
Init_App:

	push	{r4-r10, lr}

@@@@@ init
	ldr 	r3, =1
	ldr		r4, =PCB_BASE_APP0
	ldr 	r5, =20
1:
	subs	r5, r5, #1
	str		r3, [r4], #4
	bgt 	1b

	ldr		r4, =PCB_BASE_APP1
	ldr 	r5, =20
2:
	subs	r5, r5, #1
	str		r3, [r4], #4
	bgt 	2b
@@@@@

	ldr		r4, =PCB_BASE_APP0
	add		r4, r4, #0x34
	add		r5, r4, #0x08
	add 	r8, r5, #0x04

	ldr		r6, =PCB_BASE_APP1
	add		r6, r6, #0x34
	add		r7, r6, #0x08
	add 	r9, r7, #0x04

	ldr 	r3, =0x2000015f

	str		r1,	[r4]
	str		r0,	[r5]
	str		r2,	[r6]
	str		r0,	[r7]
	str		r3,	[r8]
	str		r3,	[r9]

	@@@@@@
@	push 	{r0-r3, ip, lr}
@	bl		checkRegister
@	pop 	{r0-r3, ip, lr}
	@@@@@@

	pop		{r4-r10, pc}

	.global Run_App0
Run_App0:

	@ APP0 RUN
	push	{r4, lr}

	mrs		r4, cpsr
	cps		#0x1f
	mov 	sp, r1
	blx		r0

	msr		cpsr_cxsf, r4

	pop		{r4, pc}

	.extern curAppNum
	.extern checkRegister
	.extern Timer0_ISR

	.global Backup_Context_Timer
Backup_Context_Timer:

	push	{lr}

	ldr 	r14, =curAppNum
	ldr 	r14, [r14]

	cmp 	r14, #1
	ldreq 	r14, =PCB_BASE_APP1
	cmp 	r14, #0
	ldreq 	r14, =PCB_BASE_APP0

	@@@@@@ backup
	stmia 	r14, {r0-r14}^
	add 	r14, #60
	mov 	r0, r14
	pop 	{lr}
	sub 	lr, lr, #4
	str 	lr, [r0]
	mrs 	r1, spsr
	str 	r1, [r0, #4]
	@@@@@@

	@@@@@@
@	push 	{r0-r3, ip, lr}
@	bl		checkRegister
@	pop 	{r0-r3, ip, lr}
	@@@@@@

	push 	{r0-r3, r12, lr}
	bl 		Timer0_ISR
	pop		{r0-r3, r12, lr}

	b 		Load_Context

	.global Backup_Context_Key
Backup_Context_Key:

	push	{lr}

	ldr 	r14, =curAppNum
	ldr 	r14, [r14]

	cmp 	r14, #1
	ldreq 	r14, =PCB_BASE_APP1
	cmp 	r14, #0
	ldreq 	r14, =PCB_BASE_APP0

	@@@@@@ backup
	stmia 	r14, {r0-r14}^
	add 	r14, #60
	mov 	r0, r14
	pop 	{lr}
	sub 	lr, lr, #4
	str 	lr, [r0]
	mrs 	r1, spsr
	str 	r1, [r0, #4]
	@@@@@@

	@@@@@@
@	push 	{r0-r3, ip, lr}
@	bl		checkRegister
@	pop 	{r0-r3, ip, lr}
	@@@@@@

	push 	{r0-r3, r12, lr}
	bl 		Switch_APP_ISR
	pop		{r0-r3, r12, lr}

	b 		Load_Context

	.global Load_Context

Load_Context:

	ldr 	r14, =curAppNum
	ldr 	r14, [r14]

	cmp 	r14, #1
	ldreq 	r14, =PCB_BASE_APP1
	cmp 	r14, #0
	ldreq 	r14, =PCB_BASE_APP0

	@@@@@ cpsr call
	ldr 	r0, [r14, #64]
	msr 	spsr, r0
	@@@@@

	@@@@@@ Load
	push 	{r14}
	ldmia 	r14, {r0-r14}^
	ldr 	r14, [r14, #60]

	movs 	pc, r14
	@@@@@@

	.global Get_User_SP
Get_User_SP:

	mrs		r1, cpsr
	cps		#0x1f
	mov 	r0, sp
	msr		cpsr_cxsf, r1
	bx 		lr

	.global Get_User_Stack_Base
Get_User_Stack_Base:

	ldr		r0, =SYS_STACK_BASE
	bx 		lr

	.global Get_User_Stack_Limit
Get_User_Stack_Limit:

	ldr		r0, =STACK_LIMIT
	bx 		lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ unsigned int PABT_Falut_Status(void)
@ 명령어 Fault 발생 이유를 리턴
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global  PABT_Falut_Status
PABT_Falut_Status:

	mrc		p15, 0, r0, c5, c0, 1
	bx 		lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ unsigned int PABT_Falut_Address(void)
@ 데이터 Fault 발생 주소를 리턴
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global  PABT_Falut_Address
PABT_Falut_Address:

	mrc		p15, 0, r0, c6, c0, 2
	bx 		lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ unsigned int DABT_Falut_Status(void)
@ 데이터 Fault 발생 이유를 리턴
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global  DABT_Falut_Status
DABT_Falut_Status:

	mrc		p15, 0, r0, c5, c0, 0
	bx 		lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ unsigned int DABT_Falut_Address(void)
@ 데이터 Fault 발생 주소를 리턴
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global  DABT_Falut_Address
DABT_Falut_Address:

	mrc		p15, 0, r0, c6, c0, 0
	bx 		lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ unsigned int Get_SP(void)
@ 현재 모드의 스택 포인터 값을 리턴
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global Get_SP
Get_SP:

	mov 	r0, sp
	bx 		lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ unsigned int Main_ID(void)
@ Core의 버전 값을 리턴
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global Main_ID
Main_ID:

	mrc 	p15, 0, r0, c0, c0, 0
	bx 		lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ unsigned int TLB_Type(void)
@ TLB Type 값을 리턴
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global TLB_Type
TLB_Type:

	mrc 	p15, 0, r0, c0, c0, 3
	bx 		lr

	.end
