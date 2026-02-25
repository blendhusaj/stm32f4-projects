################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/Configs/bsp_config.c 

OBJS += \
./BSP/Configs/bsp_config.o 

C_DEPS += \
./BSP/Configs/bsp_config.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/Configs/%.o BSP/Configs/%.su BSP/Configs/%.cyclo: ../BSP/Configs/%.c BSP/Configs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"D:/mcuuu/stcom/BSP" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/mcuuu/stcom/BSP/Configs" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-Configs

clean-BSP-2f-Configs:
	-$(RM) ./BSP/Configs/bsp_config.cyclo ./BSP/Configs/bsp_config.d ./BSP/Configs/bsp_config.o ./BSP/Configs/bsp_config.su

.PHONY: clean-BSP-2f-Configs

