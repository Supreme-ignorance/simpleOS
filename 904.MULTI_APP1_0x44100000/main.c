#include "Device_Driver.h"
#include "translator.h"


void Main(void)
{
	Uart_Printf(">>APP1 => UART Print, RO-BASE = 0x44100000 \n");

	for(;;)
	{
		Uart_Printf("���ϼ��� �����ϴ� ��ġ����Ŀ�� ����  ������ ������... \n");

		char input[101];
		char res[1001];

		initCharPointer(input);
		initCharPointer(res);

		Uart1_GetString(input);
		Uart_Printf("�Է� �� %s \n", input);
		Uart_Printf("�ڵ� �� %d \n", input[0]);
		translation(res, input, 0);
		Uart_Printf("���  %s \n", res);

		initCharPointer(input);
		initCharPointer(res);
	}
}
