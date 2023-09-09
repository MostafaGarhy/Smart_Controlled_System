/****************************************************/
/* SWC 	  	   : I2C Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 26 AUG 2023                        */
/* Description : I2C Communication Protocol         */
/****************************************************/
/* Header Guard */
#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define I2C_TWBR              *((volatile u8*)0x20)
#define I2C_TWSR              *((volatile u8*)0x21)
#define I2C_TWAR              *((volatile u8*)0x22)
#define I2C_TWDR              *((volatile u8*)0x23)
#define I2C_TWCR              *((volatile u8*)0x56)

/* TWI Control Register – TWCR PINS */

#define TWINT   7  /*  TWI Interrupt Flag */
#define TWEA    6  /*  TWI Enable Acknowledge Bit */
#define TWSTA   5  /*  TWI START Condition Bit*/
#define TWSTO   4  /*  TWSTO: TWI STOP Condition Bit */
#define TWWC    3  /*   TWI Write Collision Flag*/
#define TWEN    2  /*   TWI Enable Bit*/
#define TWIE    0  /*   TWI Interrupt Enable */

/* TWI Status Register – TWSR PINS */

#define TWS7    7  /*  Bits 7..3 – TWS: TWI Status */
#define TWS6    6  /*  Bits 7..3 – TWS: TWI Status*/
#define TWS5    5  /*  Bits 7..3 – TWS: TWI Status*/
#define TWS4    4  /*  Bits 7..3 – TWS: TWI Status*/
#define TWS3    3  /*  Bits 7..3 – TWS: TWI Statust*/
#define TWPS1   1  /*  TWPS: TWI Prescaler Bits*/
#define TWPS0   0  /*  TWPS: TWI Prescaler Bits*/


/* TWI Data Register – TWDR PINS */
//Bits 7..0 – TWD: TWI Data Register
#define TWD7    7
#define TWD6    6
#define TWD5    5
#define TWD4    4
#define TWD3    3
#define TWD2    2
#define TWD1    1
#define TWD0    0

/* TWI (Slave) Address Register -TWAR Pins */
// Bits 7..1 – TWA: TWI (Slave) Address Register
#define TWA6   7
#define TWA5   6
#define TWA4   5
#define TWA3   4
#define TWA2   3
#define TWA1   2
#define TWA0   1
#define TWGCE  0

#endif
