#define RAM_APP0				0x44100000
#define RAM_APP1				(RAM_APP0+SIZE_APP0)
#define SIZE_STACK0				(1*1024*1024)
#define SIZE_STACK1				(1*1024*1024)
#define SIZE_PCB0				(1*512)
#define SIZE_PCB1				(1*512)
#define STACK_LIMIT_APP0		(RAM_APP1+SIZE_APP1)
#define STACK_LIMIT_APP1		(STACK_LIMIT_APP0+SIZE_STACK1)
#define STACK_BASE_APP0			(STACK_LIMIT_APP0+SIZE_STACK0)
#define STACK_BASE_APP1			(STACK_LIMIT_APP1+SIZE_STACK1)
#define PCB_BASE_APP0			(STACK_BASE_APP1)
#define PCB_BASE_APP1			(STACK_BASE_APP1+SIZE_PCB0)

#define SIZE_APP0				(4*1024*1024)
#define SIZE_APP1				(4*1024*1024)

#define SECTOR_APP0				100
#define SECTOR_APP1				5000

#define SIZE_PCB0				(1*512)
#define SIZE_PCB1				(1*512)

#define PCBTABLE_BASE_APP0		0x44B00000
#define PCBTABLE_BASE_APP1		PCBTABLE_BASE_APP0 + SIZE_PCB0

#define SIZE_META				(SIZE_DEMAND_PAGE / 1024)
#define MAX_META_PAGE			(SIZE_META / 4)

#define META_DEMAND_PAGE 		PCBTABLE_BASE_APP1 + SIZE_PCB1

#define SIZE_DEMAND_PAGE		(8*1024*1024)

#define DEMAND_PAGE_BASE		0x44C00000
