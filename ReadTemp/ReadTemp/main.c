/*
 * ReadTemp.c
 *
 * Created: 14-04-2021 10:04:56
 * Author : lkri
 */ 

#define F_CPU 16000000UL  // 16 MHz

#include <avr/io.h> // avr header file for IO ports
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "avr/iom168.h"

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

//max 255 long text
void put_char_array(char char_array[])
{
	const int lenght = strlen(char_array);
	
	for (int i = 0; i <= lenght; i++ )
	{
		put_char(char_array[i]);
	}
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

void check_sensor(unsigned long *sensor_data){
	// Start an ADC conversion by setting ADSC bit (bit 6)
	ADCSRA |= (1 << ADSC);
	
	// Wait until the ADSC bit has been cleared
	while(ADCSRA & (1 << ADSC));
	
	*sensor_data = 0;
	*sensor_data += (ADCH << 8);
	//*sensor_data += ADCL;
}

int main(void)
{
	//DDR setup
	DDRC &= ~(1 << PC2);
	DDRB |= (1 << PB5);
	
	//USART setup
	init_uart();
	
	//Analog setup
	ADMUX = 0b01100010;		// Configure ADC to be left justified, use AVCC as reference, and select ADC0 as ADC input
	ADCSRA = 0b10000111;	// Enable the ADC and set the prescaler to max value (128)
	
	DIDR0  = 0b00011111;	// Disable digital input on ADC Channel 4 to reduce power consumption


	//start op message
	put_char_array("\nGodmorgen\n");
	BlinkPortB(PB5);

	unsigned long sensor_data = 0;
	char buffer[20];
	char control_char = '-';
	while(1)
	{
		control_char = '-';
		control_char = get_char();
		if (control_char == 't')
		{
			put_char_array("\nTemp: ");
			check_sensor(&sensor_data);
			ultoa(sensor_data, buffer, 10); // string to unsigned long int
			put_char_array(buffer);
		}
		else if (control_char == 'c')
		{
			put_char_array("\nControl: ");
			ultoa((255 << 8), buffer, 10); // long to string
			put_char_array(buffer);
		}
	}
	return 1;
}