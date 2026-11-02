#include <reg52.h>
#define LCD P2
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;
sbit SW = P1^0;
sbit LED = P1^1;
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
void lcd_string(unsigned char *str)
{
    while(*str != '\0')
    {
        data_lcd(*str);
        str++;
    }
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
    unsigned char current;
    unsigned char status = 2;
    SW = 1;   
    LED = 0;      
    init();
    cmd_lcd(0x80);
    lcd_string("LED CONTROL");
    while(1)
    {
        current = SW;
        delay();
        if(current != status)
        {
            cmd_lcd(0xC0);
            if(current == 0)
            {
                LED = 1;

                lcd_string("LED: ON       ");
            }
            else
            {
                LED = 0;

                lcd_string("LED: OFF      ");
            }
            status = current;
        }
    }
}