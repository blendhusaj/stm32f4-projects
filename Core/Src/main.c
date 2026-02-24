#include "main.h"
#include <stdio.h>
#include <string.h>

UART_HandleTypeDef huart2;

extern uint32_t SystemCoreClock;
static User_Button_config_t btn;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void configGpio(void);
void App_SysTick_Init(void);
void buttonConfig_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  configGpio();
  App_SysTick_Init();
  buttonConfig_Init();

 __enable_irq();

 uint32_t next = BSP_DELAY_START(500);

 uint8_t prev_btn = 0;

 while (1)
 {
     uint8_t curr_btn = BSP_Button_GetState(&btn);

     /* Toggle LED only on press (released -> pressed) */
     if (curr_btn == 1 && prev_btn == 0)
     {
         GPIOA->ODR ^= (1u << 5);
     }
     prev_btn = curr_btn;
 }
}

void buttonConfig_Init(void)
{
    btn.port = GPIOC;
    btn.pin  = GPIO_PIN_13;
    btn.mode = 0u;
    btn.pull = 1u;
    BSP_Button_Init(&btn);
}

void App_SysTick_Init(void){
	  SysTick_Config_t sysT = {
	 		 .load = (SystemCoreClock / 1000) -1 , // 1ms ick
	 		 .val = 0,
	 		 .ctrl = SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_TICKINIT | SYSTICK_CTRL_CLKSOURCE
	  };
	  BSP_SysTick_ApplyConfig(&sysT);
}


void configGpio(void){
	GPIOA->MODER &= ~(3u << 10);
	GPIOA->MODER |= (1u << 10);
}
static void MX_USART2_UART_Init(void)
{

  //GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_USART2_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);
}

static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                              | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
}
