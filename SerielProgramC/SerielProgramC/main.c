/*
 * SerielProgramC.c
 *
 * Created: 28-04-2020 08:44:02
 * Author : lkri
 */ 

#define F_CPU 16000000UL  // 16 MHz

#include <avr/io.h> // avr header file for IO ports
#include <util/delay.h>
char ch;

char get_char(void)
{
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void put_char(char c)
{
	while (!(UCSR0A & (1<< UDRE0)));
	UDR0 = c;
}

void init_uart()
{
	UCSR0B=0x00;	// Control reg.
	UCSR0A=0x00;	// Control reg.
	UCSR0C=0x06;	// 8 Bit data					Side 192
	UBRR0H=0x00;    // Baudrate High = 0			Side 197
	UBRR0L=0x67;	// Baudrate Low  = 9600 Baud
	UCSR0B=0x18;	//  TX og RX enable				Side 190
}

void BlinkPortB(int8_t LED)
{
	PORTB |= (1 << LED);
	_delay_ms(500);
	PORTB &= ~(1 << LED);
}

int main(void)
{
	DDRB |= (1 << PB5);
	init_uart();
	put_char('G');
	put_char('o');
	put_char('d');
	
	BlinkPortB(PB5);
	while(1)
	{
		ch = get_char();
		put_char(ch);

	}
	return 1;
}