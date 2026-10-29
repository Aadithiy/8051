#include <reg52.h>
sbit Led = P1^2;
void delay()
{
	int i,j,k;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<500;j++)
		{
			for(k=0;k<9;k++);
		}
	}
}
void main()
{
	while(1)
	{
		Led = 0;
		delay();
		Led = 1;
		delay();
	}
}