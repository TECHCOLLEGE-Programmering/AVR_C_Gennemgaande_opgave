/*
 ********************* Opgave11 - USART Serial Com ******************************
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
#include <stdio.h>
#include <string.h>

/* Project defines */
#define fosc 16000000 // Defines clock speed for calculation
#define baud 115200 // Defines Baud rate
#define UBRRVAL fosc/16/baud-1 // Calculate the value of UBRR

/* Sets up the USART registers */
void USART_Init () {
	UBRR0H = (unsigned char)(UBRRVAL >> 8);	// Set baud rate
	UBRR0L = (unsigned char)UBRRVAL;
	UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);	// Enable receiver and transmitter
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01) | (1 << USBS0);	// Set frame format: 8bit, 2 stop bit
}

/* Waits to receive a char from the serial/USART bus and returns it .*/
unsigned char USART_receive () {
	while ( !( UCSR0A & (1<<UDRE0)));
	
	return UDR0;
}

/* Waits for a char to transmit to the serial/USART bus and returns it .*/
void USART_transmit(unsigned char cmd) {
	while ( !( UCSR0A & (1<<UDRE0)));		//Wait for empty transmit buffer
	
	UDR0 = cmd;								// Put data into buffer, sends the data
}

int main(void)
{
	USART_Init();
	
    while (1) 
    {
		USART_transmit(USART_receive()); // Transmit what is received
		_delay_ms(3000);
    }
}

/* // The Assembler version
start:	clr	tmp
sts	UBRR0H,tmp
ldi	tmp,0x08		; 115200 Baud, se side 197
sts	UBRR0L, tmp		; 9600 Baud = 0x67/D103
clr	tmp

sts	UCSR0A,tmp		; Nulstilles. Se side 189
ldi	tmp,0x08
sts	UCSR0B,tmp		; TX enable. Se side 190

ldi	tmp,0x06		; 8 bit.
sts	UCSR0C,tmp		; Se side 191-192
ldi	tmp, 'A'		; Side  189
sts	UDR0,tmp		; Send bogstavet/ASCII værdien “A”

loop:

inc	tmp				;Vælg næste ASCII værdi
sts	UDR0,tmp		; Send ASCII værdi/karakter til port
ldi	count1, 0x07	; Forsinkelse
dly2:	ldi	ZH,0xFF	;  -”-
ldi	ZL,0xFF			;  -”-

dly:	sbiw 	ZL,1
brne	dly
dec	count1
brne	dly2
rjmp	loop
*/