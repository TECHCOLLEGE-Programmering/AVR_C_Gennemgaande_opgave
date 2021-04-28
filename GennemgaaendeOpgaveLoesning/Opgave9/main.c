/*
 ********************* Opgave 9 ******************************
 * GennegåendeOpgaveLosning
 * Created: 26-04-21 15:07:40
 * Author : lkri
 * Created for Atmega168 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-9365-Automotive-Microcontrollers-ATmega88-ATmega168_Datasheet.pdf
 * May be copied and used with source reference.
 */

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h> // avr header file for IO ports
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

/* Project defines */
#define LED_ON(x) PORTB |= (1 << x)
#define LED_OFF(x) PORTB &= ~(1 << x)
#define LED13 PINB5
#define ANALOG_PIN2 PINC2

/*
* Method that blinks an LED
*/
void BlinkPortB(int8_t LED)
{
	PORTB |= (1 << LED);
	_delay_ms(500);
	PORTB &= ~(1 << LED);
}

/*
* Method that check the analog channel and updates through a pointer to a long
*/
void check_sensor(unsigned long *sensor_data){
	// Start an ADC conversion by setting ADSC bit (bit 6)
	ADCSRA |= (1 << ADSC);
	
	// Wait until the ADSC bit has been cleared
	while(ADCSRA & (1 << ADSC));
	
	*sensor_data = 0;
	*sensor_data += (ADCH << 8); // missing Voltage calculation
	//*sensor_data += ADCL;
}

int main(void)
{
	//DDR setup
	DDRC &= ~(1 << ANALOG_PIN2);
	DDRB |= (1 << LED13);
	
	//Analog setup
	ADMUX = 0b01100010;		// Configure ADC to be left justified, use AVCC as reference, and select ADC0 as ADC input
	ADCSRA = 0b10000111;	// Enable the ADC and set the prescaler to max value (128)
	
	DIDR0  = 0b00011111;	// Disable digital input on ADC Channel 4 to reduce power consumption

	//start op message
	BlinkPortB(PB5);

	unsigned long sensor_data = 0;

	while(1)
	{
		check_sensor(&sensor_data); //updates sensor_data
		
		/* Turns on LED if sensor_data is above 3000 in value*/
		if (sensor_data > 3000) 
		{
			LED_ON(LED13);
		} else {
			LED_OFF(LED13);
		}
	}
	return 1;
}