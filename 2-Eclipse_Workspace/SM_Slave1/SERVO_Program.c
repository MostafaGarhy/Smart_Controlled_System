/*
 * SERVO_Program.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Bassem Hussein
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "Timer.h"
#include "SERVO_Interface.h"

u8 SERVO_U8SetServoAngle(s8 Copy_S8Angle)
{
	u8 Local_U8ErrorState = ERROR_STATE_OK;

	if((Copy_S8Angle<= 90  )&&(Copy_S8Angle >= -90))
	{
		if(Copy_S8Angle >=0)
		{
			for(s8 local_S16Counter=0; local_S16Counter<=Copy_S8Angle;local_S16Counter++)
				{
					TIMER_VidCTCTimer1Preload(5.550*local_S16Counter+1500);
					_delay_ms(50);
				}
		}
		else
		{
			for(s8 local_S16Counter=0; local_S16Counter >=Copy_S8Angle;local_S16Counter--) // for negative
				{
					TIMER_VidCTCTimer1Preload(5.569*local_S16Counter+1500);
					_delay_ms(50);
				}
		}


	}
	else
	{
		Local_U8ErrorState = ERROR_STATE_NOK;
	}
	return Local_U8ErrorState;
}
