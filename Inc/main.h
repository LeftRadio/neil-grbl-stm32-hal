/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#define IN_1_Pin GPIO_PIN_0
#define IN_1_GPIO_Port GPIOA
#define IN_1_EXTI_IRQn EXTI0_IRQn
#define IN_2_Pin GPIO_PIN_1
#define IN_2_GPIO_Port GPIOA
#define IN_2_EXTI_IRQn EXTI1_IRQn
#define IN_3_Pin GPIO_PIN_2
#define IN_3_GPIO_Port GPIOA
#define IN_3_EXTI_IRQn EXTI2_IRQn
#define IN_4_Pin GPIO_PIN_3
#define IN_4_GPIO_Port GPIOA
#define IN_4_EXTI_IRQn EXTI3_IRQn
#define IN_5_Pin GPIO_PIN_4
#define IN_5_GPIO_Port GPIOA
#define IN_5_EXTI_IRQn EXTI4_IRQn
#define STEPPER_XP_Pin GPIO_PIN_5
#define STEPPER_XP_GPIO_Port GPIOA
#define STEPPER_XD_Pin GPIO_PIN_6
#define STEPPER_XD_GPIO_Port GPIOA
#define STEPPER_YP_Pin GPIO_PIN_7
#define STEPPER_YP_GPIO_Port GPIOA
#define STEPPER_YD_Pin GPIO_PIN_0
#define STEPPER_YD_GPIO_Port GPIOB
#define STEPPER_ZP_Pin GPIO_PIN_1
#define STEPPER_ZP_GPIO_Port GPIOB
#define STEPPER_ZD_Pin GPIO_PIN_10
#define STEPPER_ZD_GPIO_Port GPIOB
#define STEPPER_AP_Pin GPIO_PIN_11
#define STEPPER_AP_GPIO_Port GPIOB
#define STEPPER_AD_Pin GPIO_PIN_12
#define STEPPER_AD_GPIO_Port GPIOB
#define STEPPER_XY_EN_Pin GPIO_PIN_13
#define STEPPER_XY_EN_GPIO_Port GPIOB
#define STEPPER_BP_Pin GPIO_PIN_14
#define STEPPER_BP_GPIO_Port GPIOB
#define STEPPER_BD_Pin GPIO_PIN_15
#define STEPPER_BD_GPIO_Port GPIOB
#define OUT_1_FWD_SPDINDLE_Pin GPIO_PIN_8
#define OUT_1_FWD_SPDINDLE_GPIO_Port GPIOA
#define OUT_2_Pin GPIO_PIN_9
#define OUT_2_GPIO_Port GPIOA
#define PWM_SPINDLE_Pin GPIO_PIN_10
#define PWM_SPINDLE_GPIO_Port GPIOA
#define OUT_4_Pin GPIO_PIN_15
#define OUT_4_GPIO_Port GPIOA
#define OUT_3_Pin GPIO_PIN_3
#define OUT_3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
