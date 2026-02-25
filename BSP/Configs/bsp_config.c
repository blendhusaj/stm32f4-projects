#include "bsp_config.h"
#include "stm32f4xx_nucleo.h"
#include "main.h"
#include <stdint.h>

static volatile uint32_t l_tickCtr = 0;

void SysTick_Handler(void)
{
    HAL_IncTick();
    ++l_tickCtr;
}

void BSP_Button_Init(const User_Button_config_t *button)
{
    uint32_t pin_pos = __builtin_ctz(button->pin);
    uint32_t shift = 2u * pin_pos;

    if (button->port == GPIOA) { __HAL_RCC_GPIOA_CLK_ENABLE(); }
    else if (button->port == GPIOB) { __HAL_RCC_GPIOB_CLK_ENABLE(); }
    else if (button->port == GPIOC) { __HAL_RCC_GPIOC_CLK_ENABLE(); }

    button->port->MODER &= ~(3u << shift);
    button->port->MODER |= (button->mode << shift);

    button->port->PUPDR &= ~(3u << shift);
    button->port->PUPDR |= (button->pull << shift);
}
uint8_t BSP_Button_GetState(const User_Button_config_t *button)
{
    return (button->port->IDR & button->pin) ? 0u : 1u;
}

void BSP_SysTick_ApplyConfig(const SysTick_Config_t *config)
{
    SysTick->LOAD = config->load & 0x00FFFFFFu;
    SysTick->VAL  = config->val & 0x00FFFFFFu;
    SysTick->CTRL = config->ctrl & 0x07u;
}

void BSP_Delay(uint32_t ms)
{
    uint32_t start = l_tickCtr;
    while ((l_tickCtr - start) < ms) {
        __NOP();
    }
}

uint32_t BSP_GetTick(void)
{
    return l_tickCtr;
}

uint8_t BSP_TimerExpired(uint32_t target_tick)
{
    return (l_tickCtr >= target_tick) ? 1u : 0u;
}
