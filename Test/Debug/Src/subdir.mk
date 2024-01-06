################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AFIO_Program.c \
../Src/DIO_Cfg.c \
../Src/DIO_Program.c \
../Src/ESP_Program.c \
../Src/NVIC_PROGRAM.c \
../Src/RCC_Program.c \
../Src/SysTick.c \
../Src/UART_Program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AFIO_Program.o \
./Src/DIO_Cfg.o \
./Src/DIO_Program.o \
./Src/ESP_Program.o \
./Src/NVIC_PROGRAM.o \
./Src/RCC_Program.o \
./Src/SysTick.o \
./Src/UART_Program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AFIO_Program.d \
./Src/DIO_Cfg.d \
./Src/DIO_Program.d \
./Src/ESP_Program.d \
./Src/NVIC_PROGRAM.d \
./Src/RCC_Program.d \
./Src/SysTick.d \
./Src/UART_Program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AFIO_Program.d ./Src/AFIO_Program.o ./Src/AFIO_Program.su ./Src/DIO_Cfg.d ./Src/DIO_Cfg.o ./Src/DIO_Cfg.su ./Src/DIO_Program.d ./Src/DIO_Program.o ./Src/DIO_Program.su ./Src/ESP_Program.d ./Src/ESP_Program.o ./Src/ESP_Program.su ./Src/NVIC_PROGRAM.d ./Src/NVIC_PROGRAM.o ./Src/NVIC_PROGRAM.su ./Src/RCC_Program.d ./Src/RCC_Program.o ./Src/RCC_Program.su ./Src/SysTick.d ./Src/SysTick.o ./Src/SysTick.su ./Src/UART_Program.d ./Src/UART_Program.o ./Src/UART_Program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

