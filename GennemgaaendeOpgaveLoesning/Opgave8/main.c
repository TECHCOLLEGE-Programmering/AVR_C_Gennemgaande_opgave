/*
 ********************* Status register and EEPROM ******************************
 * Opgave8
 * Created: 13-10-2020 12:49:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * May be copied and used with source reference.
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define PORTB_ON(x)				PORTB |= (1 << x)
#define PORTB_OFF(x)			PORTB &= ~(1 << x)
#define PORTB_TOGGLE(x)			PORTB ^= (1 << x)
#define SWITCH_PRESSED_PIND(x)	!(PIND & (1 << x))

ISR (PCINT2_vect) {
	if (SWITCH_PRESSED_PIND(PIND4)) // Checks if PIND4 is pressed.
	{
		PORTB_OFF(PB5); // Turns off PB5
		PORTB_TOGGLE(PB4); // Toggles PB5
	} 
	else
	{
		PORTB_ON(PB5); // Turns on PB5
	}
}

int main(void)
{
	DDRB |= (1 << DDB5) | (1 << DDB4);

	DDRD &= ~(1 << DDD4);
	
	PCMSK2 |= (1 << PCINT20); // Enable pin change interrupt mask for PD4. page 69 datasheet.
    PCICR |= (1 << PCIE2); // Enable pin change interrupt for PCINT23..16. page 68 datasheet.
	
	sei();

	while (1)
    {
		
    }
}