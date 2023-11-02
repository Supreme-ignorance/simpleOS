#include "device_driver.h"


void checkRegister(void){
	unsigned int * app0 = 0x44B00000;
	unsigned int * app1 = 0x44B00200;

	int i;
	for(i=0;i<18;i++){
		Uart_Printf("\n app0 r%d : %x, app1 r%d : %x \n", i, app0[i], i, app1[i]);
	}
}
