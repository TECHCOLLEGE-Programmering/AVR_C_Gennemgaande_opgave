/*
 ********************* Opgave 4 ******************************
 * GennegåendeOpgaveLosning
 * Created: 26-04-21 15:07:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * May be copied and used with source reference.
 */

#include <avr/io.h>


int main(void)
{
	DDRB = 0xFF; // Sets up DDR
    while (1) 
    {
		PORTB = 0xFF; // Turns on PORTB
		PORTB = 0x00; // Turns on PORTB
    }
}