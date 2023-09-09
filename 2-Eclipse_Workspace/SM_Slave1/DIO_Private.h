/****************************************************/
/* SWC 	  	   : DIO Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 9 AUG 2023                         */
/* Description : Digital Input Outpot driver        */
/****************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_




/*Macro Defintions for PORTS Registers */
#define PORTA *((u8*)0x3B)
#define PORTB *((u8*)0x38)
#define PORTC *((u8*)0x35)
#define PORTD *((u8*)0x32)

/*Macro Defintions for Direction Registers */
#define DDRA *((u8*)0x3A)
#define DDRB *((u8*)0x37)
#define DDRC *((u8*)0x34)
#define DDRD *((u8*)0x31)

/*Macro Defintions for PINS Registers */
#define PINA *((volatile u8*)0x39)
#define PINB *((volatile u8*)0x36)
#define PINC *((volatile u8*)0x33)
#define PIND *((volatile u8*)0x30)





#endif
