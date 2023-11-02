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
	Init_App(RAM_APP0, stackBase[0], stackBase[1]);

	return result;
}

int setApp(int index)
{
	int result = 0;

	Uart_Printf("\nAPP%d set\n", index);
	SetTransTable(RAM_APP0, (RAM_APP0+sizeApp[index]-1), ram[index], RW_WBWA_LOCAL);
	SetTransTable(stackLimit[index], STACK_BASE_APP1-1, stackLimit[index], RW_WBWA_LOCAL);
//	CoInvalidateMainTlb();
	int asid = index | (1 << 4);
	CoSetASID(asid);

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