#include <reg52.h>
sbit button = P3^2;
void delay()
{
	int i,j;
	for (i=0;i<1000;i++)
	{
		for(j=0;j<100;j++);
	}
}
void main()
{
	unsigned char count = 0;
	P3 = 0x00;
	P1 = 0x00;
	while(1)
	{
		if(button == 1)
		{
			delay();
			if(button == 1)
			{
				count +=1;
				P1 = count;
				while(button == 1);
				
					delay();
				}
			}
		}
	}