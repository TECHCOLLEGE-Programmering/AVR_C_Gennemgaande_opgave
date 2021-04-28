/*
 ********************* Opgave 5a ******************************
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

// Assembly code auto-generated from http://darcy.rsgc.on.ca/ACES/TEI4M/AVRdelay.html
// by utility from Bret Mulvey
// Delay 16 000 000 cycles
// 1s at 16.0 MHz
void delay_1sec(){
	asm volatile (
	"    ldi  r18, 82	\n"
	"    ldi  r19, 43	\n"
	"    ldi  r20, 0	\n"
	"1:  dec  r20		\n"
	"    brne 1b		\n"
	"    dec  r19		\n"
	"    brne 1b		\n"
	"    dec  r18		\n"
	"    brne 1b		\n"
	"    lpm			\n"
	"    nop			\n"
	);

}

int main(void)
{
	DDRB = 0xFF; // Sets up DDR
    while (1) 
    {
		PORTB = 0xFF; // Turns on PORTB
		//Or use _delay_ms(1000);
		delay_1sec();
		PORTB = 0x00; // Turns on PORTB
		//Or use _delay_ms(1000);
		delay_1sec();
    }
}