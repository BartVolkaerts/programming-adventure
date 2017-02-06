#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "uart.h"

#define BLINK_DELAY_MS 1000

 
int main (void){
    //Initialize the USART
    USART_init();
    USART_clean();

    //Enable pin5 as output
    DDRB |= _BV(DDB5);

    while(1) {
        PORTB &= ~_BV(PORTB5);
        _delay_ms(BLINK_DELAY_MS);
        USART_clean();
        USART_putstring("ON\r");

        PORTB |= _BV(PORTB5);
        _delay_ms(BLINK_DELAY_MS);
        USART_clean();
        USART_putstring("OFF\r");
    }
}
