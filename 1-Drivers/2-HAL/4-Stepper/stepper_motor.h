/*
 * stepper_motor.h
 *
 *  Created on: Aug 15, 2023
 *      Author: ma257
 */

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

//Stepper Function to Initialize the first four pins of the port
void HSTEP_VidInit(void);
//Stepper Function to set the stepper angle and the rotation direction
u8 HSTEP_U8SetAngDir(u16 Copy_U16Angle, u8 Copy_U8Direction);

/* 		Stepper Port Macros 		*/
/* DIO_PORTA
 * DIO_PORTB
 * DIO_PORTC
 * DIO_PORTD
 */
#define STEP_PORT			DIO_PORTA

/* 		Rotation Direction Macros		 */
#define STEP_DIR_CW			0
#define STEP_DIR_ACW		1

/* Stepper Pins */
/*DIO_PIN0
DIO_PIN1
DIO_PIN2
DIO_PIN3
DIO_PIN4
DIO_PIN5
DIO_PIN6
DIO_PIN7
 * */
#define STEP_PIN0	DIO_PIN0
#define STEP_PIN1	DIO_PIN1
#define STEP_PIN2	DIO_PIN2
#define STEP_PIN3   DIO_PIN3

#endif /* STEPPER_MOTOR_H_ */
