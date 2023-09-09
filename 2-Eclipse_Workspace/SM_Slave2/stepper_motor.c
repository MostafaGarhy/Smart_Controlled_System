/*
 * stepper_motor.c
 *
 *  Created on: Aug 15, 2023
 *      Author: ma257
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "stepper_motor.h"
#include <util/delay.h>

void HSTEP_VidInit(void)
{
	DIO_U8SetPinDirection(STEP_PORT, STEP_PIN0, DIO_PIN_OUT);
	DIO_U8SetPinDirection(STEP_PORT, STEP_PIN1, DIO_PIN_OUT);
	DIO_U8SetPinDirection(STEP_PORT, STEP_PIN2, DIO_PIN_OUT);
	DIO_U8SetPinDirection(STEP_PORT, STEP_PIN3, DIO_PIN_OUT);
}

u8 HSTEP_U8SetAngDir(u16 Copy_U16Angle, u8 Copy_U8Direction)
{
	u8 Local_U8ErrorState =  ERROR_STATE_OK;
	u16 Local_U16Steps, Local_U16Iterations, Local_U16Counter;
	/* I/P Validation */
	if(Copy_U8Direction > STEP_DIR_ACW || Copy_U16Angle > 360)
	{
		Local_U8ErrorState = ERROR_STATE_NOK;
	}
	else
	{
		//Calculations for Number of Loop Iterations according to the angle
		Local_U16Steps = (Copy_U16Angle * 2048UL)/360;
		Local_U16Iterations = Local_U16Steps / 4;
		switch(Copy_U8Direction)
		{
			case  STEP_DIR_CW: 	//Rotate Clock Wise
								for(Local_U16Counter = 0; Local_U16Counter < Local_U16Iterations; Local_U16Counter++)
								{
									//Full_step_1
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_LOW);
									_delay_ms(10);
									//Full_step_2
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_LOW);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_HIGH);
									_delay_ms(10);
									//Full_step_3
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_LOW);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_HIGH);
									_delay_ms(10);
									//Full_step_4
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_LOW);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_HIGH);
									_delay_ms(10);
								}
								break;

			case STEP_DIR_ACW:	//Rotate Anti-Clock Wise
								for(Local_U16Counter = 0; Local_U16Counter < Local_U16Iterations; Local_U16Counter++)
								{
									//Full_step_1
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_LOW);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_HIGH);
									_delay_ms(10);
									//Full_step_2
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_LOW);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_HIGH);
									_delay_ms(10);
									//Full_step_3
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_LOW);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_HIGH);
									_delay_ms(10);
									//Full_step_4
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN0, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN1, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN2, DIO_HIGH);
									DIO_U8SetPinValue(STEP_PORT, STEP_PIN3, DIO_LOW);
									_delay_ms(10);
								}
								break;

			default:			/* Do Nothing */
								break;
		}
		Local_U8ErrorState = ERROR_STATE_OK;
	}
	return Local_U8ErrorState;
}
