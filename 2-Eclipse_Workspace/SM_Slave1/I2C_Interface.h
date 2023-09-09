/****************************************************/
/* SWC 	  	   : I2C Driver                         */
/* Author 	   : Bassem Hussein                     */
/* Version 	   : V1.0                               */
/* Date    	   : 26 AUG 2023                        */
/* Description : I2C Communication Protocol         */
/****************************************************/
/* Header Guard */
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_VidMasterInit(void);

void I2C_VidSlaveInit(u8 Copy_u8Address);

void I2C_VidStartCondition(void);

void I2C_VidStopCondition(void);

void I2C_VidSlaveAddressWrite(u8 Copy_u8SlaveAddress);

void I2C_VidSlaveAddressRead(u8 Copy_u8SlaveAddress);

u8 I2C_VidSlaveRecieveData(void);

void I2C_VidMastarSendData(u8 Copy_u8Data);

u8 I2C_VidMastarRecieveData(void);

u8 I2C_VidSlaveRecieveData(void);


#endif
