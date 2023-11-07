#include "Device_Driver.h"

#include ".\images\image0.h"
#include ".\images\img101.h"

//extern WIN_INFO_ST ArrWinInfo[5];

#define BLACK	0x0000
#define WHITE	0xffff
#define BLUE	0x001f
#define GREEN	0x07e0
#define RED		0xf800
#define YELLOW	0xffe0
#define VIOLET	0xf81f

#define DELAY	3000

const unsigned short * img[]={image0, img101};

void Main(void)
{
	Uart_Printf(">>APP0 => LCD Display\n");

	int x0 = 1, x1 = 2, x2 = 3, x3 = 4, x4 = 5, x5 = 6;
	long long y0 = 45630, y1 = 79274;

	int res0 = 0;
	long long res1 = 0;

	for(;;)
	{
		Lcd_Draw_BMP(0,0,img[0]);
		Delay(DELAY);
		Lcd_Clr_Screen();

		Lcd_Draw_BMP(0,0,img[1]);
		Delay(DELAY);
		Lcd_Clr_Screen();

		Uart_Printf("\n [DEBUG] STACK TEST %d %d %d %d %d %d %d %d %d %d \n", x0, x1, x2, x3, x4, x5, x0, x1, x2, x3);
		Print_Hello();
		res0 = _Sqr(x5);
		Uart_Printf("\n [DEBUG] return TEST %d \n", res0);
		res1 = _Long_Long_Add(y0, y1);
		Uart_Printf("\n [DEBUG] return TEST %lld \n", res1);
	}
}
