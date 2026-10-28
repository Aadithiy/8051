#include <reg52.h>
sbit LED = P1^0;
sbit SW  = P3^0;
void main()
{
	SW = 0;
	P1 = 0x00;
    while(1)
    {
        if(SW == 0)
        {
            LED = 1;
        }
        else
        {
            LED = 0;
        }
    }
}