/*
 * DIO_Interface.h
 *
 * Created: 8/16/2019 4:57:12 PM
 *  Author: Abdelrhman
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
	/**** STATE	****/
	#define OUTPUT					1
	#define INPUT_WITH_PULLUP		2
	#define INPUT_WITHOUT_PULLIP	3
	/*****************/
	
	/**** VALUES ****/
	#define HIGH 1
	#define LOW	 0
	/*****************/
	
	/**** PORTS ****/
	#define PORT_A	1
	#define PORT_B	2
	#define PORT_C	3
	#define PORT_D	4
	/*****************/
	
	/**** APIS ****/
	extern void  DIO_vSetPinDirection	(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum, uint8 Copy_uint8State);
	extern void  DIO_vWritePinValue		(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum, uint8 Copy_uint8Value);
	extern void  DIO_vSetPortDirection	(uint8 Copy_uint8Port, uint8 Copy_uint8State);
	extern uint8 DIO_uint8GetPinValue	(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);
	extern void  DIO_vTogglePin			(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum);
	extern void  DIO_vWritePortValue	(uint8 Copy_uint8Port, uint8 Copy_uint8Value);
	extern uint8 DIO_uint8GetPortValue	(uint8 Copy_uint8Port);

#endif /* DIO_INTERFACE_H_ */