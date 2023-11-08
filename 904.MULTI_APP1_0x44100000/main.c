#include "Device_Driver.h"
#include "translator.h"


void Main(void)
{
	Uart_Printf(">>APP1 => UART Print, RO-BASE = 0x44100000 \n");

	for(;;)
	{
		Uart_Printf("은하수를 여행하는 히치하이커를 위한  번역기 가둥중... \n");

		char input[101];
		char res[1001];

		initCharPointer(input);
		initCharPointer(res);

		Uart1_GetString(input);
		Uart_Printf("입력 값 %s \n", input);
		Uart_Printf("코드 값 %d \n", input[0]);
		translation(res, input, 0);
		Uart_Printf("결과  %s \n", res);

		initCharPointer(input);
		initCharPointer(res);
	}
}
