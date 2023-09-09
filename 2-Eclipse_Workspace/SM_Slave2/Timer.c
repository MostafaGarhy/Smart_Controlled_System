
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include <avr/io.h>
#include "Timer.h"

void TIMER_VidOvfInit(void)
{
	//1- Set the Wave Generation mode as normal
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);

	//3- Enable Overflow Interrupt
	SET_BIT(TIMSK, 0);


	//2- Set the prescaler 8Mhz / 8 = 1Mhz --> Timer Freq
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);


}

void TIMER_VidCTCInit(void)
{
	//1- Set the Wave Generation mode as normal
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

	//3- Enable CTC Interrupt
	SET_BIT(TIMSK, 1);

	//2- Set the prescaler 8Mhz / 8 = 1Mhz --> Timer Freq
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

}
void TIMER_VoidSetPreloadValue(u16 Copy_U16PreloadValue)
{
	#if TIMER0_MODE  == TIMER_OVERFLOW_MODE
	//4- Set the Preload Value
	TCNT0 =Copy_U16PreloadValue;
	#elif TIMER0_MODE  == TIMER_CTC_MODE
	// Set the OCR Value
	OCR0=Copy_U16PreloadValue;
	#endif

}
void TIMER_VoidPWMInit(void)
{
	//1- Set the Wave Generation mode as PWM
		SET_BIT(TCCR0, WGM00);
		SET_BIT(TCCR0, WGM01);

	#if FAST_PWM_MODE == INVERTED_PWM
		CLR_BIT( TCCR0,COM00);
		SET_BIT( TCCR0,COM01);

	#elif FAST_PWM_MODE ==NONINVERTED_PWM
		SET_BIT( TCCR0,COM00);
		SET_BIT( TCCR0,COM01);
	#endif
	//2- Set the prescaler 8Mhz / 8 = 1Mhz --> Timer Freq
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);

}
void TIMER_VoidTimer1Init(void)
{
	/* Fast PWM Timer1 */
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

	/* NonInverted Timer1 Mode */
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);

	//2- Set the prescaller 8Mhz / 8 = 1Mhz --> Timer Freq
	CLR_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);

}
void TIMER_VidCTCTimer1Preload(s16 Copy_U16PreloadValue)
{
	OCR1A=Copy_U16PreloadValue;
}
void TIMER_VidSetTimer1Preload(u16 Copy_U16PreloadValue)
{
	ICR1=Copy_U16PreloadValue;
}




//void __vector_10(void)
//{
//
//	static u16 counter = 0;
//	counter++;
//	if(counter == 4000)
//	{
//		counter = 0;
//		//Do Action every 1s
//		DIO_VidTogglePinValue(PORTA_U8_INDEX, PIN0_U8_INDEX);
//	}
//}

void __vector_10(void)
{

	static u16 counter = 0;
	counter++;
	if(counter == 5)
	{
		//Do Action every 1s
		DIO_U8SetPinValue(DIO_PORTA,DIO_PIN0,1);
	}
	else if(counter == 20)
	{
		counter = 0;
		DIO_U8SetPinValue(DIO_PORTA, DIO_PIN0,0);

	}
}


void __vector_11(void)
{
	//3906.25
	static u16 counter = 0;
	counter++;
	if(counter == 3907)
	{
		counter = 0;
		TCNT0 = 192;
		//Do Action every 1s
		DIO_U8TogglePin(DIO_PORTA,DIO_PIN0);
	}
}





