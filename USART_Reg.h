/*
 * USART_Reg.h
 *
 * Created: 9/13/2019 12:37:54 AM
 *  Author: Abdelrhman
 */ 


#ifndef USART_REG_H_
#define USART_REG_H_


	#define USART_UDR	(*(volatile uint8 *) 0x2C)
	#define USART_UCSRA	(*(volatile uint8 *) 0x2B)
	#define USART_UCSRB	(*(volatile uint8 *) 0x2A)
	#define USART_UCSRC	(*(volatile uint8 *) 0x40)
	#define USART_UBRRL	(*(volatile uint8 *) 0x29)
	#define USART_UBRRH	(*(volatile uint8 *) 0x40)

#endif /* USART_REG_H_ */