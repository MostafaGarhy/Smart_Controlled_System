/****************************************************/
/* SWC 	  	   : I2C Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 26 AUG 2023                        */
/* Description : I2C Communication Protocol         */
/****************************************************/
/* Header Guard */

    /*  Lib Layer  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"



  /*  MCAL Layer  */
#include "I2C_Config.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"


void I2C_VidMasterInit(void)
{
	/*01- set the Prescaller-> 1*/
	CLR_BIT(I2C_TWSR,TWPS0);
	CLR_BIT(I2C_TWSR,TWPS1);
	/*02- choose Frequancy -->400KHZ Max speed and for 200 200KHZ --> I2C_TWBR=12 */
	I2C_TWBR=2;
	/*03- Enable I2C*/
	SET_BIT(I2C_TWCR,TWEN);
}

void I2C_VidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*01- Enable the ACK Bit */
	SET_BIT(I2C_TWCR,TWEA);
	/*02- Write Slave Address --> only 7 MSB*/
	I2C_TWAR=Copy_u8SlaveAddress<<1;  // as the data is only 7 bits and bit 0 is read write bit
	/*03- Enable I2C */
	SET_BIT(I2C_TWCR,TWEN);
}

void I2C_VidStartCondition(void)
{
	/*01- Clear the flag & Enable the SC Pins*/
	
	SET_BIT(I2C_TWCR,TWINT);
	SET_BIT(I2C_TWCR,TWSTA);
	
	/*02- wait for flag to be Cleared ---> Stuck */
	
	while((GET_BIT(I2C_TWCR,TWINT))==0);
}

void I2C_VidStopCondition(void)
{
	/*01- Clear the flag & Enable the SC Pins*/
	
	SET_BIT(I2C_TWCR,TWINT);
	SET_BIT(I2C_TWCR,TWSTO);
}

void I2C_VidSlaveAddressWrite(u8 Copy_u8SlaveAddress)//written by master
{
	/*01- Write Slave Address --> only 7 MSB*/
	I2C_TWDR=Copy_u8SlaveAddress<<1;
	/*02- Clear TWGCE bit to select Write  */
	CLR_BIT(I2C_TWDR,TWGCE);

	CLR_BIT(I2C_TWCR,TWSTA);
	/*03-Clear flag */
	SET_BIT(I2C_TWCR,TWINT);
	
	/*04- wait for flag to be Cleared ---> Stuck */
	while((GET_BIT(I2C_TWCR,TWINT))==0);

}

void I2C_VidSlaveAddressRead(u8 Copy_u8SlaveAddress)
{
	/*01- Write Slave Address --> only 7 MSB*/
	I2C_TWDR=Copy_u8SlaveAddress<<1;
	
	/*02- Clear TWGCE bit to select Write  */
	
	SET_BIT(I2C_TWDR,TWGCE);
	CLR_BIT(I2C_TWCR,TWSTA);
	
	/*03-Clear flag */
	SET_BIT(I2C_TWCR,TWINT);
	
	/*04- wait for flag to be Cleared ---> Stuck */
	while((GET_BIT(I2C_TWCR,TWINT))==0);
}

void I2C_VidMastarSendData(u8 Copy_u8Data)
{
	/*01- Send the data to I2C Data Register */
	I2C_TWDR=Copy_u8Data;
	
	/*02-Clear flag */
	SET_BIT(I2C_TWCR,TWINT);
	
	/*03- wait for flag to be Cleared ---> Stuck */
	while((GET_BIT(I2C_TWCR,TWINT))==0);
}

u8 I2C_VidMastarRecieveData(void)
{
	/*01-Clear flag */
	SET_BIT(I2C_TWCR,TWINT);
	
	/*02- wait for flag to be Cleared ---> Stuck */
	while((GET_BIT(I2C_TWCR,TWINT))==0);
	
	/*03- read the data to I2C Data Register */
	return I2C_TWDR;
}

u8 I2C_VidSlaveRecieveData(void)
{
	/*01- wait ---> Stuck */
	while((I2C_TWSR&0xf8)!=0x60);

	/*02- set the I2C Init */
	SET_BIT(I2C_TWCR,TWINT);
	/*03- wait ---> Stuck */
	while((I2C_TWSR&0xf8)!=0x80);

	/*04- read the data to I2C Data Register */
	return I2C_TWDR;

}

