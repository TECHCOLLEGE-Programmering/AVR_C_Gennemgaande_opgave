/*
 * Download_Test.c
 *
 * Created: 31-03-2020 17:49:25
 * Author : ltpe
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer.h"
#include "Timer0.h"

int main(void)
{
	DDRB = 0xFF;
	PORTB = YellowLedValue;
	
	Setup_Timer0_Overflow_Interrupt(VariableValue2SecValue8Bit);
	Enable_Timer0_Overflow_Interrupt();
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

