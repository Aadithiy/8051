#include <reg52.h>
sbit red = P1^0;
sbit yellow = P1^1;
sbit green =P1^2;
void delay()
{
	int i,k,j;
	for(i=0;i<1000;i++)
	{
		for (j=0;j<100;j++)
		{
			for(k=0;k<10;k++);
		}
	}
}
void main()
{
	P1 = 0x00;
	while(1)
	{
	red = 1;
	delay();
	red = 0;
	yellow = 1;
	delay();
	yellow = 0;
	green = 1;
	delay();
	green = 0;
	}
}
	