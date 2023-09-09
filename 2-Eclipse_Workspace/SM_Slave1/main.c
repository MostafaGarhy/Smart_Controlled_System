
#include "STD_TYPES.h"
#include <util/delay.h>
#include <math.h>
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "KPAD_Interface.h"
#include "LCD_Interface.h"
#include "Timer.h"
#include "SERVO_Interface.h"
#include "I2C_Interface.h"
#include "Smart_Home_Interface.h"
#include "KPAD_Config.h"



int main()
{


		u8 Local_u8Data;
		I2C_VidSlaveInit(3);
		while(1)
		{
			Local_u8Data=I2C_VidSlaveRecieveData();
			if(Local_u8Data=='1')
			{
				while(1)
				{
					SM_VoidCalc();
				}
			}
		}


	return 0;

}


