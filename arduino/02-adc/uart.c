#include "uart.h"

void USART_init(void){

    UBRR0H = (uint8_t)(BAUD_PRESCALER>>8);
    UBRR0L = (uint8_t)(BAUD_PRESCALER);
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
}

unsigned char USART_receive(void){
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}

void USART_send( unsigned char data){
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

void USART_putstring(char* StringPtr){
    while(*StringPtr != 0x00){
        USART_send(*StringPtr);
        StringPtr++;}
}

void USART_clean(void){
    USART_putstring("\033[2J");
}
