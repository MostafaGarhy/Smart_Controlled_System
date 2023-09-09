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
#include "Smart_Home_Config.h"
#include "Smart_Home_Interface.h"


static s16 mine = 0;

void SM_VoidServo_APP(void)
{
    static s8 isNegative = 1;
    u8 Pressed_Key;

    KPAD_U8GetPressedKey(&Pressed_Key);

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
        _delay_ms(700);
        LCD_u8WriteString("YOUR ANGLE= ");

        LCD_VoidSendNumber(mine);
        _delay_ms(700);
        LCD_VoidGoToRowCol(1,1);
        SERVO_U8SetServoAngle(mine);
        }
        else
        {                  // for range 90 : - 90
        	 LCD_VoidSendCommand(1);
        	  _delay_ms(700);
        	 LCD_u8WriteString("WRONG CHOICE");
        	 _delay_ms(700);
        	 LCD_VoidGoToRowCol(1,0);
        	 LCD_u8WriteString("RANGE -90:90");

        }
    }
    else if (Pressed_Key == 'c')
    {  // if clear
        LCD_VoidSendCommand(1);
        mine = 0;
        isNegative = 0;
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
								DIO_U8SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_HIGH);
								DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);
								_delay_ms(500);
								DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);
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

								DIO_U8SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_HIGH);
								DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);
								_delay_ms(500);
								DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);
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
								DIO_U8SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_HIGH);
								DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);
								_delay_ms(500);
								DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);
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

u8 SM_U8RoomSelect(void)
{
	u8 Local_U8ErrorState=ERROR_STATE_NOK;

	u8 Pressed=0;
	KPAD_U8GetPressedKey(&Pressed);


	LCD_VoidGoToRowCol(1,0);

	LCD_u8WriteString("Select Room");
	_delay_ms(700);
	LCD_VoidSendCommand(1);

	LCD_u8WriteString("1-Servo 2-DC  3-led");
	LCD_VoidGoToRowCol(1,0);
	LCD_u8WriteString("4-Calc  5-TL  6-SS");
	if((Pressed <='1') && (Pressed <='6'))
	{
		switch(Pressed)
		{
			case '1':SM_VoidServo_APP(); break;
		}
	}



	return Local_U8ErrorState;
}

void SM_VoidCalc(void)
{
	KPAD_Void_INIT();
	u8 ch;



	LCD_VoidLCDInit();

	LCD_u8WriteString("WELCOME In Calc");
		_delay_ms(500);
		LCD_VoidSendCommand(1);

	//LCD_u8WriteString("Hello");
	f32 operand1=0.00, operand2=0.00,result=0.00;
	u8 state=0, negative1=0,negative2=0,op;

	while(1){
	do { KPAD_U8GetPressedKey(&ch); } while(ch==0xff);
	switch(ch)
	{
	case '0': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '1': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '2': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '3': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '4': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '5': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '6': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '7': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '8': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case '9': LCD_VoidSendData(ch); if(state==0|| op==5 || op==8 || op==9|| op==10) {operand1 = ((operand1 * 10) + ch)-48;} else if(state==1){operand2 = ((operand2 * 10) + ch)-48; } break;
	case 'c': LCD_VoidSendCommand(1); operand1=0; operand2=0;result=0;state=0;negative1=0;negative2=0;break;
    case '*':op=1; LCD_VoidSendData(ch); state=1;break;
    case '/':op=2; LCD_VoidSendData(ch); state=1;break;
    case 'I':LCD_VoidSendData('-'); if (state==0){negative1=1;} else if(state==1){negative2=2;}break;
    case '-':op=4; LCD_VoidSendData(ch); state=1;break;
    case 'M':op=5; LCD_VoidSendData('M');LCD_VoidSendData('C');state=1;break;
    case '%':op=6; LCD_VoidSendData(ch); state=1;break;
    case '+':op=7; LCD_VoidSendData(ch); state=1;break;
    case 'N':op=8; LCD_VoidSendData('M');LCD_VoidSendData('-');state=0;break;
    case 'S':op=9; LCD_VoidSendData('S');LCD_VoidSendData('Q');LCD_VoidSendData('R');LCD_VoidSendData('T');state=0;break;
    case '.':LCD_VoidSendData(ch); state=0;break; //.fraction
    case 'P':op=10;LCD_VoidSendData('M');LCD_VoidSendData('+'); state=0;break;
    case '=': LCD_VoidSendData(ch); if (negative1==1){operand1=-operand1;} if (negative2==2){operand2=-operand2;}
    if(op==1){result = (operand1) * (operand2); LCD_VoidSendNumber(result);}
    else if(op==2){result = (operand1) / (operand2); LCD_VoidSendNumber(result);}
    else if(op==4 ){result = (operand1) - (operand2); LCD_VoidSendNumber(result);}
    else if(op==5){LCD_VoidSendNumber(result);}
    else if(op==6){result = (operand1) - ((operand2) * (f32)((int)((operand1) / (operand2)))); LCD_VoidSendNumber(result);}
    else if(op==7){result = (operand1) + (operand2); LCD_VoidSendNumber(result);}
    else if(op==8){result = result-((operand1)); LCD_VoidSendNumber(result);}
    else if(op==9){result = sqrt((operand1)) ;LCD_VoidSendNumber(result);}//fraction
    else if(op==10){result = result+(operand1) ; LCD_VoidSendNumber(result);}
    break;
	default: LCD_u8WriteString("WRONG CHOICE"); break;
	 }
	}
}



//void displayDigit1(u8 digit)
//{
//	DIO_U8SetPinValue(CONTROL_SEGMENT_PORT,CONTROL_DISPLAY_PIN1,DIO_LOW);
//	DIO_U8SetPinValue(CONTROL_SEGMENT_PORT,CONTROL_DISPLAY_PIN2,DIO_HIGH);
//	 DIO_U8SetPortValue(DISPLAY_SEGMENT_PORT,digit);
//	_delay_ms(500);
//
//}
//void displayDigit2(u8 digit)
//{
//	DIO_U8SetPinValue(CONTROL_SEGMENT_PORT,CONTROL_DISPLAY_PIN2,DIO_LOW);
//	DIO_U8SetPinValue(CONTROL_SEGMENT_PORT,CONTROL_DISPLAY_PIN1,DIO_HIGH);
//    DIO_U8SetPortValue(DISPLAY_SEGMENT_PORT,digit);
//	_delay_ms(500);
//}
//void Display_TL(void)
//{
//	DIO_U8SetPortDirection(DISPLAY_SEGMENT_PORT,DIO_PORT_OUT);
//	DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT,CONTROL_DISPLAY_PIN2,DIO_PIN_OUT);
//	DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT,CONTROL_DISPLAY_PIN1,DIO_PIN_OUT);
//
//    u8 arr[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
//    u8 i;
//    u8 j;
//	for (i = 0; i < 10; i++)
//			  {
//				 displayDigit1(arr[i]);
//			  }
//	for (j = 0; j < 10; j++)
//			  {
//				 displayDigit2(arr[j]);
//			  }
//}






