#include <reg52.h>
sbit LED = P1^0;
unsigned char SW = 1;
void main()
{
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