#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRD |= (1 << PD6);

    TCCR0A |= ((1 << COM0A1)|(1 << WGM00)|(1 << WGM01));
    TCCR0B |= (1 << CS00);
    uint8_t pwm = 0xff;
    bool up = false;
    while (1)
    {
        OCR0A = pwm;
        pwm += up ? 1 : -1;
        if (pwm == 0xff)
            up = false;
        else if (pwm == 0x20)
            up = true;
        _delay_ms(20);
    }
}
