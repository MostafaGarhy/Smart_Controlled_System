/*
 * Smart_Home_Config.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Bassem Hussein
 */

#ifndef SMART_HOME_CONFIG_H_
#define SMART_HOME_CONFIG_H_




#define ZERO  0b0111111
#define ONE   0b0000110
#define TWO   0b1011011
#define THREE 0b1001111
#define FOUR  0b1100110
#define FIVE  0b1101101
#define SIX   0b1111101
#define SEVEN 0b0000111
#define EIGHT 0b1111111
#define NINE  0b1101111


#define CONTROL_SEGMENT_PORT         DIO_PORTC
#define DISPLAY_SEGMENT_PORT         DIO_PORTB

#define CONTROL_DISPLAY_PIN1         DIO_PIN2
#define CONTROL_DISPLAY_PIN2         DIO_PIN3

#define CONTROL_RED_PIN              DIO_PIN4
#define CONTROL_YELLOW_PIN           DIO_PIN5
#define CONTROL_GREEN_PIN            DIO_PIN6
#define CONTROL_BUZZER_PIN           DIO_PIN7

#endif /* SMART_HOME_CONFIG_H_ */
