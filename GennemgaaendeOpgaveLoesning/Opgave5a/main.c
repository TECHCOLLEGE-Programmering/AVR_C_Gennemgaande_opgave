/*
 ********************* 16 bit register and Bit shifts ******************************
 * GennegåendeOpgaveLosning
 * Created: 13-10-2020 12:49:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * May be copied and used with source reference.
 */ 

#include <avr/io.h>

int main(void)
{
	DDRB |= 0b11111111;
	PORTB |= 0b11111111;
	PINB |= 0b11111111;  
    while (1) 
    {
		
    }
}

