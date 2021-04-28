/*
 ********************* Opgave 5b - 16 bit register and Bit shifts ******************************
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
#define LED13	PINB5

/* Sets up the stack pointer.
 * The GCC compiler already does this, but just for educational purposes I included it. 
 */
#ifndef SPL
#define SPL  _SFR_IO8 (0x3D) //sets up Stack pointer low at the right I/O address
#endif
#ifndef SPH
#define SPH  _SFR_IO8 (0x3E) //sets up Stack pointer high at the right I/O address
#endif

/* Defines to get the high an low of 16 bit values*/
#define low(x)   ((x) & 0xFF)		//gets the lower 8 bits of value
#define high(x)   (((x)>>8) & 0xFF) //get the higher 8 bits of value

/* Example of shift operations over 3 LEDs */
void shift_example () {
	PORTB |= (1 << LED13);	//Set the bit of LED13
	_delay_ms(1000);
	PORTB &= ~(1 << LED13); //clear the bit of LED13
	_delay_ms(1000);
	PORTB ^= (1 << LED13);	//toggle the bit of LED13
	_delay_ms(1000);
	PORTB >>= 2;			//right shift whole byte[]
	_delay_ms(1000);
	PORTB <<= 1;			//left shift whole byte[]
	_delay_ms(1000);
	PORTB <<= 1;			//left shift whole byte[]
	_delay_ms(1000);
}

int main(void)
{
	SPL = low(RAMEND);		//Sets up stack pointer low
	SPH = high(RAMEND);		//Sets up stack pointer high
	
	DDRB = 0xFF;			//Set DDRB to 0xFF (0b11111111)
	
    while (1)				// infinite loop
    {
		shift_example();	//Runs the shift_example method
    }
}