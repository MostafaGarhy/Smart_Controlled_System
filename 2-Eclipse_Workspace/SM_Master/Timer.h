/*
 * Timer.h
 *
 *  Created on: Aug 20, 2023
 *      Author: ma257
 */

#ifndef TIMER_H_
#define TIMER_H_

#define INVERTED_PWM 		 0
#define NONINVERTED_PWM      1

#define TIMER_OVERFLOW_MODE  0
#define TIMER_CTC_MODE       1


#define FAST_PWM_MODE INVERTED_PWM

#define TIMER0_MODE TIMER_CTC_MODE

void TIMER_VidOvfInit(void);

void TIMER_VidCTCInit(void);

void TIMER_VidCTCTimer1Preload(s16 Copy_U16PreloadValue);

void TIMER_VidSetTimer1Preload(u16 Copy_U16PreloadValue);

void TIMER_VoidSetPreloadValue(u16 Copy_U16PreloadValue);

void TIMER_VoidPWMInit(void);

void TIMER_VoidTimer1Init(void);

void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));

#endif /* TIMER_H_ */
