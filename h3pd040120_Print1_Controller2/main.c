/*
 * h3pd040120_Print1.c
 *
 * Created: 28-04-2020 12:20:04
 * Author : ltpe
 */ 

#include <avr/io.h>
#include <string.h>
#include "uart.h"


int main(void)
{
	RS232Init();
	char UartPutchStringArray[] = "Udskrevet med Putch fra char of Arrays\n";
	char UartPutchStringArrayUsingCharPointer[] = "Udskrevet med Putch fra char of Arrays ved brug af Char Pointer\n";
	char *StringPointer;
	uint8_t StringCounter;
	
	StringPointer = UartPutchStringArrayUsingCharPointer;
	StringPointer = &UartPutchStringArrayUsingCharPointer;
	StringPointer = &UartPutchStringArrayUsingCharPointer[0];
	
	uart_putch('U', stdout);
	putc('d', stdout);
	putc('s', stdout);
	putc('k', stdout);
	putc('r', stdout);
	putc('e', stdout);
	putc('v', stdout);
	putc('e', stdout);
	putc('t', stdout);
	putc(' ', stdout);
	putc('m', stdout);
	putc('e', stdout);
	putc('d', stdout);
	putc(' ', stdout);
	putc('P', stdout);
	putc('u', stdout);
	putc('t', stdout);
	putc('c', stdout);
	putc('h', stdout);
	putc('\n', stdout);
	
	for (StringCounter = 0; StringCounter < strlen(UartPutchStringArray); StringCounter++)
	{
		putc(UartPutchStringArray[StringCounter], stdout);
	}
	
	while (*StringPointer != '\n')
	{
		putc(*StringPointer, stdout);
		StringPointer++;
	}
	putc(*StringPointer, stdout);
	
	printf("Udskrevet med Printf\n");
	
	printf(UartPutchStringArray);
	
	printf(UartPutchStringArrayUsingCharPointer);
    /* Replace with your application code */
    while (1) 
    {
    }
}

