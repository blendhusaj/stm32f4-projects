################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Config/bsp_config.c 

OBJS += \
./Config/bsp_config.o 

C_DEPS += \
./Config/bsp_config.d 


# Each subdirectory must supply rules for building sources it contributes
Config/%.o Config/%.su Config/%.cyclo: ../Config/%.c Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"D:/mcuuu/stcom/BSP" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/mcuuu/stcom/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Config

clean-Config:
	-$(RM) ./Config/bsp_config.cyclo ./Config/bsp_config.d ./Config/bsp_config.o ./Config/bsp_config.su

.PHONY: clean-Config

