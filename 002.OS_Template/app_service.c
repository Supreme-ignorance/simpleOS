#include "app_service.h"
#include "device_driver.h"

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

int curAppNum = 0;

unsigned int ram[] = {RAM_APP0, RAM_APP1};
unsigned int sizeApp[] = {SIZE_APP0, SIZE_APP1};
unsigned int stackLimit[] = {STACK_LIMIT_APP0, STACK_LIMIT_APP1};
unsigned int stackBase[] = {STACK_BASE_APP0, STACK_BASE_APP1};

int initApp(void)
{
	int result = 0;

	// ���α׷� ���� �� ���� �ʿ�
	int i;
	for (i = 0; i < 2; i++){
		Init_App(ram[0], stackBase[0], stackBase[1]);
		SetAppTransTable(ram[0], (RAM_APP0+sizeApp[0]-1), ram[i], RW_WBWA_LOCAL, i);
		SetAppTransTable(stackLimit[i], stackBase[i]-1, stackLimit[i], RW_WBWA_LOCAL, i);
	}
	setApp(0);

	return result;
}

int setApp(int appNum)
{
	int result = 0;

	Uart_Printf("\n set APP%d - ASID : 0x%x, TTBR : 0x%x \n", appNum, asid[appNum], ttbr[appNum]);
//	CoInvalidateMainTlb();
	CoSetASID(asid[appNum]);
	CoSetTTBase(ttbr[appNum]|(1<<6)|(1<<3)|(0<<1)|(0<<0));

	return result;
}

int getCurAppNum(void)
{
	return curAppNum;
}

int setCurAppNum(int num)
{
	curAppNum = num;

	return curAppNum;
}
