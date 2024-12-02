################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL_STM32F411_GPIO.c \
../Src/HAL_STM32F411_RCC.c \
../Src/HAL_STM32F411_TIM.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/HAL_STM32F411_GPIO.o \
./Src/HAL_STM32F411_RCC.o \
./Src/HAL_STM32F411_TIM.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/HAL_STM32F411_GPIO.d \
./Src/HAL_STM32F411_RCC.d \
./Src/HAL_STM32F411_TIM.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/HAL_STM32F411_GPIO.cyclo ./Src/HAL_STM32F411_GPIO.d ./Src/HAL_STM32F411_GPIO.o ./Src/HAL_STM32F411_GPIO.su ./Src/HAL_STM32F411_RCC.cyclo ./Src/HAL_STM32F411_RCC.d ./Src/HAL_STM32F411_RCC.o ./Src/HAL_STM32F411_RCC.su ./Src/HAL_STM32F411_TIM.cyclo ./Src/HAL_STM32F411_TIM.d ./Src/HAL_STM32F411_TIM.o ./Src/HAL_STM32F411_TIM.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

