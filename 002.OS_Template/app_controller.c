#include "app_controller.h"
#include "app_service.h"
#include "device_driver.h"


int initializeApp(void)
{
	int result = 0;

	result = initApp();
	Uart_Printf("\n [INFO] INIT APP \n");

	return result;
}
