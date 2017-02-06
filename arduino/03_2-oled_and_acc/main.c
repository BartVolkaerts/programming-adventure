#define F_CPU 16000000UL 
#include "src/u8g.h"
#include "src/u8g_com_i2c.c"
#include <avr/io.h>
#include <util/delay.h>
#include <util/twi.h>

u8g_t u8g;
 
void u8g_setup(void)
{
    u8g_InitI2C(&u8g, &u8g_dev_ssd1306_128x64_i2c, U8G_I2C_OPT_NONE);
    u8g_SetColorIndex(&u8g, 1);
}

void adc_init(void){
    ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));    //16Mhz/128 = 125Khz the ADC reference clock
    ADMUX |= (1<<REFS0);                //Voltage reference from Avcc (5v)
    ADCSRA |= (1<<ADEN);                //Turn on ADC
    ADCSRA |= (1<<ADSC);                //Do an initial conversion because this one is the slowest and to ensure that everything is up and running
}

uint16_t read_adc(uint8_t channel){
    ADMUX &= 0xF0;                    //Clear the older channel that was read
    ADMUX |= channel;                //Defines the new ADC channel to be read
    ADCSRA |= (1<<ADSC);                //Starts a new conversion
    while(ADCSRA & (1<<ADSC));            //Wait until the conversion is done
    return ADCW;                    //Returns the ADC value of the chosen channel
}

int main(void)
{
    CLKPR=0x80;
    uint16_t acc_x_val = 0;
    uint16_t acc_y_val = 0;
    int x_coor = 60;
    int y_coor = 30;
    int draw = 0;

    adc_init();
    u8g_setup();
    u8g_SetFont(&u8g, u8g_font_courR10);

    while(1)
    {
        acc_x_val = read_adc(7);
        if (acc_x_val > 520)
            x_coor--;
        else if (acc_x_val < 490)
            x_coor++;
        acc_y_val = read_adc(6);
        if (acc_y_val > 520)
            y_coor++;
        else if (acc_y_val < 490)
            y_coor--;
        u8g_FirstPage(&u8g);
        if (draw == 3){
        do
        {
            u8g_DrawBox(&u8g, x_coor,y_coor, 3,3);
        }while(u8g_NextPage(&u8g));
        draw = 0;
        }
        draw++;
    }
}
