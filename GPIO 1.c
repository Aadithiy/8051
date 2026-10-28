#include <reg52.h>
sbit LED = P1^0;
void main()
{
	P1 = 0x00;
	LED = 1;
}