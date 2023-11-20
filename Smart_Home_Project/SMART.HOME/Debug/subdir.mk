################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../CLCD_prog.c \
../DIO_prog.c \
../GIE_Prog.c \
../GI_program.c \
../KPD_prog.c \
../LED_prog.c \
../PORT_program.c \
../STPPR_Program.c \
../SW_prog.c \
../Seg_prog.c \
../USART_prog.c \
../main.c 

OBJS += \
./ADC_prog.o \
./CLCD_prog.o \
./DIO_prog.o \
./GIE_Prog.o \
./GI_program.o \
./KPD_prog.o \
./LED_prog.o \
./PORT_program.o \
./STPPR_Program.o \
./SW_prog.o \
./Seg_prog.o \
./USART_prog.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./CLCD_prog.d \
./DIO_prog.d \
./GIE_Prog.d \
./GI_program.d \
./KPD_prog.d \
./LED_prog.d \
./PORT_program.d \
./STPPR_Program.d \
./SW_prog.d \
./Seg_prog.d \
./USART_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


