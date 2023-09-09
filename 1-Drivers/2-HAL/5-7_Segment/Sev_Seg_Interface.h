
#ifndef SEV_SEG_INTERFACE_H_
#define SEV_SEG_INTE

void SevSeg_VidInit(void);
void SevSeg_VidDisplayNumber(u8 Copy_U8PortNumber, u8 Copy_U8Number);
void SevSeg_VidDisplayNumMulti(u8 Copy_U8Port, u8 Copy_U8Number);
void BuzzForDuration(u16 duration_ms);
void SevSeg_VidDispTrafficLights(u8 Copy_U8SevSeg_PORT, u8 Copy_U8Number);

#endif