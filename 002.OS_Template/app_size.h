
#define SECTOR_SIZE 		512
#define ALIGN_SECTOR(x)	 	((((x+(SECTOR_SIZE-1))&~(SECTOR_SIZE-1))/SECTOR_SIZE))

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

#define META_TABLE_BASE_APP		0x44B00000

#define META_TABLE_LIMIT_APP	META_TABLE_BASE_APP + (1*1024*1024)

#define DEMAND_PAGE_BASE		0x44C00000

#define SIZE_DEMAND_PAGE		(1*1024*1024)
#define SIZE_META				(SIZE_DEMAND_PAGE / 1024)
#define MAX_META_PAGE			(SIZE_META / 4)

/**
 *		0x44100000 ------------------------------------------
 *
 *		APP 0
 *
 *		0x44500000 ------------------------------------------
 *
 *		APP 1
 *
 *		0x44900000 ------------------------------------------
 *
 *		APP 0 stack
 *
 *		0x44a00000 ------------------------------------------
 *
 *		APP 1 stack
 *
 *		0x44b00000 ------------------------------------------
 *
 *		APP 0 PCB
 *
 *		0x44b00200 ------------------------------------------
 *
 *		APP 1 PCB
 *
 *		0x44b00400 ------------------------------------------
 *
 *		APP 0 META_DEMAND_PAGE
 *
 *		0x44b00800 ------------------------------------------
 *
 *		@@@@@  RESERVED  @@@@@
 *
 *		0x44b10000 ------------------------------------------
 *
 *		shareAdrress
 *
 *		0x44c00000 ------------------------------------------
 *
 *		DEMAND_PAGE
 *
 *		0x44d00000 ------------------------------------------
 *
 *		@@@@@  RESERVED  @@@@@
 *
 *		0x84100000 ------------------------------------------
 *
 *		Program
 *
 *		0x84500000 ------------------------------------------
 */
