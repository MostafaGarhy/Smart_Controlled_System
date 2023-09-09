/************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                */
/*  Date	:	23	Aug	2023		                                                */
/*  SWC		:	USART Driver			                                            */
/*  File	:	USART_Program.c		                                                */
/*  Version	:	V1.0				                                                */
/*  Desc	:	This API allows user to send/receive a byte 						*/
/* 				and Signed Integer Number using USART Protocol						*/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include <util/delay.h>

void UART_VidInit(void)
{
	//Access UCSRA Once time for simple configurations
	UART_UCSRC_REG = (1<<UCSRC_URSEL_BIT) | (1<<UCSRC_UCSZ0_BIT) | (1<<UCSRC_UCSZ1_BIT);
	UART_UBRRL_REG = 51; 	//9600 Baud rate with 8Mhz Osc.freq to the MCU
	SET_BIT(UART_UCSRB_REG, UCSRB_RXEN_BIT);
	SET_BIT(UART_UCSRB_REG, UCSRB_TXEN_BIT);
}

void UART_VidTransmitData(u8 Copy_U8Data)
{
	//Waiting for the transmit buffer (UDR) is ready to receive new data
	while((GET_BIT(UART_UCSRA_REG, UCSRA_UDRE_BIT)) != 1);

	if((GET_BIT(UART_UCSRA_REG, UCSRA_UDRE_BIT)) == 1)
	{
		//Send Data to UDR register
		UART_UDR_REG = Copy_U8Data;
	}
	else
	{
		UART_UDR_REG = 0xff;
	}
}

u8 UART_VidReceiveData(void)
{
	u8 Local_U8Data;
	//Waiting for the receive buffer (UDR) is ready to transmit new data
	while((GET_BIT(UART_UCSRA_REG, UCSRA_RXC_BIT)) != 1);

	if((GET_BIT(UART_UCSRA_REG, UCSRA_RXC_BIT)) == 1)
	{
		Local_U8Data = UART_UDR_REG;
	}
	else
	{
		Local_U8Data = 0xff;
	}

	return Local_U8Data;
}

void UART_VidTransmitString(u8 *Copy_U8String)
{
	while(*Copy_U8String > NULL_STR)
	{
		UART_VidTransmitData(*Copy_U8String++);
	}
}

void UART_VidTransmitSNumber(s32 Copy_S32Number)
{
	u8 counter = 0;
	u8 number[10];
	//Negative Number
	if(Copy_S32Number < 0)
	{
		UART_VidTransmitData('-');
		Copy_S32Number *= -1;	//make it positive again
	}
	//Zero
	else if(Copy_S32Number == 0)
	{
		UART_VidTransmitData('0');
	}
	//Save Positive or Negative Number
	while(Copy_S32Number > 0)
	{
		number[counter++] = (Copy_S32Number%10) + '0';
		Copy_S32Number /= 10;
	}
	//Display Numbers by transmit array elements reversely
	for(u8 i = counter; i > 0; i--)
	{
		UART_VidTransmitData(number[i-1]);
	}
}

void UART_VidTerminalPrintChar(u8 Copy_U8Character)
{
	UART_VidTransmitString("Enter Char : ");
	Copy_U8Character = UART_VidReceiveData();
	if(Copy_U8Character != 0xff)
	{
		UART_VidTransmitData(Copy_U8Character);
		UART_VidTransmitData('\r');	//Make a new line in the Virtual Terminal
		UART_VidTransmitString("Printed Char : ");
		UART_VidTransmitData(Copy_U8Character);
		UART_VidTransmitData('\r');	//Make a new line in the Virtual Terminal
		UART_VidTransmitData('\r');	//Make a new line in the Virtual Terminal
	}
	_delay_ms(10);	//Delay for reading stability
}

void UART_VoidSendNumber(s32 Copy_s32Number)
{
	   u8 Local_u8Array[11]; // Increased array size to accommodate negative sign
	    s8 Local_counter = 0;

	    if (Copy_s32Number < 0)
	    {
	    	UART_VidTransmitData('-'); // Display negative sign
	    	Copy_s32Number = -Copy_s32Number; // Convert negative number to positive for processing
	    }
	    else if (Copy_s32Number == 0)
	    {
	    	UART_VidTransmitData('0');
	    }

	    while (Copy_s32Number > 0)
	    {
	        Local_u8Array[Local_counter++] = (Copy_s32Number % 10) + 48;
	        Copy_s32Number /= 10;
	    }

	    Local_counter--;

	    // Loop for sending the reverse of the array
	    while (Local_counter >= 0)
	    {
	    	UART_VidTransmitData(Local_u8Array[Local_counter]);
	        Local_counter--;
	    }
}
