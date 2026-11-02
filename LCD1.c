#include <reg52.h>
#define LCD P2
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;
void delay()
{
	int i,j;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++);
	}
}

void cmd_led(unsigned char cmd)
{
	LCD = cmd;
	RS = 0;
	RW = 0;
	EN  =1;
	delay();
	EN = 0;
	delay();
}
void data_lcd(unsigned char d)
{
	LCD = d;
	RS = 1;
	RW = 0;
	EN = 1;
	delay();
	EN = 0;
	delay();
}
void init()
{
	cmd_led(0x38);
	cmd_led(0x0c);
	cmd_led(0x06);
	cmd_led(0x01);
	cmd_led(0x80);
}
void main()
{
	unsigned char i;
	unsigned char word[] = "HELLO";
	init();
	for(i=0;i!='\0';i++)
	{
		data_lcd(word[i]);
	}
	while(1);
}