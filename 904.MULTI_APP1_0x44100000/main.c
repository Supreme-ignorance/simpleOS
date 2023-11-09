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

	Uart_Printf("���ϼ��� �����ϴ� ��ġ����Ŀ�� ����  ������ ������... \n");
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
