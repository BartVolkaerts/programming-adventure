#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "uart.h"

#define BLINK_DELAY_MS 100

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

int main (void){
    uint16_t acc_val = 0;
    char acc_x_val_str[16];
    char acc_y_val_str[16];
    char acc_z_val_str[16];

    //Initialize the USART
    USART_init();
    USART_clean();

    //Init ADC
    adc_init();

    while(1) {
        acc_val = read_adc(6);
        //itoa(acc_val, acc_z_val_str, 10);
        //USART_putstring(acc_z_val_str);
        if (acc_val < 550 && acc_val > 450)
            USART_putstring("NORMAAL     \r");
        else if (acc_val < 550)
            USART_putstring("VOORWAARTS  \r");
        else if (acc_val > 450)
            USART_putstring("ACHTERWAARTS\r");
    }
}
