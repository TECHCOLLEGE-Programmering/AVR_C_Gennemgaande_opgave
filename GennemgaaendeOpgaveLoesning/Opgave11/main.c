/*
 ********************* USART Serial Com ******************************
 * Opgave5b.c
 * Created: 13-10-2020 12:49:40
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



#define fosc 16000000
#define baud 115200
#define UBBRVAL fosc/16/baud-1

void USART_Init () {
	
	UBRR0H = (unsigned char)(UBBRVAL >> 8);	// Set baud rate
	UBRR0L = (unsigned char)UBBRVAL;
	UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);	// Enable receiver and transmitter
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01) | (1 << USBS0);	// Set frame format: 8bit, 2 stop bit
}

unsigned char USART_receive () {
	while ( !( UCSR0A & (1<<UDRE0)));
	
	return UDR0;
}

void USART_transmit(unsigned char cmd) {
	while ( !( UCSR0A & (1<<UDRE0)));		//Wait for empty transmit buffer
	
	UDR0 = cmd;								//Put data into buffer, sends the data
}

int main(void)
{
	USART_Init();
	
    while (1) 
    {
		USART_transmit(USART_receive());
		_delay_ms(3000);
    }
}

/*

start:	clr	tmp
sts	UBRR0H,tmp
ldi	tmp,0x08		;115200 Baud, se side 197
sts	UBRR0L, tmp	;9600 Baud = 0x67/D103
clr	tmp

sts	UCSR0A,tmp	; Nulstilles. Se side 189
ldi	tmp,0x08
sts	UCSR0B,tmp	; TX enable. Se side 190

ldi	tmp,0x06		; 8 bit.
sts	UCSR0C,tmp	; Se side 191-192
ldi	tmp, 'A'		; Side  189
sts	UDR0,tmp		; Send bogstavet/ASCII værdien “A”

loop:

inc	tmp		;Vælg næste ASCII værdi
sts	UDR0,tmp		; Send ASCII værdi/karakter til port
ldi	count1, 0x07	; Forsinkelse
dly2:	ldi	ZH,0xFF		;  -”-
ldi	ZL,0xFF		;  -”-
dly:	sbiw 	ZL,1
brne	dly
dec	count1
brne	dly2
rjmp	loop

*/
