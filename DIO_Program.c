/*
 * DIO_Program.c
 *
 * Created: 8/16/2019 4:57:36 PM
 *  Author: Abdelrhman
 */ 
#include "../../LIB/types.h"
#include "../../LIB/Operational_Macros.h"
#include "DIO_Reg.h"
#include "DIO_Interface.h"

void  DIO_vSetPinDirection		(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum, uint8 Copy_uint8State){
		if (Copy_uint8Port == PORT_A)
		{
			if (Copy_uint8State == OUTPUT)
			{
				set_Bit(DDRA,Copy_uint8PinNum);
			}else if(Copy_uint8State == INPUT_WITHOUT_PULLIP){
				clear_Bit(DDRA,Copy_uint8PinNum);
			}else if (Copy_uint8State == INPUT_WITH_PULLUP)
			{
				clear_Bit(DDRA,Copy_uint8PinNum);
				set_Bit(PORTA,Copy_uint8PinNum);
			}
	}
	else if (Copy_uint8Port == PORT_B)
	{
		if (Copy_uint8State == OUTPUT)
		{
			set_Bit(DDRB,Copy_uint8PinNum);
			}else if(Copy_uint8State == INPUT_WITHOUT_PULLIP){
			clear_Bit(DDRB,Copy_uint8PinNum);
		}else if (Copy_uint8State == INPUT_WITH_PULLUP)
		{
			clear_Bit(DDRB,Copy_uint8PinNum);
			set_Bit(PORTB,Copy_uint8PinNum);
		}
	}
	else if (Copy_uint8Port == PORT_C)
	{
		if (Copy_uint8State == OUTPUT)
		{
			set_Bit(DDRC,Copy_uint8PinNum);
			}else if(Copy_uint8State == INPUT_WITHOUT_PULLIP){
			clear_Bit(DDRC,Copy_uint8PinNum);
		}else if (Copy_uint8State == INPUT_WITH_PULLUP)
		{
			clear_Bit(DDRC,Copy_uint8PinNum);
			set_Bit(PORTC,Copy_uint8PinNum);
		}
	}
	else if (Copy_uint8Port == PORT_D)
	{
		if (Copy_uint8State == OUTPUT)
		{
			set_Bit(DDRD,Copy_uint8PinNum);
			}else if(Copy_uint8State == INPUT_WITHOUT_PULLIP){
			clear_Bit(DDRD,Copy_uint8PinNum);
		}else if (Copy_uint8State == INPUT_WITH_PULLUP)
		{
			clear_Bit(DDRD,Copy_uint8PinNum);
			set_Bit(PORTD,Copy_uint8PinNum);
		}
	}
}
void  DIO_vWritePinValue		(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum, uint8 Copy_uint8Value){
	if (Copy_uint8Port == PORT_A)
	{
		if (Copy_uint8Value == HIGH)
		{
			set_Bit(PORTA,Copy_uint8PinNum);
		}else if(Copy_uint8Value == LOW)
		{
			clear_Bit(PORTA,Copy_uint8PinNum);	
		}
	}
	else if (Copy_uint8Port == PORT_B)
	{
		if (Copy_uint8Value == HIGH)
		{
			set_Bit(PORTB,Copy_uint8PinNum);
		}else if(Copy_uint8Value == LOW)
		{
			clear_Bit(PORTB,Copy_uint8PinNum);
		}
	}
	else if (Copy_uint8Port == PORT_C)
	{
		if (Copy_uint8Value == HIGH)
		{
			set_Bit(PORTC,Copy_uint8PinNum);
		}else if(Copy_uint8Value == LOW)
		{
			clear_Bit(PORTC,Copy_uint8PinNum);
		}
	}
	else if (Copy_uint8Port == PORT_D)
	{
		if (Copy_uint8Value == HIGH)
		{
			set_Bit(PORTD,Copy_uint8PinNum);
		}else if(Copy_uint8Value == LOW)
		{
			clear_Bit(PORTD,Copy_uint8PinNum);
		}
	}
	
}
void  DIO_vSetPortDirection		(uint8 Copy_uint8Port, uint8 Copy_uint8State){
	if (Copy_uint8Port == PORT_A)
	{
		if (Copy_uint8State == OUTPUT)
		{
			DDRA |= 0xFF;
		}
		else if (Copy_uint8State == INPUT_WITHOUT_PULLIP)
		{
			DDRA |= 0x00;
		}
		else if (Copy_uint8State == INPUT_WITH_PULLUP)
		{
			DDRA |= 0x00;
			PORTA |= 0xFF;
		}
	}
	else if (Copy_uint8Port == PORT_B)
	{
		if (Copy_uint8State == OUTPUT)
		{
			DDRB |= 0xFF;
		}
		else if (Copy_uint8State == INPUT_WITHOUT_PULLIP)
		{
			DDRB |= 0x00;
		}
		else if (Copy_uint8State == INPUT_WITH_PULLUP)
		{
			DDRB |= 0x00;
			PORTB |= 0xFF;
		}
	}
	else if (Copy_uint8Port == PORT_C)
	{
		if (Copy_uint8State == OUTPUT)
		{
			DDRC |= 0xFF;
		}
		else if (Copy_uint8State == INPUT_WITHOUT_PULLIP)
		{
			DDRC |= 0x00;
		}
		else if (Copy_uint8State == INPUT_WITH_PULLUP)
		{
			DDRC |= 0x00;
			PORTC |= 0xFF;
		}
	}
	else if (Copy_uint8Port == PORT_D)
	{
		if (Copy_uint8State == OUTPUT)
		{
			DDRD |= 0xFF;
		}
		else if (Copy_uint8State == INPUT_WITHOUT_PULLIP)
		{
			DDRD |= 0x00;
		}
		else if (Copy_uint8State == INPUT_WITH_PULLUP)
		{
			DDRD |= 0x00;
			PORTD |= 0xFF;
		}
	}
}
uint8 DIO_uint8GetPinValue		(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum){
	if (Copy_uint8Port == PORT_A)
	{
		return get_Bit(PINA,Copy_uint8PinNum);
	}
	else if (Copy_uint8Port == PORT_B)
	{
		return get_Bit(PINB,Copy_uint8PinNum);
	}
	else if (Copy_uint8Port == PORT_C)
	{
		return get_Bit(PINC,Copy_uint8PinNum);
	}
	else if (Copy_uint8Port == PORT_D)
	{
		return get_Bit(PIND,Copy_uint8PinNum);
	}

}
void  DIO_vTogglePin			(uint8 Copy_uint8Port, uint8 Copy_uint8PinNum){
	if (Copy_uint8Port == PORT_A)
	{
		toggle_Bit(DDRA,Copy_uint8PinNum);
	}
	else if (Copy_uint8Port == PORT_B)
	{
		toggle_Bit(DDRB,Copy_uint8PinNum);
	}
	else if (Copy_uint8Port == PORT_C)
	{
		toggle_Bit(DDRC,Copy_uint8PinNum);
	}
	else if (Copy_uint8Port == PORT_D)
	{
		toggle_Bit(DDRD,Copy_uint8PinNum);
	}
}
void  DIO_vWritePortValue		(uint8 Copy_uint8Port, uint8 Copy_uint8Value){
	if (Copy_uint8Port == PORT_A)
	{
		PORTA |= Copy_uint8Value;
	}
	else if (Copy_uint8Port == PORT_B)
	{
		PORTB |= Copy_uint8Value;
	}
	else if (Copy_uint8Port == PORT_C)
	{
		PORTC |= Copy_uint8Value;
	}
	else if (Copy_uint8Port == PORT_D)
	{
		PORTD |= Copy_uint8Value;
	}
}
uint8 DIO_uint8GetPortValue		(uint8 Copy_uint8Port){
	if (Copy_uint8Port == PORT_A)
	{
		return (PINA &= 0xFF);
	}
	else if (Copy_uint8Port == PORT_B)
	{
		return (PINB & 0xFF);
	}
	else if (Copy_uint8Port == PORT_C)
	{
		return (PINC & 0xFF);
	}
	else if (Copy_uint8Port == PORT_D)
	{
		return (PIND & 0xFF);
	}
	
}