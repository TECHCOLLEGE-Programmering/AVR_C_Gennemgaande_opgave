/*
 * SerielProgramC.c
 *
 * Created: 28-04-2020 08:44:02
 * Author : lkri
 */ 

#define F_CPU 16000000UL  // 16 MHz

#include <avr/io.h> // avr header file for IO ports
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
	UCSR0B=0x00;    //Control reg.
	UCSR0A=0x00;    //Control reg.
	UCSR0C=0x06;     // 8 Bit data                            side 192
	UBRR0H=0x00;    // Baudrate High =0              Side 197
	UBRR0L=0x67;     // Baudrate Low  =9600 Baud
	UCSR0B=0x18;     //  TX og RX  enable              Side 190
}


int main(void)
{
	init_uart();
	put_char('God morgen');
	while(1)
	{
		ch = get_char();
		put_char(ch);

		
	}
	return 1;
}