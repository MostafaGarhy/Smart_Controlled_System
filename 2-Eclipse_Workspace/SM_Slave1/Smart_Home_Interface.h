
#ifndef SMART_HOME_INTERFACE_H_
#define SMART_HOME_INTERFACE_H_




void SM_VoidServo_APP(void);
u8 SM_U8LoginSys(void);
u16 SM_U16EnterPassword(void);
u8 SM_U8RoomSelect(void);
void SM_VoidCalc(void);

/* Traffic Lights Prototypes */
void displayDigit2(u8 digit);
void displayDigit1(u8 digit);
void Display_TL(void);


#endif
