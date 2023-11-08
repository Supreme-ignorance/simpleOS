#include "Device_Driver.h"

#define DELAY	8000

void Main(void)
{
	Uart_Printf(">>APP1 => UART Print, RO-BASE = 0x44100000 \n");

//	int x0 = 1, x1 = 2, x2 = 3, x3 = 4, x4 = 5, x5 = 6;
//	long long y0 = 45630, y1 = 79274;

	int res0 = 0;
//	long long res1 = 0;

	for(;;)
	{
//		Uart_Printf("\n [DEBUG] STACK TEST %d %d %d %d %d %d %d %d %d %d \n", x0, x1, x2, x3, x4, x5, x0, x1, x2, x3);
//		Print_Hello();
		res0 = _Sqr(5);
		Uart_Printf("\n [DEBUG] return TEST %d \n", res0);
//		res1 = _Long_Long_Add(y0, y1);
//		Uart_Printf("\n [DEBUG] return TEST %lld \n", res1);
	}
}
