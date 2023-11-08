#include "app_service.h"
#include "device_driver.h"

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

int curAppNum = 0;
unsigned int asid[] = {(1 << 4), (1 << 4)|1};
unsigned int ttbr[] = {MMU_PAGE_TABLE_BASE, MMU_PAGE_TABLE_BASE + (1 << 14)};

unsigned int ram[] = {RAM_APP0, RAM_APP1};
unsigned int sizeApp[] = {SIZE_APP0, SIZE_APP1};
unsigned int stackLimit[] = {STACK_LIMIT_APP0, STACK_LIMIT_APP1};
unsigned int stackBase[] = {STACK_BASE_APP0, STACK_BASE_APP1};
unsigned int pcb[] = {PCBTABLE_BASE_APP0, PCBTABLE_BASE_APP1};
unsigned int sizePcb[] = {SIZE_PCB0, SIZE_PCB1};

int initApp(void)
{
	int result = 0;

	int i;
	for (i = 0; i < 2; i++){
		Init_App(ram[0], stackBase[0], stackBase[1]);
		SetAppTransTable(stackLimit[i], stackBase[i]-1, stackLimit[i], RW_WBWA_LOCAL, i);
		// 2�� ���̺�
		SetAppTransTablePageTable(ram[0], (ram[0]+sizeApp[0]-1), PAGE_1ST_RW, PAGE_2ST_RW_NCNB_LOCAL_NO_ACCESS, i);
		// pcb
		SetAppTransTable(pcb[i], pcb[i]+sizePcb[i]-1, ram[i], RW_WBWA, i);
		// mataDemandPage
		SetAppTransTable(META_DEMAND_PAGE, META_DEMAND_PAGE + SIZE_META - 1, META_DEMAND_PAGE, RW_WBWA, i);
		// DemandPage
		SetAppTransTable(DEMAND_PAGE_BASE, DEMAND_PAGE_BASE + SIZE_DEMAND_PAGE-1, DEMAND_PAGE_BASE, RW_WT, i);
		// ���α׷� �޸�
		SetAppTransTable(0x84100000, 0x84500000-1, ram[i], RW_WBWA_LOCAL, i);
	}

	extern unsigned int* metaDemandPageBase;

	for (i = 0; i < MAX_META_PAGE; i++)
	{
		*(metaDemandPageBase + i) = 1 << 31;
	}

	setApp(0);

	return result;
}

int setApp(int appNum)
{
	int result = 0;

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
