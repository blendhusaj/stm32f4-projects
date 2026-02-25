#ifndef BSP_CONFIG_H
#define BSP_CONFIG_H

#include <stdint.h>
#include "stm32f4xx_hal.h"

/* --- Macros --- */
#define SYSTICK_CTRL_ENABLE    (1u << 0)
#define SYSTICK_CTRL_TICKINIT  (1u << 1)
#define SYSTICK_CTRL_CLKSOURCE (1u << 2)
#define BSP_DELAY_START(ms)   (BSP_GetTick() + (ms))

/* --- Types (defined before use in declarations) --- */
typedef struct {
    GPIO_TypeDef *port;
    uint32_t pin;
    uint32_t mode;
    uint32_t pull;
} User_Button_config_t;

typedef struct {
    uint32_t load;
    uint32_t val;
    uint32_t ctrl;
} SysTick_Config_t;

/* --- Button --- */
void BSP_Button_Init(const User_Button_config_t *button);
uint8_t BSP_Button_GetState(const User_Button_config_t *button);

/* --- SysTick --- */
void BSP_SysTick_ApplyConfig(const SysTick_Config_t *config);
void BSP_SysTick_Config(void);

/* --- Timing --- */
void BSP_Delay(uint32_t ms);
uint32_t BSP_GetTick(void);
uint8_t BSP_TimerExpired(uint32_t target_tick);

#endif /* BSP_CONFIG_H */
