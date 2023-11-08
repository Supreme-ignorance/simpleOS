#include "Device_Driver.h"
#include "translator.h"
#include "view.h"


void Main(void)
{
	Uart_Printf(">>APP1 => UART Print, RO-BASE = 0x44100000 \n");

	char input[101];
	char res[1001];

	Uart_Printf("���ϼ��� �����ϴ� ��ġ����Ŀ�� ����  ������ ������... \n");

	for(;;)
	{

		initCharPointer(input);
		initCharPointer(res);
		initView();

		Uart1_GetString(input);
		translation(res, input, 0);
		printOutPut(res);

		while(Uart1_Get_Pressed() != ':');
	}
}
