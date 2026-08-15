#include <util/delay.h>

// Define the exact hardware memory locations
#define BARE_DDRB  (*(volatile unsigned char *)(0x37))
#define BARE_PORTB (*(volatile unsigned char *)(0x38))

// Define the pin positions (Bits 0 to 5)
#define PIN_3 3
#define PIN_4 4

int main(void) {
    // Configure PIN 3 and PIN 4 as outputs
    BARE_DDRB |= (1 << PIN_3) | (1 << PIN_4);

    // Set PIN 3 and PIN 4 to HIGH
    //BARE_PORTB |= (1 << PIN_3) | (1 << PIN_4);
    
    // PIN 3 HIGH, PIN 4 LOW
    BARE_PORTB |=  (1 << PIN_3);
    BARE_PORTB &= ~(1 << PIN_4);

    while (1) {
      BARE_PORTB ^= (1 << PIN_3) | (1 << PIN_4);
      _delay_ms(500);
    }
}
