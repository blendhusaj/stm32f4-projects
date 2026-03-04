################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CAN/can_driver.c 

OBJS += \
./Drivers/CAN/can_driver.o 

C_DEPS += \
./Drivers/CAN/can_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CAN/%.o Drivers/CAN/%.su Drivers/CAN/%.cyclo: ../Drivers/CAN/%.c Drivers/CAN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"D:/mcuuu/stcom/BSP" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/mcuuu/stcom/BSP/Configs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CAN

clean-Drivers-2f-CAN:
	-$(RM) ./Drivers/CAN/can_driver.cyclo ./Drivers/CAN/can_driver.d ./Drivers/CAN/can_driver.o ./Drivers/CAN/can_driver.su

.PHONY: clean-Drivers-2f-CAN

