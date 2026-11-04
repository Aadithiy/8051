#include <reg52.h>
sbit LED = P1^0;
sbit BUTTON = P3^2;
void Timer0_Delay()
{
    unsigned int i;
    for(i = 0; i < 20; i++)
    {
        TMOD = 0x01;     
        TH0 = 0x3C;       
        TL0 = 0xB0;       
        TR0 = 1;         
        while(TF0 == 0);  
        TR0 = 0;         
        TF0 = 0;          
    }
}
void main()
{
    unsigned char blink = 0;
    LED = 0;
    BUTTON = 1;     
    while(1)
    {
        if(BUTTON == 0)   
        {
            blink = !blink;
            while(BUTTON == 0); 
        }
        if(blink == 1)
        {
            LED = !LED;
            Timer0_Delay();
        }
        else
        {
            LED = 0;
        }
    }
}