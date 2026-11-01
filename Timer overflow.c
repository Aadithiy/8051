#include <reg52.h>
void delay()
{
	TMOD = 0xF0;
	TMOD = 0x01;
	TH0 = 0x3C;
	TL0 = 0xB0;
	TR0 = 1;
	while (TF0 == 0);
	
		TR0 = 0;
		TF0 = 0;
	
}
void main()
{
	while (1)
	{
	P1 = 0x00;
	delay();
		delay();
	P1 = 0xFF;
	delay();
		delay();
	}
}