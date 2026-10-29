#include <reg52.h>
sbit Led = P1^0;
sbit Button = P3^2;
void External_interrupt(void) interrupt 0
{
	Led = !Led;
}
void main()
{
	P1 = 0x00;
	P3 = 0x00;
	Button = 1;
	IT0 = 1;
	EX0 = 1;
	EA = 1;
	PX0 = 1;
	while(1)
	{
	}
}