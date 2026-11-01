#include <reg52.h>
sbit LED = P1^0;
unsigned char tick = 0;
void timer_isr() interrupt 1
{
	TH0 = 0x4C;
	TL0 = 0x00;
	if (++tick == 0)
	{
		tick = 0;
		LED = ~LED;
	}
}
void main()
{
	LED = 1;
	TMOD = 0xF0;
	TMOD = 0x01;
	TH0 = 0x4C;
	TL0 = 0x00;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
	while(1);
}