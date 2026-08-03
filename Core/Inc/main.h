/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define LED_STATUS_Pin GPIO_PIN_13
#define LED_STATUS_GPIO_Port GPIOC
#define LED_POWER_Pin GPIO_PIN_15
#define LED_POWER_GPIO_Port GPIOC
#define BOTAO_1_Pin GPIO_PIN_1
#define BOTAO_1_GPIO_Port GPIOA
#define BOTAO_2_Pin GPIO_PIN_2
#define BOTAO_2_GPIO_Port GPIOA
#define BOTAO_3_Pin GPIO_PIN_3
#define BOTAO_3_GPIO_Port GPIOA
#define BOTAO_4_Pin GPIO_PIN_4
#define BOTAO_4_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_12
#define BUZZER_GPIO_Port GPIOB
#define SINAL_1_Pin GPIO_PIN_15
#define SINAL_1_GPIO_Port GPIOA
#define SINAL_2_Pin GPIO_PIN_3
#define SINAL_2_GPIO_Port GPIOB
#define SINAL_3_Pin GPIO_PIN_4
#define SINAL_3_GPIO_Port GPIOB
#define SINAL_4_Pin GPIO_PIN_5
#define SINAL_4_GPIO_Port GPIOB
#define LED_STATUS_EXTERNO_Pin GPIO_PIN_7
#define LED_STATUS_EXTERNO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
