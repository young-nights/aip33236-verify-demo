/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-09-09     RT-Thread    first version
 */

#include <rtthread.h>
#include "bsp_sys.h"
#include <rtdbg.h>

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  /* 相关引脚初始化 */
  AIP33236_GPIO_Config();
  /* iic初始化 */
  aip33236_device_init();
  /* Fre set */
  AIP33236_PWM_Frequency_Set(aip33236_u1_dev,0);
  /* 0x00 写 0x01 */
  AIP33236_Software_Switch(aip33236_u1_soft, 1);
  /* 0x4A 写 0x00 */
  AIP33236_Enable_all_Channel_Res(aip33236_u1_dev,0);
  /* PWM and current set */
  AIP33236_PWM_Duty_Set(aip33236_u1_dev,0xFF,1);
  AIP33236_PWM_Switch_Current_Set(aip33236_u1_dev,0x01,1);
  /* Update channel */
  AIP33236_Channel_Data_Update(aip33236_u1_dev);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

      rt_thread_mdelay(500);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}



