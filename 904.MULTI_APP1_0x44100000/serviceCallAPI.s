	.include "4412addr.inc"
	.include "option.inc"

	.code	32
	.text



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@
@svc call api
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@
@Lcd_Clr_Screen 10
@Lcd_Draw_BMP 11
@Uart_Printf 21
@LED_Display 12
@Key_Get_Key_Pressed 30
@Key_Wait_Key_Released 31
@Key_Wait_Key_Pressed 32
@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@22


	.global Print_Hello
Print_Hello:

	svc 0
	bx lr


	.global _Sqr
_Sqr:

	svc 1
	bx lr


	.global _Long_Long_Add
_Long_Long_Add:

	svc 2
	bx lr


	.global Lcd_Clr_Screen
Lcd_Clr_Screen:

	svc 10
	bx lr


	.global Lcd_Draw_BMP
Lcd_Draw_BMP:

	svc 11
	bx lr

	.global Uart1_Printf
Uart1_Printf:

	svc 20
	bx lr

	.global Uart1_Send_Byte
Uart1_Send_Byte:

	svc 22
	bx lr

	.global Uart1_Get_Pressed
Uart1_Get_Pressed:

	svc 23
	bx lr

	.global LED_Display
LED_Display:

	svc 12
	bx lr

	.global Lcd_Printf
Lcd_Printf:

	svc 13
	bx lr

	.global Lcd_Draw_Bar
Lcd_Draw_Bar:

	svc 14
	bx lr


	.global Key_Get_Key_Pressed
Key_Get_Key_Pressed:

	svc 30
	bx lr

	.global Key_Wait_Key_Released
Key_Wait_Key_Released:

	svc 31
	bx lr

	.global Key_Wait_Key_Pressed
Key_Wait_Key_Pressed:

	svc 32
	bx lr
