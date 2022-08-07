/*
 * USART_Conf.h
 *
 * Created: 9/13/2019 1:28:32 AM
 *  Author: Abdelrhman
 */ 


#ifndef USART_CONF_H_
#define USART_CONF_H_


	#define Baud_Rate	103
	#define NO_of_DATA_BITS	8
	#define NO_of_STOP_BITS	2
	#define RX_Complete_Interrupt_Enable	ENABLE
	#define TX_Complete_Interrupt_Enable	ENABLE
	#define Data_Register_Empty_Interrupt	ENABLE
	#define Clock_POLARITY_MODE				RISING_INPUT_FALLING_OUTPUT
	#define USART_MODE_SELECT				Asynchronous_Operation
	#define PARITY_MODE						PARITY_DISABLED
#endif /* USART_CONF_H_ */