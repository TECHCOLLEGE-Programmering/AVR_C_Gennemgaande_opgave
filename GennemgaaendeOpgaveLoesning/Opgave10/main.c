/*
 ********************* Opgave 10 ******************************
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

/* Projects defines */
#define LED_ON(x)	PORTD |= (1 << x)
#define LED_OFF(x)	PORTD &= ~(1 << x)
#define GREEN		PIND2
#define YELLOW		PIND3
#define RED			PIND4

/* Method that executes the transition from green to red light*/
void Green_to_Red(){
	LED_OFF(GREEN);
	LED_ON(YELLOW);
	_delay_ms(1000);
	LED_OFF(YELLOW);
	LED_ON(RED);
}

/* Method that executes the transition from red to green light*/
void Red_to_Green(){
	LED_ON(YELLOW);
	_delay_ms(1000);
	LED_OFF(RED);
	LED_OFF(YELLOW);
	LED_ON(GREEN);
}

int main(void)
{
	DDRD = 0xFF; // Sets up DDR to be 0b11111111
	
    while (1) 
    {
		Green_to_Red();
		_delay_ms(5000);
		Red_to_Green();
		_delay_ms(5000);
    }
}

