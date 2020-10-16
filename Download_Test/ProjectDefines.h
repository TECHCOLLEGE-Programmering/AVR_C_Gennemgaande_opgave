/*
 * ProjectDefines.h
 *
 * Created: 15-01-2018 14:56:37
 *  Author: ltpe
 */ 

#include <avr/io.h>

#ifndef PROJECTDEFINES_H_
#define PROJECTDEFINES_H_

#define YellowLedBit	5 
#define GreenLedBit		4 
#define RedLedBit		3 


#define YellowLedValue (1 << YellowLedBit)	//Pin 13
#define GreenLedValue (1 << GreenLedBit)	//Pin 12
#define RedLedValue (1 << RedLedBit)		//Pin 11

#endif /* PROJECTDEFINES_H_ */