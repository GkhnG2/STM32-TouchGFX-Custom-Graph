/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32h747i_discovery_qspi.h"
#include "stm32h747i_discovery_sdram.h"
#include "stm32h747i_discovery_bus.h"
#include "stm32h747i_discovery_errno.h"
#include "../Components/otm8009a/otm8009a.h"
//#include <TouchGFXGeneratedHAL.hpp>
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
extern int32_t DSI_IO_Write(uint16_t ChannelNbr, uint16_t Reg, uint8_t *pData, uint16_t Size);
extern int32_t DSI_IO_Read(uint16_t ChannelNbr, uint16_t Reg, uint8_t *pData, uint16_t Size);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_BL_Pin GPIO_PIN_12
#define LCD_BL_GPIO_Port GPIOJ
#define LCD_RESET_Pin GPIO_PIN_3
#define LCD_RESET_GPIO_Port GPIOG
/* USER CODE BEGIN Private defines */
#define LED1_Green_Pin  GPIO_PIN_12
#define LED1_Green_Port GPIOI
#define LED2_Orange_Pin  GPIO_PIN_13
#define LED2_Orange_Port GPIOI
#define LED3_Red_Pin  GPIO_PIN_14
#define LED3_Red_Port GPIOI
#define LED4_Blue_Pin  GPIO_PIN_15
#define LED4_Blue_Port GPIOI

#define JOY_SEL_Pin  GPIO_PIN_2
#define JOY_SEL_Port GPIOK
#define JOY_DOWN_Pin  GPIO_PIN_3
#define JOY_DOWN_Port GPIOK
#define JOY_LEFT_Pin  GPIO_PIN_4
#define JOY_LEFT_Port GPIOK
#define JOY_RIGHT_Pin  GPIO_PIN_5
#define JOY_RIGHT_Port GPIOK
#define JOY_UP_Pin  GPIO_PIN_6
#define JOY_UP_Port GPIOK
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
