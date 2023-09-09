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

void LCD_VoidSendCommand(u8 Copy_U8Command)
{
#if LCD_MODE == LCD_8BIT_MODE
	/* Set RS -> Low  --> to send Command*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,DIO_LOW);

	/* Set RW -> Low  --> to Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,DIO_LOW);

	/* Send the Command to Data Port */
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_U8Command);

	/*Enable sequence to send command*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_HIGH);
	_delay_ms(2);
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_LOW);
#elif LCD_MODE == LCD_4BIT_MODE
	/* Set RS -> Low  --> to send Command*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,DIO_LOW);

	/* Set RW -> Low  --> to Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,DIO_LOW);

	/* Send the Command to Data Port */
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_U8Command);
	/*Enable sequence to send command*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_HIGH);
	_delay_us(1);
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_LOW);
	_delay_us(200);
	/* Write On Command Least Lower Nibble */
	DIO_U8SetPortValue(LCD_DATA_PORT,(Copy_U8Command << 4));
	/*Enable sequence to send command*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_HIGH);
	_delay_us(1);
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_LOW);
	_delay_ms(2);
#endif
}

void LCD_VoidLCDInit(void)
{
#if LCD_MODE == LCD_8BIT_MODE
	/* Set Direction Data PORT -> High */
	DIO_U8SetPortDirection(LCD_DATA_PORT,DIO_PORT_OUT);

	/* Set Direction Control PORT ( E,RS,RW ) -> High */
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_E,HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_RS,HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT,CONTROL_RW,HIGH);

	_delay_ms(40);
	/*LCD Send Function Set */
	LCD_VoidSendCommand(LCD_FUN_SET);

	/*LCD Send Display on of */
	LCD_VoidSendCommand(LCD_DISPLAY_ON_OFF);

	/* clear Display */
	LCD_VoidSendCommand(LCD_CLEAR);
#elif LCD_MODE == LCD_4BIT_MODE
	/* Set Direction Data PORT -> High */
	DIO_U8SetPortDirection(LCD_DATA_PORT, 0xF0);

	/* Set Direction Control PORT ( E,RS,RW ) -> High */
	DIO_U8SetPinDirection(LCD_CONTROL_PORT, CONTROL_E, HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT, CONTROL_RS, HIGH);
	DIO_U8SetPinDirection(LCD_CONTROL_PORT, CONTROL_RW, HIGH);
	/* LCD Power ON delay always >15ms */
	_delay_ms(35);
	LCD_VoidSendCommand(0x33);
	/* send for 4 bit initialization of LCD  */
	LCD_VoidSendCommand(0x32);
	/* Use 2 line and initialize 5*7 matrix in (4-bit mode)*/
	LCD_VoidSendCommand(0x28);
	/* Display on cursor off */
	LCD_VoidSendCommand(0x0c);
	/* Increment cursor (shift cursor to right) */
	LCD_VoidSendCommand(0x06);
	/* Clear display screen*/
	LCD_VoidSendCommand(0x01);
	_delay_ms(2);
	LCD_VoidSendCommand (0x80);
	/* End Of Init */
#endif
}

void LCD_VoidSendData(u8 Copy_U8Data)
{
#if LCD_MODE == LCD_8BIT_MODE
	/* Set RS -> High  --> to send data*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,DIO_HIGH);

	/* Set RW -> Low  --> to Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,DIO_LOW);

	/* Send the data to Data Port */
	DIO_U8SetPortValue(LCD_DATA_PORT,Copy_U8Data);

	/*Enable sequence to send data*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_HIGH);
	_delay_ms(2);
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_LOW);
#elif LCD_MODE == LCD_4BIT_MODE
	/* Set RS -> High  --> to send data*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RS,DIO_HIGH);

	/* Set RW -> Low  --> to Write*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_RW,DIO_LOW);
	/* Write On Char */
	DIO_U8SetPortValue(LCD_DATA_PORT, Copy_U8Data);
	/*Enable sequence to send command*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_HIGH);
	_delay_us(1);
	DIO_U8SetPinValue(LCD_CONTROL_PORT,CONTROL_E,DIO_LOW);
	_delay_us(200);
	/* Write On Char Least Signifit */
	DIO_U8SetPortValue(LCD_DATA_PORT, (Copy_U8Data << 4));
	/*Enable sequence to send command*/
	DIO_U8SetPinValue(LCD_CONTROL_PORT, CONTROL_E, DIO_HIGH);
	_delay_us(1);
	DIO_U8SetPinValue(LCD_CONTROL_PORT, CONTROL_E, DIO_LOW);
	_delay_ms(2);
#endif
}
void LCD_VoidSendString(u8 *Copy_U8String)
{
	static u8 i=0;
	while(Copy_U8String[i] != '\0')
	{
		LCD_VoidSendData(Copy_U8String[i]);
		i++;
	}


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

    while (Copy_s32Number > LOW)
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

