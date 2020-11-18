/*
 * Interrupt.c
 *
 *  Created on: Oct 6, 2020
 *      Author: rzeszutko
 */

#include "Interrupt.h"
#include "Objects.h"
#include "self_timer.h"
#include "main.h"
#include "parametr.h"

MotorErr retval = MOTOR_OK;

DataReadEnum DataRead = data_unavailable;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM6) {
		if(MOTOR_OK == retval)
		{
			for(int i=0;i<MOTORS_NUM;i++)
			{
				retval = motorRun(&Motor_set[i]);
			}
		}
		else if(MOTOR_INTERRUPT_ERROR == retval)
		{
			for(int i=0;i<MOTORS_NUM;i++)
			{
				if(i==0)
					retval = set(Motor_set);
				else
					retval = set_for_angle(&Motor_set[i]);
				motorStartMove(&Motor_set[i]);
			}
		}
		else
		{
			for(int i=0;i<MOTORS_NUM;i++)
			{
				motorStop(&Motor_set[i]);
			}
		}
	} else if (htim->Instance == TIM7) {
		static uint8_t state = 1;
		if (1 == state)
			state = run_trigger(&timer_T);
		else {
			// Do nothing
		}
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == LIMIT_SWITCH_Pin) {
		for (int i = 0; i < MOTORS_NUM; i++) {
			//motorStop(Motor_set + i);
		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART3) {
		static int idx=1;
		HAL_UART_Receive_IT(&huart3, (uint16_t*) (data+idx), 2);
		idx++;
		if((uint16_t)-2 == data[idx])
			DataRead = data_available;
		else
			DataRead= data_unavailable;
	}
}
