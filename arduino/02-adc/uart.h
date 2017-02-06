#ifndef UART_H
#define UART_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef BAUDRATE
#define BAUDRATE 57600
#endif

#ifndef BAUD_PRESCALER
#define BAUD_PRESCALER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#endif

#include <avr/io.h>

void USART_init(void);
unsigned char USART_receive(void);
void USART_send(unsigned char data);
void USART_putstring(char* StringPtr);
void USART_clean(void);

#endif
