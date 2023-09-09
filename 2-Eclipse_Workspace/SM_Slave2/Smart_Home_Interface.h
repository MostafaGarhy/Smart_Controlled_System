
#ifndef SMART_HOME_INTERFACE_H_
#define SMART_HOME_INTERFACE_H_




void SM_VoidServo_APP(void);
u8 SM_U8LoginSys(void);
u16 SM_U16EnterPassword(void);
u8 SM_U8RoomSelect(void);
void SM_VoidCalc(void);

/* Traffic Lights Prototypes */
void SevSeg_VidInit(void);
void SevSeg_VidDisplayNumber(u8 Copy_U8PortNumber, u8 Copy_U8Number);
void SevSeg_VidDisplayNumMulti(u8 Copy_U8Port, u8 Copy_U8Number);
void BuzzForDuration(u16 duration_ms);
void SevSeg_VidDispTrafficLights(u8 Copy_U8SevSeg_PORT, u8 Copy_U8Number);


#endif
