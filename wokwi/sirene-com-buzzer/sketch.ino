#include <util/delay.h>

// Hardware registers
#define BARE_DDRB  (*(volatile unsigned char *)(0x37))
#define BARE_PORTB (*(volatile unsigned char *)(0x38))

// Port B bit positions
#define BUZZER_PIN 0
#define PIN_3      3
#define PIN_4      4


// Low siren tone: approximately 700 Hz
void tone_low(void)
{
    // 350 cycles ≈ 0.5 second
    for (unsigned int i = 0; i < 350; i++) {

        // Buzzer HIGH
        BARE_PORTB |= (1 << BUZZER_PIN);
        _delay_us(714);

        // Buzzer LOW
        BARE_PORTB &= ~(1 << BUZZER_PIN);
        _delay_us(714);
    }
}


// High siren tone: approximately 1000 Hz
void tone_high(void)
{
    // 500 cycles = approximately 0.5 second
    for (unsigned int i = 0; i < 500; i++) {

        // Buzzer HIGH
        BARE_PORTB |= (1 << BUZZER_PIN);
        _delay_us(500);

        // Buzzer LOW
        BARE_PORTB &= ~(1 << BUZZER_PIN);
        _delay_us(500);
    }
}


int main(void)
{
    // Configure PB0, PB3 and PB4 as outputs
    BARE_DDRB |=
        (1 << BUZZER_PIN) |
        (1 << PIN_3) |
        (1 << PIN_4);

    while (1) {

        // -------------------------
        // LED 3 ON
        // LED 4 OFF
        // Low siren tone
        // -------------------------

        BARE_PORTB |=  (1 << PIN_3);
        BARE_PORTB &= ~(1 << PIN_4);

        tone_low();


        // -------------------------
        // LED 3 OFF
        // LED 4 ON
        // High siren tone
        // -------------------------

        BARE_PORTB &= ~(1 << PIN_3);
        BARE_PORTB |=  (1 << PIN_4);

        tone_high();
    }
}