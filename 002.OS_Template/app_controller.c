#include "app_controller.h"
#include "app_service.h"
#include "device_driver.h"


int InitApp(void)
{
	int result = 0;

	result = initApp();
	Uart_Printf("\n [INFO] INIT APP \n");

	return result;
}

int ChangeApp(void)
{
	int result = 0;

	int nextAppNum = (getCurAppNum() + 1) % 2;
	setCurAppNum(nextAppNum);
	result = runApp(getCurAppNum());

	Uart_Printf("\n [INFO] RUN APP ==> APP%d, result : %s\n", getCurAppNum(), result == 1 ? "true":"false");

	return result;
}
