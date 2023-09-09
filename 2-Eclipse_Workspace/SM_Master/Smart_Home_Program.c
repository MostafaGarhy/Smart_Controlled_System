/*
 * Smart_Home_Program.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Bassem Hussein
 */
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
#include "USART_Interface.h"
static s16 mine = 0;

void SM_VoidServo_APP(void)
{
    static s8 isNegative = 1;
    u8 Pressed_Key;
	while(1)
	{


  serv:  KPAD_U8GetPressedKey(&Pressed_Key);

    if ((Pressed_Key >= '0') && (Pressed_Key <= '9')) {
        LCD_VoidSendData(Pressed_Key);
        u8 angle = Pressed_Key - '0';
        mine = mine * 10 + angle;
    }
    else if (Pressed_Key == '-')
     {
    	isNegative =-1;
    	LCD_VoidSendData('-');
     }
    else if (Pressed_Key == '=')
    {
        if(isNegative == -1)
        {
        	mine = -mine;
        }
        if((mine <=90) &&(mine >= -90))
        {
        LCD_VoidSendCommand(1);
        _delay_ms(500);
        LCD_u8WriteString("YOUR ANGLE= ");

        LCD_VoidSendNumber(mine);
        _delay_ms(500);
        LCD_VoidGoToRowCol(1,1);
        SERVO_U8SetServoAngle(mine);
        mine =0;
        LCD_VoidSendCommand(1);
        _delay_ms(300);
        LCD_u8WriteString("CHOOSE ANGLE: ");
        goto serv;
        }
        else
        {                  // for range 90 : - 90
        	 LCD_VoidSendCommand(1);
        	  _delay_ms(500);
        	 LCD_u8WriteString("WRONG CHOICE");
        	 _delay_ms(400);
        	 LCD_VoidGoToRowCol(1,0);
        	 LCD_u8WriteString("RANGE -90:90");
        	 _delay_ms(300);
        	  mine =0;
			 _delay_ms(500);
			 LCD_VoidSendCommand(1);
			 LCD_u8WriteString("CHOOSE ANGLE: ");
			 goto serv;
        }
    }
    else if (Pressed_Key == 'c')
    {  // if clear
        LCD_VoidSendCommand(1);
        mine = 0;
        isNegative = 0;
        break;

    }
	}

}

	static u8 Select=0;
	u8 SM_U8LoginSys(void)
	 {
		static u8 Local_U8ErrorState = ERROR_STATE_NOK;
		static u16 User_Pass=0;
	lable:	LCD_u8WriteString("USER NUMBER = ");

		_delay_ms(700);


		while(1)
		{
		KPAD_U8GetPressedKey(&Select);

		if((Select !=255) &&(Select != '='))
		{

			if((Select != 'c'))
			{
				LCD_VoidSendData(Select);
			}


			switch(Select)
			{
				case '0':
				{
					LCD_VoidGoToRowCol(1,0);
					LCD_u8WriteString("WELCOME USER_0");

					_delay_ms(1000);
					LCD_VoidSendCommand(1);
					for(u8 i=0;i<3;i++)
					{
						LCD_u8WriteString("ENTER YOUR PASS");
						_delay_ms(700);
						LCD_VoidGoToRowCol(1,0);
						User_Pass= SM_U16EnterPassword();
						if(User_Pass ==1111)
						{

							LCD_u8WriteString("WELCOME ALI");
							Local_U8ErrorState = ERROR_STATE_OK;
							 return Local_U8ErrorState;
						}
						else
						{
							LCD_u8WriteString("INCORRECT PASS");
							LCD_VoidGoToRowCol(1,0);
							LCD_u8WriteString("TRY AGAIN");
							_delay_ms(700);
							LCD_VoidSendCommand(1);
							if(i==2)
							{
							LCD_VoidGoToRowCol(1,0);
							LCD_u8WriteString("U entered 3 times");
							DIO_U8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_HIGH);
							DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_HIGH);
							_delay_ms(500);
							DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_LOW);
							Local_U8ErrorState = ERROR_STATE_NOK;
							 return Local_U8ErrorState;
							}
						}
					}
				} break;
				case '1':
				{
					LCD_VoidGoToRowCol(1,0);
					LCD_u8WriteString("WELCOME USER_1");

					_delay_ms(1000);
					LCD_VoidSendCommand(1);
						for(u8 i=0;i<3;i++)
					{

						LCD_u8WriteString("ENTER YOUR PASS");
						_delay_ms(700);
						LCD_VoidGoToRowCol(1,0);
						User_Pass= SM_U16EnterPassword();
						if(User_Pass ==2222)
						{

							LCD_u8WriteString("WELCOME ALAA");
							Local_U8ErrorState = ERROR_STATE_OK;
							 return Local_U8ErrorState;
						}
						else
						{
							LCD_u8WriteString("INCORRECT PASS");
							LCD_VoidGoToRowCol(1,0);
							LCD_u8WriteString("TRY AGAIN");
							_delay_ms(700);
							LCD_VoidSendCommand(1);
							if(i==2)
							{
								LCD_VoidGoToRowCol(1,0);
								LCD_u8WriteString("U entered 3 times");

							DIO_U8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_HIGH);
							DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_HIGH);
							_delay_ms(500);
							DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_LOW);
								Local_U8ErrorState = ERROR_STATE_NOK;
								 return Local_U8ErrorState;

							}
						}
					}
				} break;
				case '2':
				{
					LCD_VoidGoToRowCol(1,0);
					LCD_u8WriteString("WELCOME USER_2");

					_delay_ms(1000);
					LCD_VoidSendCommand(1);
						for(u8 i=0;i<3;i++)
					{

						LCD_u8WriteString("ENTER YOUR PASS");
						_delay_ms(700);
						LCD_VoidGoToRowCol(1,0);
						User_Pass= SM_U16EnterPassword();
						if(User_Pass ==3333)
						{

							LCD_u8WriteString("WELCOME MAI");

							Local_U8ErrorState = ERROR_STATE_OK;
							 return Local_U8ErrorState;

						}
						else
						{
							LCD_u8WriteString("INCORRECT PASS");
							LCD_VoidGoToRowCol(1,0);
							LCD_u8WriteString("TRY AGAIN");
							_delay_ms(700);
							LCD_VoidSendCommand(1);
							if(i==2)
							{
								LCD_VoidGoToRowCol(1,0);
								LCD_u8WriteString("U entered 3 times");
								DIO_U8SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_HIGH);
								DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_HIGH);
								_delay_ms(500);
								DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_LOW);
								Local_U8ErrorState = ERROR_STATE_NOK;
								 return Local_U8ErrorState;
							}
						}
					}
				} break;

				case 'c':
				{
					_delay_ms(50);
					LCD_VoidSendCommand(1);
				} break;
				default :
					LCD_VoidSendCommand(1);

					LCD_u8WriteString("INVALID USER");
					_delay_ms(700);
					LCD_VoidSendCommand(1);
					goto lable;
					break;
			}
		}
		}

		  return Local_U8ErrorState;

	 }


	u16 SM_U16EnterPassword(void)
	 {
		static u8 Local_U8EnteredPass =0;
		 u16 Returned_Password=0;
		while(1)
		{

		 KPAD_U8GetPressedKey(&Local_U8EnteredPass);

			if ((Local_U8EnteredPass >= '0') && (Local_U8EnteredPass <= '9')) {
				LCD_VoidSendData('*');
				u8 pass = Local_U8EnteredPass - '0';
				Returned_Password = Returned_Password * 10 + pass;
			}
			else if (Local_U8EnteredPass == '=')
			{
				LCD_VoidSendCommand(1);
				break;

			}
			else if (Local_U8EnteredPass == 'c')
			{
				LCD_VoidSendCommand(1);
				Returned_Password=0;
			}
		}

		 return Returned_Password;
	 }

void SM_VoidDCMotor(void)
{
    u8 Pressed_Key;
	LCD_VoidSendCommand(1);
	LCD_VoidGoToRowCol(0, 0);
	LCD_u8WriteString("1-Clock Wise 2-Anti-CW");
	LCD_VoidGoToRowCol(1, 0);
	LCD_u8WriteString("3-Stop  4-Return");
	while(1)
	{
	    KPAD_U8GetPressedKey(&Pressed_Key);
	    if((Pressed_Key >= '1') && (Pressed_Key <= '3'))
	    {
	    	switch(Pressed_Key)
			{
	    		case '1':  	/* Send Data to Slave_2 */
							I2C_VidStartCondition();
							I2C_VidSlaveAddressWrite(5);
							I2C_VidMastarSendData('2');   /* send 1 and wait 500ms then send 2 and will check for that in slave */
							I2C_VidStopCondition();
							_delay_ms(500);
							break;
	    		case '2':   /* Send Data to Slave_2 */
							I2C_VidStartCondition();
							I2C_VidSlaveAddressWrite(5);
							I2C_VidMastarSendData('1');   /* send 1 and wait 500ms then send 2 and will check for that in slave */
							I2C_VidStopCondition();
							_delay_ms(500);
							break;
	    		case '3':   /* Send Data to Slave_2 */
							I2C_VidStartCondition();
							I2C_VidSlaveAddressWrite(5);
							I2C_VidMastarSendData('3');   /* send 1 and wait 500ms then send 2 and will check for that in slave */
							I2C_VidStopCondition();
							_delay_ms(500);
							break;
			}
	    }
	    else if(Pressed_Key == '4')
	    {
	    	break;
	    }
	}
}

void SM_VoidStepper(void)
{
    u8 Pressed_Key;
    s16 num = 0;

    Stepper:
	LCD_VoidSendCommand(1);
	LCD_VoidGoToRowCol(0, 0);
	LCD_u8WriteString("1-Clock Wise  2-Anti-CW");
	LCD_VoidGoToRowCol(1,0);
	LCD_u8WriteString("3-Return");
	while(1)
	{
	    KPAD_U8GetPressedKey(&Pressed_Key);
	    if((Pressed_Key >= '1') && (Pressed_Key <= '2'))
	    {
	    	switch(Pressed_Key)
	    	{
	    		case '1':   //CW
							LCD_VoidSendCommand(1);
							LCD_VoidGoToRowCol(0, 0);
							LCD_u8WriteString("Choose Angle:0 ->360");
							LCD_VoidGoToRowCol(1, 0);
							while(1)
							{
								KPAD_U8GetPressedKey(&Pressed_Key);
								if((Pressed_Key >= '0') && (Pressed_Key <= '9') && num <= 360 )
								{
									LCD_VoidSendData(Pressed_Key);
									num =  num * 10 + (Pressed_Key - '0');

								}
								else if(Pressed_Key == '=')
								{
									UART_VoidSendNumber(num);
									break;
								}
							}
							/* Start the Stepper (Send Data to Slave_2) */
							I2C_VidStartCondition();
							I2C_VidSlaveAddressWrite(5);
							I2C_VidMastarSendData('4');   /* send 1 and wait 500ms then send 2 and will check for that in slave */
							I2C_VidStopCondition();
							_delay_ms(500);
							goto Stepper;
							break;
	    		case '2':	//ACW
							LCD_VoidSendCommand(1);
							LCD_VoidGoToRowCol(0, 0);
							LCD_u8WriteString("Choose Angle:0 ->360");
							LCD_VoidGoToRowCol(1, 0);
							while(1)
							{
								KPAD_U8GetPressedKey(&Pressed_Key);
								if((Pressed_Key >= '0') && (Pressed_Key <= '9') && num <= 360 )
								{
									LCD_VoidSendData(Pressed_Key);
									num =  num * 10 + (Pressed_Key - '0');

								}
								else if(Pressed_Key == '=')
								{
									UART_VoidSendNumber(num);
									break;
								}
							}
							/* Start the Stepper (Send Data to Slave_2) */
							I2C_VidStartCondition();
							I2C_VidSlaveAddressWrite(5);
							I2C_VidMastarSendData('5');   /* send 1 and wait 500ms then send 2 and will check for that in slave */
							I2C_VidStopCondition();
							_delay_ms(500);
							goto Stepper;
							break;
	    	}
	    }
	    else if(Pressed_Key == '3')
	    {
	    		break;
	    }
	}
}

void Turn_Led(void)
{
	static u8 Led_Flag=0;
	DIO_U8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUT);
LED:	LCD_u8WriteString("1-Turn On   2- Turn OFF");
	LCD_VoidGoToRowCol(1,0);
	LCD_u8WriteString("3-Return");
	static u8 Pressed;
	while(1)
		{
			KPAD_U8GetPressedKey(&Pressed);
			if((Pressed >='1') && (Pressed <='6'))
			{
				switch(Pressed)
				{
					case '1':
						LCD_VoidSendCommand(1);
						LCD_u8WriteString("Led is ON ");
						DIO_U8SetPinValue(DIO_PORTB,DIO_PIN0,HIGH);
						_delay_ms(500);
						LCD_VoidSendCommand(1);
						goto LED;
						break;
					case '2':
						LCD_VoidSendCommand(1);
						LCD_u8WriteString("Led is OFF ");
						DIO_U8SetPinValue(DIO_PORTB,DIO_PIN0,LOW);
						_delay_ms(500);
						LCD_VoidSendCommand(1);
						goto LED;
						break;
					case '3':
						LCD_VoidSendCommand(1);
						Led_Flag=1;
						break;

				}
			}
			if(Led_Flag==1)
			{
				Led_Flag=0;
				break;
			}

		}
}

u8 SM_U8RoomSelect(void)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;

	static u8 Pressed;

	Select: /* Select Room */
	LCD_VoidSendCommand(1);
	LCD_VoidGoToRowCol(0,0);
	LCD_u8WriteString("Select Room");
	_delay_ms(800);
	LCD_VoidSendCommand(1);
	LCD_VoidGoToRowCol(0,0);
	LCD_u8WriteString("1-Servo 2-DC  3-led");
	LCD_VoidGoToRowCol(1,0);
	LCD_u8WriteString("4-Calc  5-TL  6-SM");


	while(1)
	{
		KPAD_U8GetPressedKey(&Pressed);
		if((Pressed >='1') && (Pressed <='6'))
		{
			switch(Pressed)
			{
				case '1':
				LCD_VoidSendCommand(1);
				LCD_u8WriteString("CHOOSE ANGLE: ");
				SM_VoidServo_APP();
				goto Select;
				break;
				case '2':
							LCD_VoidSendCommand(1);
							LCD_u8WriteString("DC Motor is On");
							_delay_ms(300);
							SM_VoidDCMotor();
							goto Select;
							break;
				case '3':
							LCD_VoidSendCommand(1);
							LCD_u8WriteString("Control Led ");
							_delay_ms(300);
							LCD_VoidSendCommand(1);
							Turn_Led();
							goto Select;
							break;

				case '4':
							LCD_VoidSendCommand(1);
							LCD_u8WriteString("welcome in Calc: ");
							_delay_ms(500);
							LCD_VoidSendCommand(1);

							I2C_VidStartCondition();
							I2C_VidSlaveAddressWrite(3);
							I2C_VidMastarSendData('1');   /* send 1 and wait 500ms then send 2 and will check for that in slave */
							I2C_VidStopCondition();
							_delay_ms(500);
							goto Select;
							break;
				case '5':
							LCD_VoidSendCommand(1);
							LCD_VoidGoToRowCol(0, 0);
							LCD_u8WriteString("Seven Segment is On");
							/* Send Data to Slave_1 address: 5 */
					    	I2C_VidStartCondition();
					    	I2C_VidSlaveAddressWrite(5);
					    	I2C_VidMastarSendData('0');
					    	I2C_VidStopCondition();
					    	goto Select;
					    	break;
				case '6':
							LCD_VoidSendCommand(1);
							LCD_u8WriteString("Stepper Motor is On");
							_delay_ms(300);
							SM_VoidStepper();
							goto Select;
							break;

			}
		}

	}


	return Local_U8ErrorState;
}

