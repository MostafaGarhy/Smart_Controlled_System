
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

int main()
{
	LCD_VoidLCDInit();
	I2C_VidMasterInit();
	KPAD_VidInit();
	UART_VidInit();

	DIO_U8SetPortDirection(DIO_PORTD, 0xFE);

	TIMER_VoidTimer1Init();
	TIMER_VidSetTimer1Preload(20000);

	LCD_u8WriteString("Welcome");
	_delay_ms(500);
	LCD_VoidSendCommand(1);


	u8 x = 0;
    x = SM_U8LoginSys();
	if(x== ERROR_STATE_OK)
	{
		SM_U8RoomSelect();
	}
	else
	{
		DIO_U8SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUT);
		DIO_U8SetPinValue(DIO_PORTB,DIO_PIN6,HIGH);
	}
    while (1)
    {

    }

    return 0;
}


