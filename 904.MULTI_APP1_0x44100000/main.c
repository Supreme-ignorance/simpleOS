#include "Device_Driver.h"
#include "translator.h"
#include "view.h"


void Main(void)
{
	Uart_Printf(">>APP1 => UART Print, RO-BASE = 0x44100000 \n");

	char input[101];
	char res[1001];
	int* curPlanet = (int*) 0x44b10000;

	Uart_Printf("은하수를 여행하는 히치하이커를 위한  번역기 가둥중... \n");

	for(;;)
	{

		initCharPointer(input);
		initCharPointer(res);
		initView();

		Uart1_GetString(input);
		translation(res, input, *curPlanet);
		printOutPut(res);

		while(Uart1_Get_Pressed() != ':');
	}
}
