/****************************************************/
/* SWC 	  	   : DIO Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 9 AUG 2023                         */
/* Description : Digital Input Outpot driver        */
/****************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define DIO_PORT_OUT  0xff
#define DIO_PORT_IN   0x00
#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW  0x00


#define DIO_PIN_OUT 1
#define DIO_PIN_IN  0

#define DIO_HIGH   1
#define DIO_LOW    0

u8 DIO_U8SetPinDirection(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb,u8 Copy_U8Directon);

u8 DIO_U8SetPinValue(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb,u8 Copy_U8Value);

u8 DIO_U8GetPinValue(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb,u8 *Copy_U8Value);

u8 DIO_U8TogglePin(u8 Copy_U8PortNumb,u8 Copy_U8PinNumb);

u8 DIO_U8SetPortDirection(u8 Copy_U8PortNumb,u8 Copy_U8Directon);

u8 DIO_U8SetPortValue(u8 Copy_U8PortNumb,u8 Copy_U8Value); 

u8 DIO_U8GetPortValue(u8 Copy_U8PortNumb,u8 *Copy_U8Value);






#endif
