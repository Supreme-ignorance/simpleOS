#include "device_driver.h"

char Uart1_Get_Char(void)
{
	while(Macro_Check_Bit_Clear(rUTRSTAT1,0));
	return rURXH1;
}

void Uart1_GetString(char *string)
{
    char *string2 = string;
    char c;
    int i = 0;
    while((c = Uart1_Get_Char())!='\r')
    {
        if(c=='\b')
        {
            if( (int)string2 < (int)string )
            {
                Uart_Printf("\b \b");
                string--;
            }
        }
        else
        {
            *string++ = c;
            Uart1_Send_Byte(c);
        }
    	Lcd_Printf(INPUT_X_START + (i++ * INPUT_X_SIZE), INPUT_Y_START, WHITE, BLACK, INNER_TEXT_SIZE, INNER_TEXT_SIZE, "%c", c);
    }
    *string='\0';
    Uart1_Send_Byte('\n');
}
