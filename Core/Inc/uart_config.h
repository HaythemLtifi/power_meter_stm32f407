/*
 * uart_config.h
 *
 *  Created on:
 *      Author: haythem
 */

#ifndef CONFIG_UART_CONFIG_H_
#define CONFIG_UART_CONFIG_H_

UART_HandleTypeDef huart3;
osMutexId uart_mutexHandle;
static void MX_USART3_UART_Init(void);
static void MX_USART3_UART_Init(void)
{


  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }


}






#endif /* CONFIG_UART_CONFIG_H_ */
