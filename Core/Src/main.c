/*
 * main.c
 *
 *  Created on:
 *      Author: haythem
 */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h" // this is need for the freeRtos
#include <stdio.h>
#include "adc_config.h"
#include "uart_config.h"
#include "func.h"
#include "gipio_config.h"






osThreadId thread0Handle;
osThreadId thread1Handle;
osThreadId thread2Handle;
osThreadId theard3Handle;





void thread0_func(void const * argument);
void thread1_func(void const * argument);
void thread2_func(void const * argument);
void theard3_func(void const * argument);



typedef  uint32_t TaskProfiler ;
TaskProfiler Thread_0,Thread_1,Thread_2,Thead_3;


char str[7];

int main(void)
{

  HAL_Init();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART3_UART_Init();
  MX_ADC1_Init();
  SystemClock_Config();
  osMutexDef(uart_mutex);
  uart_mutexHandle = osMutexCreate(osMutex(uart_mutex));
  HAL_ADC_Start_DMA(&hadc1, sensor_value, 2);


  /* Create the thread(s) */

  /* definition and creation of thread0 */
  osThreadDef(thread0, thread0_func, osPriorityNormal, 0, 128);
  thread0Handle = osThreadCreate(osThread(thread0), NULL);

  /* definition and creation of thread1 */
  osThreadDef(thread1, thread1_func, osPriorityNormal, 0, 128);
  thread1Handle = osThreadCreate(osThread(thread1), NULL);
  /* definition and creation of thread2 */
  osThreadDef(thread2, thread2_func, osPriorityNormal, 0, 128);
  thread2Handle = osThreadCreate(osThread(thread2), NULL);

  /* definition and creation of theard3 */
  osThreadDef(theard3, theard3_func, osPriorityNormal, 0, 128);
  theard3Handle = osThreadCreate(osThread(theard3), NULL);
  osKernelStart();

  while (1)
  { }

}


void thread0_func(void const * argument)
{

  for(;;)
  {Thread_0++;
   current =  current_value(sensor_value[0]);
   voltage = voltage_value(sensor_value[1]);
    osDelay(1);
  }

}




void thread1_func(void const * argument)
{


  for(;;)
  { Thread_1++;
	power = power_value(current,voltage);
    osDelay(1);
  }

}


void thread2_func(void const * argument)
{


  for(;;)
  {	 Thread_2++;

	 int txlength = sprintf(str, "%ld\r\n", power);
     HAL_UART_Transmit(&huart3, (uint8_t*)(&str), txlength, 100);
    osDelay(1);
  }

}

void theard3_func(void const * argument)
{


  for(;;)
  {
    osDelay(1);
  }

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

  if (htim->Instance == TIM3) {
    HAL_IncTick();
  }

}


void Error_Handler(void)
{

}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif


