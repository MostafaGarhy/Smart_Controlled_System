
#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "KPAD_Interface.h"
#include "LCD_Interface.h"
#include "Timer.h"
#include "SERVO_Interface.h"
#include "I2C_Interface.h"
#include "Smart_Home_Interface.h"
#include "KPAD_Config.h"
#include "stepper_motor.h"
#include "USART_Interface.h"
#include "Smart_Home_Config.h"

int main()
{

	u8 Local_u8Data;
	s16 returned_num = 0;
	LCD_VoidLCDInit();
	DIO_U8SetPinDirection(DIO_PORTD, DIO_PIN6, DIO_PIN_OUT);
	DIO_U8SetPinDirection(DIO_PORTD, DIO_PIN7, DIO_PIN_OUT);
	DIO_U8SetPortDirection(DIO_PORTC, 0xFF);
	DIO_U8SetPortDirection(DIO_PORTA, 0xFF);
	LCD_VoidGoToRowCol(0, 0);
	LCD_u8WriteString("Welcome Slave");
	SevSeg_VidInit();
	UART_VidInit();
	HSTEP_VidInit();
	I2C_VidSlaveInit(5);

	while(1)
	{
		Local_u8Data = I2C_VidSlaveRecieveData();
		if(Local_u8Data=='2')
		{
			while(Local_u8Data == '2')
			{
				LCD_VoidSendCommand(1);
				LCD_u8WriteString("DC is on CW");
				DIO_U8SetPinValue(DIO_PORTD, DIO_PIN6, DIO_LOW);
				DIO_U8SetPinValue(DIO_PORTD, DIO_PIN7, DIO_HIGH);
				Local_u8Data = I2C_VidSlaveRecieveData();
			}
		}
		else if(Local_u8Data == '1')
		{
			while(Local_u8Data == '1')
			{
				LCD_VoidSendCommand(1);
				LCD_u8WriteString("DC is on ACW");
				DIO_U8SetPinValue(DIO_PORTD, DIO_PIN6, DIO_HIGH);
				DIO_U8SetPinValue(DIO_PORTD, DIO_PIN7, DIO_LOW);
				Local_u8Data = I2C_VidSlaveRecieveData();
			}
		}
		else if(Local_u8Data == '3')
		{
			while(Local_u8Data == '3')
			{
				LCD_VoidSendCommand(1);
				LCD_u8WriteString("DC is Off");
				DIO_U8SetPinValue(DIO_PORTD, DIO_PIN6, DIO_LOW);
				DIO_U8SetPinValue(DIO_PORTD, DIO_PIN7, DIO_LOW);
				Local_u8Data = I2C_VidSlaveRecieveData();
			}
		}
		else if(Local_u8Data == '0')
		{
			while(Local_u8Data == '0')
			{
				LCD_VoidSendCommand(1);
				LCD_u8WriteString("Seven Seg is On");
				SevSeg_VidDispTrafficLights(DISPLAY_SEGMENT_PORT, 99);
				Local_u8Data = I2C_VidSlaveRecieveData();
			}
		}
		else if(Local_u8Data == '4')
		{
			returned_num = UART_VidReceiveData();
			while(Local_u8Data == '4')
			{
				LCD_VoidSendCommand(1);
				LCD_VoidGoToRowCol(0, 0);
				LCD_u8WriteString("Stepper is On CW:");
				LCD_VoidGoToRowCol(1, 0);
		        HSTEP_U8SetAngDir(returned_num, 0);
		        Local_u8Data = I2C_VidSlaveRecieveData();
			}
		}
		else if(Local_u8Data == '5')
		{
			returned_num = UART_VidReceiveData();
			while(Local_u8Data == '5')
			{
				LCD_VoidSendCommand(1);
				LCD_VoidGoToRowCol(0, 0);
				LCD_u8WriteString("Stepper is On ACW:");
				LCD_VoidGoToRowCol(1, 0);
		        HSTEP_U8SetAngDir(returned_num, 0);
		        Local_u8Data = I2C_VidSlaveRecieveData();
			}
		}
	}
	return 0;

}

