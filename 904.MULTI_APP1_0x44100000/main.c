#include "Device_Driver.h"
#include "translator.h"
#include "view.h"


void Main(void)
{
	Uart_Printf(">>APP1 => UART Print, RO-BASE = 0x44100000 \n");

	char input[101];
	char res[1001];
	int* curPlanet = (int*) 0x44b10000;
	int postPlanet = -1;

	Uart_Printf("은하수를 여행하는 히치하이커를 위한  번역기 가둥중... \n");
	initView();

	for(;;)
	{
		initCharPointer(input);
		initCharPointer(res);
		clearView();

		Uart1_GetString(input);
		postPlanet = *curPlanet;
		translation(res, input, *curPlanet);
		printOutPut(res);

		while(Uart1_Get_Pressed() != ':')
		{
			if (postPlanet != *curPlanet)
			{
				reTranslationView();
				initCharPointer(res);
				postPlanet = *curPlanet;
				translation(res, input, *curPlanet);
				printOutPut(res);
			}
		}
	}
}
