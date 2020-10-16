/*
 * GccTestApplication.c
 *
 * Created: 27-03-2020 13:37:52
 * Author : lkri
 */ 

#include <avr/io.h>

int main(void)
{
const volatile char asemblerline asm("ldi DDRB, 0xff");
	
    while (1)
    {
    }
}