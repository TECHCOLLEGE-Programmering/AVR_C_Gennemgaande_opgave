/*
 ********************* Opgave 7 ******************************
 * GennegåendeOpgaveLosning
 * Created: 26-04-21 15:07:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * May be copied and used with source reference.
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

/* Project defines */
#define LED13					PINB5
#define READPIN4				PIND4
#define PINB_TOGGLE(x)			PORTB ^= (1 << x)
#define SWITCH_PRESSED_PIND(x)	(PIND & (1 << x))

int main(void)
{
	DDRD &= ~(1 << READPIN4);
	DDRB |= (1 << LED13);
	
    while (1) 
    {
		if (SWITCH_PRESSED_PIND(READPIN4)) // Checks if PIND4 is pressed.
		{
			PINB_TOGGLE(LED13); // Toggles PINB5.
			_delay_ms(300); // Tiny delay to make sure the toggle doesn't just repeat.
		}
    }
}

