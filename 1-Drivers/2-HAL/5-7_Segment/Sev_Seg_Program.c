#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_Interface.h"

#include "Sev_Seg_Interface.h"


u8 Num_arr[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void SevSeg_VidDisplayNumber(u8 Copy_U8PortNumber, u8 Copy_U8Number)
{
    if (Copy_U8PortNumber >= 0 && Copy_U8PortNumber < 4) {
        if (Copy_U8Number >= 0 && Copy_U8Number < 10) {
#if SEVENSEG_TYPE == COM_CATHODE
            DIO_U8SetPortValue(Copy_U8PortNumber, Num_arr[Copy_U8Number]);
#elif SEVENSEG_TYPE == COM_ANODE
            DIO_U8SetPortValue(Copy_U8PortNumber, 0xFF - Num_arr[Copy_U8Number]);
#else
#error "Wrong input of the 7-Segment type"
#endif
        }
    }
}
void SevSeg_VidInit(void)
{
    DIO_U8SetPortDirection(DISPLAY_SEGMENT_PORT, DIO_PORT_OUT);
    DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN2, DIO_PIN_OUT);
    DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN1, DIO_PIN_OUT);
    DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT, CONTROL_RED_PIN, DIO_PIN_OUT);
    DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT, CONTROL_YELLOW_PIN, DIO_PIN_OUT);
    DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT, CONTROL_GREEN_PIN, DIO_PIN_OUT);

    DIO_U8SetPinDirection(CONTROL_SEGMENT_PORT, CONTROL_BUZZER_PIN, DIO_PIN_OUT);
    DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_BUZZER_PIN, DIO_LOW);
}
void SevSeg_VidDisplayNumMulti(u8 Copy_U8Port, u8 Copy_U8Number)
{
    /* Port1 for digit 1 and Port2 for digit 2 */
    u8 Local_U8Quot = Copy_U8Number / 10;
    u8 Local_U8rem = Copy_U8Number % 10;

    // Activate Digit 1
    DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN1, DIO_LOW);
    DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN2, DIO_HIGH);
    SevSeg_VidDisplayNumber(Copy_U8Port, Local_U8rem);
    _delay_ms(5);
    // Activate Digit 2
    DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN1, DIO_HIGH);
    DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN2, DIO_LOW);
    SevSeg_VidDisplayNumber(Copy_U8Port, Local_U8Quot);
    _delay_ms(5);
    /* Each Frame takes 2 x 2ms = 4ms to fully Display */
}

void BuzzForDuration(u16 duration_ms)
{
    DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_BUZZER_PIN, DIO_HIGH);
    _delay_ms(duration_ms);
    DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_BUZZER_PIN, DIO_LOW);
}

static u8 led = 0;

void SevSeg_VidDispTrafficLights(u8 Copy_U8SevSeg_PORT, u8 Copy_U8Number)
{
    u16 Local_U16LoopDelay = 0;
    u8 prev_led = 0;

    for (u8 i = Copy_U8Number; i > 0; i--) {
        led = i;

        DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_RED_PIN, DIO_LOW);
        DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_YELLOW_PIN, DIO_LOW);
        DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_GREEN_PIN, DIO_LOW);

        if (led >= 67) {
            DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_RED_PIN, DIO_HIGH);
        } else if (led >= 34) {
            DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_YELLOW_PIN, DIO_HIGH);
            // Buzz when transitioning from red to yellow
            if (prev_led >= 67) {
                BuzzForDuration(200);
            }
        } else {
            DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_GREEN_PIN, DIO_HIGH);
            // Buzz when transitioning from yellow to green
            if (prev_led >= 34) {
                BuzzForDuration(200);
            }
        }

        DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN1, DIO_HIGH);
        DIO_U8SetPinValue(CONTROL_SEGMENT_PORT, CONTROL_DISPLAY_PIN2, DIO_LOW);

        while (Local_U16LoopDelay < 20) {
            SevSeg_VidDisplayNumMulti(Copy_U8SevSeg_PORT, i);
            Local_U16LoopDelay++;
        }
        Local_U16LoopDelay = 0;
        prev_led = led;
    }
}
