#include "4412_addr.h"
#include "macro.h"
#include "option.h"

#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <sys/stat.h>
#include <sys/types.h>

// runtime.c
extern void Delay(unsigned int v);

// test.c
extern void Print_Hello(void);
extern int _Sqr(int a);
extern long long _Long_Long_Add(long long a, long long b);

//uart.c
#define Uart_Printf		Uart1_Printf
extern void Uart1_Send_Byte(char data);
extern void Uart1_Send_String(const char *pt);
extern void Uart1_Printf(const char *fmt,...);
extern char Uart1_Get_Char(void);
extern char Uart1_Get_Pressed(void);
extern int Uart1_GetIntNum(void);
extern void Uart1_GetString(char *string);

// key.c
extern int Key_Get_Key_Pressed(void);

//graphics.c

#define BLACK	0x0000
#define WHITE	0xffff
#define BLUE	0x001f
#define GREEN	0x07e0
#define RED		0xf800
#define YELLOW	0xffe0
#define VIOLET	0xf81f

#define RIGHT_ALIGN 		512

#define TITLE_X_START 		20 + RIGHT_ALIGN
#define TITLE_Y_START 		10
#define TITLE_TEXT_SIZE 	1.5

#define BOX_TEXT_SIZE 		1

#define BOX1_TITLE_X_START 	20 + RIGHT_ALIGN
#define BOX1_TITLE_Y_START 	INIT_INPUTBOX_Y - 5

#define INIT_INPUTBOX_X 	10 + RIGHT_ALIGN
#define INIT_INPUTBOX_Y 	60
#define END_INPUTBOX_X 		INIT_INPUTBOX_X + SIZE_BOX_X
#define END_INPUTBOX_Y 		INIT_INPUTBOX_Y + SIZE_BOX_Y

#define BOX_ALIGN 	260
#define BOX2_TITLE_X_START 	BOX1_TITLE_X_START
#define BOX2_TITLE_Y_START 	BOX1_TITLE_Y_START + BOX_ALIGN

#define INIT_OUTPUTBOX_X 	INIT_INPUTBOX_X
#define INIT_OUTPUTBOX_Y 	INIT_INPUTBOX_Y + BOX_ALIGN
#define END_OUTPUTBOX_X 	END_INPUTBOX_X
#define END_OUTPUTBOX_Y 	END_INPUTBOX_Y + BOX_ALIGN

#define SIZE_BOX_X 			492
#define SIZE_BOX_Y 			200

#define LINE_SIZE 			2
#define INNER_TEXT_ALIGN 	30
#define INNER_TEXT_SIZE 	2

#define INPUT_X_START 	INIT_INPUTBOX_X + INNER_TEXT_ALIGN
#define INPUT_X_SIZE 	20
#define INPUT_Y_START 	INIT_INPUTBOX_Y + INNER_TEXT_ALIGN

#define OUTPUT_X_START 	INPUT_X_START
#define OUTPUT_Y_START 	INPUT_Y_START + BOX_ALIGN

typedef struct {
	unsigned int posx;
	unsigned int posy;
	unsigned int p_sizex;
	unsigned int p_sizey;
	unsigned int v_sizex;
	unsigned int v_sizey;
	unsigned int bytes_per_pixel;
	unsigned int bpp_mode;
}WIN_INFO_ST;

#define BPPMODE_1BPP				(0)
#define BPPMODE_2BPP				(1)
#define BPPMODE_4BPP				(2)
#define BPPMODE_8BPP_PAL			(3)
#define BPPMODE_8BPP_NOPAL			(4)
#define BPPMODE_16BPP_565			(5)
#define BPPMODE_16BPP_A555			(6)
#define BPPMODE_18BPP_666			(8)
#define BPPMODE_24BPP_888			(11)
#define BPPMODE_24BPP_A887			(12)
#define BPPMODE_25BPP_A888			(13)
#define BPPMODE_32BPP_A888			(13)
#define BPPMODE_13BPP_A444			(14)
#define BPPMODE_16BPP_A444			(14)
#define BPPMODE_15BPP_555			(15)

#define WIDTH		(1024)
#define HEIGHT		(600)

extern void	Lcd_Init(void);
extern void Lcd_Win_Init(int id,int en);
extern void Lcd_Put_Pixel(int x,int y, unsigned short color);
extern void * Lcd_Get_Pixel_Address(int x,int y);
extern unsigned int Lcd_Get_Pixel(int x,int y);
extern void Lcd_Clr_Screen(void);
extern void Lcd_Draw_Back_Color(int color);
extern void Lcd_Get_Info_BMP(int * x, int  * y, const unsigned short int *fp);
extern void Lcd_Draw_BMP(int x, int y, const unsigned short int *fp);
extern void Lcd_Select_Draw_Frame_Buffer(int win_id,int buf_num);
extern void Lcd_Select_Display_Frame_Buffer(int win_id,int buf_num);
extern void Lcd_Wait_Blank(void);
extern void Lcd_Draw_Image(int x, int y, const unsigned short int *fp, int width, int height);
extern void Lcd_Brightness_Control(int level);
extern void Lcd_Draw_BMP_File_24bpp(int x, int y, void *fp);
extern void Lcd_Draw_STACK(void);
extern void Lcd_Printf(int x, int y, int color, int bkcolor, int zx, int zy, char *fmt,...);
extern void Lcd_Draw_Bar(int x1, int y1, int x2, int y2, int color);
extern void Lcd_Draw_Line(int x1,int y1,int x2,int y2,int color);
extern void Lcd_Half_Clr_Screen(int appNum);
