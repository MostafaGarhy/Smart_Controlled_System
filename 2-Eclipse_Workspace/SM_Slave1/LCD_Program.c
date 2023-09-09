/****************************************************/
/* SWC 	  	   : LCD Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 13 AUG 2023                        */
/* Description : char LCD				            */
/****************************************************/

/* Lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/* MCAL layer */
#include "DIO_Interface.h"
/* HAL Layer */
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

void LCD_VoidLCDInit(void)
{
#if LCD_PINS_MODE==LCD_8BIT_MODE
	/* Set Direction Data PORT -> High */
	DIO_U8SetPortDirection(LCD_DATA_PORT,DIO_PORT_OUT);

	/* Set Direction Control PORT ( E,RS,RW ) -> High */
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_RS,HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_RW,HIGH);
	_delay_ms(32);
	/*Send the Function Set >> 2 lines and font size 5*7 */
	LCD_VoidSendCommand(FUN_SET);
	_delay_us(40);
	/*SET the the DISPLAY_ON_OFF Command*/
	LCD_VoidSendCommand(DISPLAY_ON_OFF);
	_delay_us(40);
	/*SET the the DISPLAY_CLEAR Command*/
	LCD_VoidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);
	/*SET the the ENTRY_SET_MODE Command*/
	LCD_VoidSendCommand(ENTRY_MODE_SET);
#elif LCD_PINS_MODE==LCD_4BIT_MODE
	/* Set Direction Data PORT -> High */
	DIO_U8SetPortDirection(LCD_DATA_PORT,DIO_PORT_OUT);

	/* Set Direction Control PORT ( E,RS,RW ) -> High */
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_RS,HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_RW,HIGH);
	_delay_ms(32);
	/*Send the Function Set >> 2 lines and font size 5*7 */
	LCD_VoidSendCommand(FUN_SET1);
	LCD_VoidSendCommand(FUN_SET2);
	LCD_VoidSendCommand(FUN_SET3);
	_delay_us(40);
	/*SET the the DISPLAY_ON_OFF Command*/
	LCD_VoidSendCommand(DISPLAY_ON_OFF);
	_delay_us(40);
	/*SET the the DISPLAY_CLEAR Command*/
	LCD_VoidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);
	/*SET the the ENTRY_SET_MODE Command*/
	LCD_VoidSendCommand(ENTRY_MODE_SET);

#endif
}
void LCD_VoidSendCommand(u8 Copy_U8Command)
{
#if LCD_PINS_MODE==LCD_8BIT_MODE
	/* clear the RS Pin*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,LOW);
	/* Clear the R/W PIN >>> Selects Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,LOW);
	/* Send Command */
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_U8Command);
	/* SET Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	/* Set the Tw the time width of the enable min_Value is 230ns >> Setting 1microS */
	/*NOTE : >>>>>> Delay can't be float value  */
	_delay_us(1);
	/* Clear Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,LOW);

#elif LCD_PINS_MODE==LCD_4BIT_MODE

  /* clear the RS Pin*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,LOW);
	/* Clear the R/W PIN >>> Selects Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,LOW);
	/* Send Command the first high 4bits*/
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_U8Command);
	/* SET Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	/* Set the Tw the time width of the enable min_Value is 230ns >> Setting 1microS */
	/*NOTE : >>>>>> Delay can't be float value  */
	_delay_us(1);
	/* Clear Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,LOW);
	/* Send Command the second high 4bits by shifting the first 4 bits to left*/
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_U8Command<<4);
	/* SET Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	/* Set the Tw the time width of the enable min_Value is 230ns >> Setting 1microS */
	/*NOTE : >>>>>> Delay can't be float value  */
	_delay_us(1);
	/* Clear Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,LOW);

#endif
}
void LCD_VoidSendData(u8 Copy_u8Char)
{
#if LCD_PINS_MODE==LCD_8BIT_MODE
	/* SET the RS Pin*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,HIGH);
	/* Clear the R/W PIN >>> Selects Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,LOW);
	/* Send char */
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_u8Char);
	/* SET Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	/* Set the Tw the time width of the enable min_Value is 230ns >> Setting 1microS */
	/*NOTE : >>>>>> Delay can't be float value  */
	_delay_us(1);
	/* Clear Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,LOW);

#elif LCD_PINS_MODE==LCD_4BIT_MODE

   /* SET the RS Pin*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,HIGH);
	/* Clear the R/W PIN >>> Selects Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,LOW);
	/* Send the highest 4 bit of the char */
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_u8Char);
	/* SET Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	/* Set the Tw the time width of the enable min_Value is 230ns >> Setting 1microS */
	/*NOTE : >>>>>> Delay can't be float value  */
	_delay_us(1);
	/* Clear Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,LOW);
	/* Send the lowest 4 bit of the char by shifting the highest to left */
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_u8Char<<4);
	/* SET Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	/* Set the Tw the time width of the enable min_Value is 230ns >> Setting 1microS */
	/*NOTE : >>>>>> Delay can't be float value  */
	_delay_us(1);
	/* Clear Enable */
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,LOW);
#endif
}


void LCD_VoidGoToRowCol(u8 Copy_U8Row ,u8 Copy_U8Col)
{
	switch(Copy_U8Row)
	{
		case 0:LCD_VoidSendCommand(0x80+Copy_U8Col);break;
		case 1:LCD_VoidSendCommand(0xc0+Copy_U8Col);break;
	}
}


void LCD_VoidSendNumber(s32 Copy_s32Number)
{
    u8 Local_u8Array[11]; // Increased array size to accommodate negative sign
    s8 Local_counter = 0;

    if (Copy_s32Number < 0)
    {
    	LCD_VoidSendData('-'); // Display negative sign
    	Copy_s32Number = -Copy_s32Number; // Convert negative number to positive for processing
    }
    else if (Copy_s32Number == 0)
    {
    	LCD_VoidSendData('0');
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
    	LCD_VoidSendData(Local_u8Array[Local_counter]);
        Local_counter--;
    }
}
u8 LCD_u8WriteString(u8 *Copy_U8String)
{
	u8 Local_U8ErrorState = ERROR_STATE_OK;
	if(Copy_U8String != NULL)
	{
		while(*Copy_U8String > NULL_STR)
		{
			LCD_VoidSendData(*Copy_U8String++);
		}
	}
	else
	{
		Local_U8ErrorState = ERROR_STATE_NOK;
	}
	return Local_U8ErrorState;
}

