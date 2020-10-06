/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR2_MS1_Pin GPIO_PIN_5
#define MOTOR2_MS1_GPIO_Port GPIOA
#define MOTOR2_STEP_Pin GPIO_PIN_6
#define MOTOR2_STEP_GPIO_Port GPIOA
#define MOTOR2_DIR_Pin GPIO_PIN_7
#define MOTOR2_DIR_GPIO_Port GPIOA
#define MOTOR2_SLEEP_Pin GPIO_PIN_4
#define MOTOR2_SLEEP_GPIO_Port GPIOC
#define MOTOR2_RESET_Pin GPIO_PIN_5
#define MOTOR2_RESET_GPIO_Port GPIOC
#define MOTOR2_MS2_Pin GPIO_PIN_0
#define MOTOR2_MS2_GPIO_Port GPIOB
#define MOTOR2_MS3_Pin GPIO_PIN_1
#define MOTOR2_MS3_GPIO_Port GPIOB
#define MOTOR1_MS3_Pin GPIO_PIN_14
#define MOTOR1_MS3_GPIO_Port GPIOB
#define MOTOR1_MS2_Pin GPIO_PIN_15
#define MOTOR1_MS2_GPIO_Port GPIOB
#define MOTOR1_MS1_Pin GPIO_PIN_6
#define MOTOR1_MS1_GPIO_Port GPIOC
#define MOTOR1_RESET_Pin GPIO_PIN_7
#define MOTOR1_RESET_GPIO_Port GPIOC
#define MOTOR1_SLEEP_Pin GPIO_PIN_8
#define MOTOR1_SLEEP_GPIO_Port GPIOC
#define MOTOR1_DIR_Pin GPIO_PIN_9
#define MOTOR1_DIR_GPIO_Port GPIOC
#define MOTOR1_STEP_Pin GPIO_PIN_8
#define MOTOR1_STEP_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
