#include "device_driver.h"


void checkRegister(void)
{
	unsigned int * app0 = (unsigned int *) 0x44B00000;
	unsigned int * app1 = (unsigned int *) 0x44B00200;

	int i;
	for(i=0;i<17;i++){
		Uart_Printf("\n app0 r%d : 0x%x,\t app1 r%d : 0x%x \n", i, app0[i], i, app1[i]);
	}
	Uart_Printf("\n------------------------------\n");
}

void checkR0(unsigned int r0)
{
	Uart_Printf("\n current r0 : 0x%x \n", r0);
}
