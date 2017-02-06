#define F_CPU 16000000UL 
#include "src/u8g.h"
#include "src/u8g_com_i2c.c"
#include <avr/io.h>
#include <util/delay.h>
#include <util/twi.h>

u8g_t u8g;
 
void u8g_setup(void)
{
    u8g_SetPinLevel(PD0, 1); u8g_SetPinOutput(PD0);
    u8g_SetPinLevel(PD1, 1); u8g_SetPinOutput(PD1);
    u8g_InitI2C(&u8g, &u8g_dev_ssd1306_128x64_i2c, U8G_I2C_OPT_NONE);
    u8g_SetColorIndex(&u8g, 1);
}

int main(void)
{
    CLKPR=0x80;
    //DDRD=0xff; //set all pins of portD to output
    //PORTD=0xff; //internal pullups
    u8g_setup();
    while(1)
    {
        u8g_SetFont(&u8g, u8g_font_7x14);
        u8g_FirstPage(&u8g);
        do
        {
            u8g_DrawStr(&u8g, 0, 10, "Liesje <3");
        }while(u8g_NextPage(&u8g));
        u8g_Delay(100);
    }
}
