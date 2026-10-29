#include <reg52.h>
sbit Led = P1^0;
sbit Button = P3^2;
void main()
{
	P1 = 0x00;
	P3 = 0x00;
	while(1)
	{
		if(Button == 1)
		{
			Led = 1;
		}
		else
		{
			Led = 0;
		}
	}
}