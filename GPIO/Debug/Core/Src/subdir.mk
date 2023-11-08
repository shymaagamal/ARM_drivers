################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/DMA_program.c \
../Core/Src/GPIO_program.c \
../Core/Src/NVIC_program.c \
../Core/Src/RCC_program.c \
../Core/Src/STK_program.c \
../Core/Src/main.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32c0xx.c 

OBJS += \
./Core/Src/DMA_program.o \
./Core/Src/GPIO_program.o \
./Core/Src/NVIC_program.o \
./Core/Src/RCC_program.o \
./Core/Src/STK_program.o \
./Core/Src/main.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32c0xx.o 

C_DEPS += \
./Core/Src/DMA_program.d \
./Core/Src/GPIO_program.d \
./Core/Src/NVIC_program.d \
./Core/Src/RCC_program.d \
./Core/Src/STK_program.d \
./Core/Src/main.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32c0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C011xx -c -I../Core/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/DMA_program.d ./Core/Src/DMA_program.o ./Core/Src/DMA_program.su ./Core/Src/GPIO_program.d ./Core/Src/GPIO_program.o ./Core/Src/GPIO_program.su ./Core/Src/NVIC_program.d ./Core/Src/NVIC_program.o ./Core/Src/NVIC_program.su ./Core/Src/RCC_program.d ./Core/Src/RCC_program.o ./Core/Src/RCC_program.su ./Core/Src/STK_program.d ./Core/Src/STK_program.o ./Core/Src/STK_program.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32c0xx.d ./Core/Src/system_stm32c0xx.o ./Core/Src/system_stm32c0xx.su

.PHONY: clean-Core-2f-Src

