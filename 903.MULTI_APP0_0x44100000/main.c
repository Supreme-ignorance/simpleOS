#include "Device_Driver.h"

#include ".\images\planet_0.h"
#include ".\images\planet_1.h"
#include ".\images\planet_2.h"
#include ".\images\planet_3.h"
#include ".\images\planet_4.h"
#include ".\images\planet_5.h"
#include ".\images\planet_6.h"
#include ".\images\planet_7.h"
#include ".\images\planet_8.h"
#include ".\images\planet_9.h"
#include ".\images\planet_10.h"

//extern WIN_INFO_ST ArrWinInfo[5];

#define BLACK	0x0000
#define WHITE	0xffff
#define BLUE	0x001f
#define GREEN	0x07e0
#define RED		0xf800
#define YELLOW	0xffe0
#define VIOLET	0xf81f

#define DELAY	16000

const unsigned short * img[]={
		planet_0,
		planet_1,
		planet_2,
		planet_3,
		planet_4,
		planet_5,
		planet_6,
		planet_7,
		planet_8,
		planet_9,
		planet_10,
};

void Main(void)
{
	Uart_Printf(">>APP0 => LCD Display\n");
	int i = 0;

	for(;;)
	{
		for(i=0; i<11; i++)
		{
			Lcd_Clr_Screen();
			Lcd_Draw_BMP(0,0,img[i]);
			Delay(DELAY);
			Lcd_Clr_Screen();
		}
	}
}
