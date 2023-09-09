/****************************************************/
/* SWC 	  	   : DIO Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 9 AUG 2023                         */
/* Description : Digital Input Outpot driver        */
/****************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL layer */
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

u8 DIO_U8SetPinDirection(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb,u8 Copy_U8Directon)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	if((Copy_U8PortNumb <= DIO_PORTD) && (Copy_U8PinNumb <= DIO_PIN7) &&(Copy_U8Directon <= DIO_PIN_OUT))
	{
		switch(Copy_U8Directon)
		{
			case DIO_PIN_OUT:
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: SET_BIT(DDRA,Copy_U8PinNumb);break;
				case DIO_PORTB: SET_BIT(DDRB,Copy_U8PinNumb);break;
				case DIO_PORTC: SET_BIT(DDRC,Copy_U8PinNumb);break;
				case DIO_PORTD: SET_BIT(DDRD,Copy_U8PinNumb);break;
			}
			break;
			case DIO_PIN_IN:
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: CLR_BIT(DDRA,Copy_U8PinNumb);break;
				case DIO_PORTB: CLR_BIT(DDRB,Copy_U8PinNumb);break;
				case DIO_PORTC: CLR_BIT(DDRC,Copy_U8PinNumb);break;
				case DIO_PORTD: CLR_BIT(DDRD,Copy_U8PinNumb);break;
			}
			break;
			
		}
	}
	else
	{
		 Local_U8ErrorState=ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}

u8 DIO_U8SetPinValue(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb,u8 Copy_U8Value)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	if((Copy_U8PortNumb <= DIO_PORTD) && (Copy_U8PinNumb <= DIO_PIN7) &&(Copy_U8Value <= DIO_HIGH))
	{
		switch(Copy_U8Value)
		{
			case DIO_HIGH:
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: SET_BIT(PORTA,Copy_U8PinNumb);break;
				case DIO_PORTB: SET_BIT(PORTB,Copy_U8PinNumb);break;
				case DIO_PORTC: SET_BIT(PORTC,Copy_U8PinNumb);break;
				case DIO_PORTD: SET_BIT(PORTD,Copy_U8PinNumb);break;
			}
			break;
			case DIO_LOW:
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: CLR_BIT(PORTA,Copy_U8PinNumb);break;
				case DIO_PORTB: CLR_BIT(PORTB,Copy_U8PinNumb);break;
				case DIO_PORTC: CLR_BIT(PORTC,Copy_U8PinNumb);break;
				case DIO_PORTD: CLR_BIT(PORTD,Copy_U8PinNumb);break;
			}
			break;
			default:
			Local_U8ErrorState=ERROR_STATE_OK;
			break;	
		}
	}
	else
	{
		 Local_U8ErrorState=ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}

u8 DIO_U8GetPinValue(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb,u8 *Copy_U8Value)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	if((Copy_U8PortNumb <= DIO_PORTD) && (Copy_U8PinNumb <= DIO_PIN7))
	{
		switch(Copy_U8PortNumb)
		{	
			case DIO_PORTA: *Copy_U8Value = GET_BIT(PINA,Copy_U8PinNumb); break;
			case DIO_PORTB: *Copy_U8Value = GET_BIT(PINB,Copy_U8PinNumb); break;
			case DIO_PORTC:	*Copy_U8Value = GET_BIT(PINC,Copy_U8PinNumb); break;
			case DIO_PORTD: *Copy_U8Value = GET_BIT(PIND,Copy_U8PinNumb); break;
			default:
			Local_U8ErrorState=ERROR_STATE_OK;
			break;
		}
	}
	else
	{
		 Local_U8ErrorState=ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}

u8 DIO_U8TogglePin(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	if((Copy_U8PortNumb <= DIO_PORTD) && (Copy_U8PinNumb <= DIO_PIN7))
	{
		switch(Copy_U8PortNumb)
		{	
			case DIO_PORTA: TOG_BIT(PORTA,Copy_U8PinNumb); break;
			case DIO_PORTB: TOG_BIT(PORTB,Copy_U8PinNumb); break;
			case DIO_PORTC: TOG_BIT(PORTC,Copy_U8PinNumb); break;
			case DIO_PORTD: TOG_BIT(PORTD,Copy_U8PinNumb); break;
			default:
			Local_U8ErrorState=ERROR_STATE_OK;
			break;		
		}
	}
	else
	{
		 Local_U8ErrorState=ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}

u8 DIO_U8SetPortDirection(u8 Copy_U8PortNumb,u8 Copy_U8Directon)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	if((Copy_U8PortNumb <= DIO_PORTD) && (Copy_U8Directon <=DIO_PORT_OUT))
	{
		if(Copy_U8Directon == DIO_PORT_OUT)
		{
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: DDRA=DIO_PORT_OUT; break;
				case DIO_PORTB: DDRB=DIO_PORT_OUT; break;
				case DIO_PORTC: DDRC=DIO_PORT_OUT; break;
				case DIO_PORTD: DDRD=DIO_PORT_OUT; break;
				default:
				Local_U8ErrorState=ERROR_STATE_OK;
				break;	
			}
		}
		else if(Copy_U8Directon == DIO_PORT_IN)
		{
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: DDRA=DIO_PORT_IN; break;
				case DIO_PORTB: DDRB=DIO_PORT_IN; break;
				case DIO_PORTC: DDRC=DIO_PORT_IN; break;
				case DIO_PORTD: DDRD=DIO_PORT_IN; break;
				default:
				Local_U8ErrorState=ERROR_STATE_OK;
				break;	
			}
		}
		else
		{
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: DDRA=Copy_U8Directon; break;
				case DIO_PORTB: DDRB=Copy_U8Directon; break;
				case DIO_PORTC: DDRC=Copy_U8Directon; break;
				case DIO_PORTD: DDRD=Copy_U8Directon; break;
				default:
				Local_U8ErrorState=ERROR_STATE_OK;
				break;	
			}
		}
	}
	else
	{
		 Local_U8ErrorState=ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}

u8 DIO_U8SetPortValue(u8 Copy_U8PortNumb,u8 Copy_U8Value)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	if((Copy_U8PortNumb <= DIO_PORTD) && (Copy_U8Value <=DIO_PORT_HIGH))
	{
		if(Copy_U8Value == DIO_PORT_HIGH)
		{
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA:  PORTA=DIO_PORT_HIGH; break;
				case DIO_PORTB: PORTB=DIO_PORT_HIGH; break;
				case DIO_PORTC: PORTC=DIO_PORT_HIGH; break;
				case DIO_PORTD: PORTD=DIO_PORT_HIGH; break;
				default:
				Local_U8ErrorState=ERROR_STATE_OK;
				break;	
			}
		}
		else if(Copy_U8Value == DIO_PORT_IN)
		{
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: PORTA=DIO_PORT_LOW; break;
				case DIO_PORTB: PORTB=DIO_PORT_LOW; break;
				case DIO_PORTC: PORTC=DIO_PORT_LOW; break;
				case DIO_PORTD: PORTD=DIO_PORT_LOW; break;
				default:
				Local_U8ErrorState=ERROR_STATE_OK;
				break;	
			}
		}
		else
		{
			switch(Copy_U8PortNumb)
			{
				case DIO_PORTA: PORTA=Copy_U8Value; break;
				case DIO_PORTB: PORTB=Copy_U8Value; break;
				case DIO_PORTC: PORTC=Copy_U8Value; break;
				case DIO_PORTD: PORTD=Copy_U8Value; break;
				default:
				Local_U8ErrorState=ERROR_STATE_OK;
				break;	
			}
		}
		
	}
	else
	{
		 Local_U8ErrorState=ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}

u8 DIO_U8GetPortValue(u8 Copy_U8PortNumb,u8 *Copy_U8Value)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	if((Copy_U8PortNumb <= DIO_PORTD))
	{
		switch(Copy_U8PortNumb)
		{
			case DIO_PORTA: *Copy_U8Value=PINA; break;
			case DIO_PORTB: *Copy_U8Value=PINB;; break;
			case DIO_PORTC: *Copy_U8Value=PINC;; break;
			case DIO_PORTD: *Copy_U8Value=PIND;; break;
			default:
			Local_U8ErrorState=ERROR_STATE_OK;
			break;	
		}
	}
	else
	{
		 Local_U8ErrorState=ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}
