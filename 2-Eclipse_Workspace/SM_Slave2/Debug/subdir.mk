################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../I2C_Program.c \
../KPAD_Program.c \
../LCD_Program.c \
../SERVO_Program.c \
../Smart_Home_Program.c \
../Timer.c \
../USART_Program.c \
../main.c \
../stepper_motor.c 

OBJS += \
./DIO_Program.o \
./I2C_Program.o \
./KPAD_Program.o \
./LCD_Program.o \
./SERVO_Program.o \
./Smart_Home_Program.o \
./Timer.o \
./USART_Program.o \
./main.o \
./stepper_motor.o 

C_DEPS += \
./DIO_Program.d \
./I2C_Program.d \
./KPAD_Program.d \
./LCD_Program.d \
./SERVO_Program.d \
./Smart_Home_Program.d \
./Timer.d \
./USART_Program.d \
./main.d \
./stepper_motor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


