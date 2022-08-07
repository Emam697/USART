/*
 * USART_Interface.h
 *
 * Created: 9/13/2019 12:38:34 AM
 *  Author: Abdelrhman
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

	#define RECEIVER_ENABLE_BIT	4
	#define TRANSMITTER_ENABLE_BIT	5	
	
	#define RXEN	4
	#define TXEN	3
	
	#define URSEL	7
	#define UMSEL	6
	#define UDRIE	5
	#define UCSZ2	2
	#define UCSZ1	2
	#define UCSZ0	1
	#define USBS	3	
	#define UCPOL	0
	
	//#define DISABLE	0
	
	/*#define ENABLE	1
	#define UPM0	4
	#define UPM1	5
	#define UDRE	5
	#define RXC		7*/
	typedef enum
	{
		RISING_INPUT_FALLING_OUTPUT = 0,
		FALLING_INPUT_RISING_OUTPUT
	}Clock_Polarity;
	
	typedef enum
	{
		Asynchronous_Operation = 0,
		synchronous_Operation
	}USART_Mode_Select;
	
	typedef enum
	{
		PARITY_DISABLED = 0,
		PARITY_EVEN,
		PARITY_ODD	
	}Parity_Mode;
	
	typedef struct
	{
		uint8 Data_Bits;
		uint8 Stop_Bits;
		uint8 RX_Interrupt_Enable;
		uint8 TX_Interrupt_Enable;
		uint8 UDRI_ENABLE;
		Clock_Polarity CLK_Polarity;
		USART_Mode_Select Mode;
		Parity_Mode PMode;
	}USART_CONFIGURATION;
	
	void USART_Init(void);
	void USART_SetConfig(void);
	void USART_Transmit(uint8 Data);
	uint8 USART_Receiver(void);

#endif /* USART_INTERFACE_H_ */