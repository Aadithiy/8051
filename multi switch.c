#include <reg52.h>
sbit LED1 = P1^3;
sbit LED2 = P1^4;
sbit SW1 = P2^3;
sbit SW2 = P2^4;
void main()
{
	P1 = 0x00;
	P2 = 0x00;
	SW1 = 1;
	SW2 = 1;
  if(SW1 == 1)
	{
		LED1 = 1;
	}
	else
	{
		LED1 = 0;
	}
	if(SW2 == 1)
	{
		LED2 = 1;
	}
	else
	{
		LED2 = 0;
	}
}