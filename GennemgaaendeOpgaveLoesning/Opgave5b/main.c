/*
 ********************* 16 bit register and Bit shifts ******************************
 * GennegåendeOpgaveLosning
 * Created: 13-10-2020 12:49:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * Optimized for Atmel Studio 7.0
 * May be copied and used with source reference.
 */

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

/* Project defines */
#define LED13	PINB5
#define LED12	PINB4
#define LED11	PINB3

#define YellowLedValue	(1 << LED13)
#define GreenLedValue	(1 << LED12)
#define RedLedValue		(1 << LED11)


/* Sets up the stack pointer.
 * The gcc compiler already does this, but just for educational purposes I included it. 
 */
//#define SPL  _SFR_IO8 (0x3D)
//#define SPH  _SFR_IO8 (0x3E)

/* Defines to get the high an low of 16 bit values*/
#define low(x)   ((x) & 0xFF)
#define high(x)   (((x)>>8) & 0xFF)



void shift_example () {
	PORTB |= (1 << LED13); //Set a bit
	_delay_ms(1000);
	PORTB &= ~(1 << LED13); //clear a bit
	_delay_ms(1000);
	PORTB ^= (1 << LED13); //toggle bit
	_delay_ms(1000);
	PORTB >>= 2; //right shift whole byte[]
	_delay_ms(1000);
	PORTB <<= 1; //left shift whole byte[]
	_delay_ms(1000);
	PORTB <<= 1; //left shift whole byte[]
	_delay_ms(1000);
}

int main(void)
{
	SPL = low(RAMEND); // Sets up stack pointer low
	SPH = high(RAMEND); // Sets up stack pointer high
	
	DDRB = 0xFF;
	
    while (1) 
    {
		shift_example();
    }
}