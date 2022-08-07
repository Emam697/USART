/*
 * USART_Program.c
 *
 * Created: 9/13/2019 12:38:59 AM
 *  Author: Abdelrhman
 */ 
	#include "../../LIB/types.h"
	#include "../../LIB/Operational_Macros.h"
	#include "USART_Reg.h"
	#include "USART_Conf.h"
	#include "USART_Interface.h"
	USART_CONFIGURATION config = {NO_of_DATA_BITS,NO_of_STOP_BITS,
								  RX_Complete_Interrupt_Enable,
								  TX_Complete_Interrupt_Enable,
								  Data_Register_Empty_Interrupt,
								  RISING_INPUT_FALLING_OUTPUT,
								  USART_MODE_SELECT,
								  PARITY_MODE};
	
	void USART_Init(void)
	{
		clear_Bit(USART_UCSRC,URSEL);
		USART_UBRRH = (uint8) (Baud_Rate >> 8);
		USART_UBRRL = (uint8) (Baud_Rate);
		set_Bit(USART_UCSRB,RECEIVER_ENABLE_BIT);
		set_Bit(USART_UCSRB,TRANSMITTER_ENABLE_BIT);
		set_Bit(USART_UCSRC,URSEL);
		switch(config.Data_Bits)
		{
			case 5:
				clear_Bit(USART_UCSRB,UCSZ2);
				clear_Bit(USART_UCSRC,UCSZ1);
				clear_Bit(USART_UCSRC,UCSZ0);
				break;
			case 6:
				clear_Bit(USART_UCSRB,UCSZ2);
				clear_Bit(USART_UCSRC,UCSZ1);
				set_Bit(USART_UCSRC,UCSZ0);
				break;
			case 7:
				clear_Bit(USART_UCSRB,UCSZ2);
				set_Bit(USART_UCSRC,UCSZ1);
				clear_Bit(USART_UCSRC,UCSZ0);
				break;
			case 8:
				clear_Bit(USART_UCSRB,UCSZ2);
				set_Bit(USART_UCSRC,UCSZ1);
				set_Bit(USART_UCSRC,UCSZ0);
				break;
			case 9:
				set_Bit(USART_UCSRB,UCSZ2);
				set_Bit(USART_UCSRC,UCSZ1);
				set_Bit(USART_UCSRC,UCSZ0);
				break;
			default:
				break;
		}
		//NOofdatabits == 1? clear_Bit(USART_UCSRC,USBS) : set_Bit(USART_UCSRC,USBS);
		switch(config.Stop_Bits)
		{
			case 1:
				clear_Bit(USART_UCSRC,USBS);
				break;
			case 2:
				set_Bit(USART_UCSRC,USBS);
				break;
			default:
				break;
		}
		clear_Bit(USART_UCSRC,URSEL);
	}
	void USART_SetConfig(void)
	{
		if (config.RX_Interrupt_Enable == ENABLE)
		{
			set_Bit(USART_UCSRB,RXEN);
		}
		else if(config.RX_Interrupt_Enable == DISABLE)
		{
			clear_Bit(USART_UCSRB,RXEN);
		}
		if (config.TX_Interrupt_Enable == ENABLE)
		{
			set_Bit(USART_UCSRB,TXEN);
		}
		else if(config.TX_Interrupt_Enable == DISABLE)
		{
			clear_Bit(USART_UCSRB,TXEN);
		}
		if (config.UDRI_ENABLE == ENABLE)
		{
			set_Bit(USART_UCSRB,UDRIE);
		}
		else if (config.UDRI_ENABLE == DISABLE)
		{
			clear_Bit(USART_UCSRB,UDRIE);
		}
		
		if (config.Mode == Asynchronous_Operation)
		{
			clear_Bit(USART_UCSRC,UMSEL);
		}
		else if (config.Mode == synchronous_Operation)
		{
			set_Bit(USART_UCSRC,UMSEL);
		}
		if (config.CLK_Polarity == RISING_INPUT_FALLING_OUTPUT)
		{
			clear_Bit(USART_UCSRC,UCPOL);
		}
		else if (config.CLK_Polarity == FALLING_INPUT_RISING_OUTPUT)
		{
			set_Bit(USART_UCSRC,UCPOL);
		}
		if (config.PMode == PARITY_DISABLED)
		{
			clear_Bit(USART_UCSRC,UPM0);
			clear_Bit(USART_UCSRC,UPM1);
		}
		else if (config.PMode == PARITY_EVEN)
		{
			clear_Bit(USART_UCSRC,UPM0);
			set_Bit(USART_UCSRC,UPM1);
		}
		else if (config.PMode == PARITY_ODD)
		{
			set_Bit(USART_UCSRC,UPM0);
			set_Bit(USART_UCSRC,UPM1);
		}
	}
	void USART_Transmit(uint8 Data)
	{
		while(get_Bit(USART_UCSRA,UDRE) != 1);
		USART_UDR = Data;
	}
	uint8 USART_Receiver(void)
	{	
		while(get_Bit(USART_UCSRA,RXC) != 1);
		return USART_UDR;
	}