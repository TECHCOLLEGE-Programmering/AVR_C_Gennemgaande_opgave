/*
 * BlinkC.c
 *
 * Created: 12-10-2020 15:06:10
 * Author : lkri
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define LED13 5
void blink () {
	 PORTB = 0xFF;
	 _delay_ms(5000);
	 PORTB = 0x00;
	 _delay_ms(5000);
}

int main(void)
{
	DDRB = 0xFF;
	
	while(1)
	{
		blink();
	}
}
