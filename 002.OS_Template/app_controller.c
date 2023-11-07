
#include "app_controller.h"
#include "device_driver.h"


int initializeApp(void)
{
	int result = 0;

	result = initApp();
	Uart_Printf("\n [INFO] INIT APP done \n");

	return result;
}

int switchAppASIDTTBR()
{
	int result = 0;

	int nextAppNum = (getCurAppNum() + 1) % 2;
	setCurAppNum(nextAppNum);
	result = setApp(getCurAppNum());
//	Uart_Printf("\n [INFO] switch APP done \n");

	return result;
}
