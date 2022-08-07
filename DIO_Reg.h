/*
 * DIO_Reg.h
 *
 * Created: 8/16/2019 4:56:04 PM
 *  Author: Abdelrhman
 */ 
#include "../../LIB/types.h"

#ifndef DIO_REG_H_
#define DIO_REG_H_

	#define PINA				(*(volatile uint8 *)  0x39)
	#define DDRA				(*(volatile uint8 *)  0x3A)
	#define PORTA				(*(volatile uint8 *)  0x3B)
	#define PINB				(*(volatile uint8 *)  0x36)
	#define DDRB				(*(volatile uint8 *)  0x37)
	#define PORTB				(*(volatile uint8 *)  0x38)
	#define PINC				(*(volatile uint8 *)  0x33)
	#define DDRC				(*(volatile uint8 *)  0x34)
	#define PORTC				(*(volatile uint8 *)  0x35)
	#define PIND				(*(volatile uint8 *)  0x30)
	#define DDRD				(*(volatile uint8 *)  0x31)
	#define PORTD				(*(volatile uint8 *)  0x32)



#endif /* DIO_REG_H_ */