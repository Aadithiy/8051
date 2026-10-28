#include <reg52.h>
void delay()
{
	int i,j,k;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<100;j++)
		{
			for(k=0;k<10;k++);
		}
	}
}
void main()
{
	unsigned char led = 0x80;
	while(1)
	{
		P1 = led;
		delay();
		led = led>>1;
		delay();
		if(led == 0)
		{
			led = 0x80;
		}
	}
}