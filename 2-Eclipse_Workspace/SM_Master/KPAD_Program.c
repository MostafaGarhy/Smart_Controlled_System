/****************************************************/
/* SWC 	  	   : KPAD Driver                        */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 14 AUG 2023                        */
/* Description : interface with KEY PAD	            */
/****************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/* MCAL layer */
#include "DIO_Interface.h"

/* HAL Layer */
#include "KPAD_Interface.h"
#include "KPAD_Private.h"
#include "KPAD_Config.h"

void KPAD_VidInit(void)
{
	DIO_U8SetPortDirection(DIO_PORTA, 0xF0);
	DIO_U8SetPortValue(DIO_PORTA, 0xFF);
}

u8 KPAD_U8GetPressedKey(u8 *Copy_U8Returned)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;
	u8 LocaL_U8KPAD_ARR[ROW_NUMBERS][COLUMN_NUMBERS]= KPAD_ARR;
	u8 Local_U8PinState;

	u8 Local_U8ColIndex,Local_U8CRowIndex;
	u8 KPAD_U8RowsPins[ROW_NUMBERS]={KPAD_ROW_PIN0,KPAD_ROW_PIN1,KPAD_ROW_PIN2,KPAD_ROW_PIN3};
	u8 KPAD_U8ColsPins[COLUMN_NUMBERS]={KPAD_COLUMN_PIN0,KPAD_COLUMN_PIN1,KPAD_COLUMN_PIN2,KPAD_COLUMN_PIN3};

	if(Copy_U8Returned !=NULL)
	{
		*Copy_U8Returned=0xff;
		for(Local_U8ColIndex=0;Local_U8ColIndex <COLUMN_NUMBERS ; Local_U8ColIndex++)
		{
			DIO_U8SetPinValue(KPAD_PORT,KPAD_U8ColsPins[Local_U8ColIndex],DIO_LOW);
			for(Local_U8CRowIndex=0; Local_U8CRowIndex < ROW_NUMBERS ; Local_U8CRowIndex++)
			{
				DIO_U8GetPinValue(KPAD_PORT,KPAD_U8RowsPins[Local_U8CRowIndex],&Local_U8PinState);
				if(Local_U8PinState==DIO_LOW)
					{
						_delay_ms(30);

						/* Polling on the pressed Key */
						while(Local_U8PinState==DIO_LOW)
						{
							DIO_U8GetPinValue(KPAD_PORT,KPAD_U8RowsPins[Local_U8CRowIndex],&Local_U8PinState);
						}
						*Copy_U8Returned=LocaL_U8KPAD_ARR[Local_U8CRowIndex][Local_U8ColIndex];

					}
			}
			DIO_U8SetPinValue(KPAD_PORT,KPAD_U8ColsPins[Local_U8ColIndex],DIO_HIGH);

		}

	}
	else
	{
		Local_U8ErrorState=ERROR_STATE_OK;
	}

return Local_U8ErrorState;

}

