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
void cmd_lcd(unsigned char cmd)
{
    LCD = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
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
    cmd_lcd(0x38);
    cmd_lcd(0x0C); 
    cmd_lcd(0x06); 
    cmd_lcd(0x01); 
    cmd_lcd(0x80); 
}
void main()
{
    unsigned char i;
    unsigned char msg[] = "WELCOME TO 8051";
    init();
    for(i=0; msg[i]!='\0'; i++)
    {
        data_lcd(msg[i]);
    }
    while(1)
    {
        for(i=0; i<16; i++)
        {
            cmd_lcd(0x18);
            delay();
        }
        cmd_lcd(0x02);
        delay();
    }
}