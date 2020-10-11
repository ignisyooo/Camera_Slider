/*
 * Interrupt.c
 *
 *  Created on: Oct 6, 2020
 *      Author: rzeszutko
 */

#include "Interrupt.h"
#include "Objects.h"
#include "main.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM6) {
		static MotorErr retval = MOTOR_OK;
		for (int i = 0; i < MOTORS_NUM - 2; i++) {
			if (MOTOR_OK == retval) {
				retval = motorRun(&Motor_set[i]);
			} else if (MOTOR_INTERRUPT_ERROR == retval) {
				//do nothing
			}
		}
	}

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == LIMIT_SWITCH_Pin) {
		for (int i = 0; i < MOTORS_NUM; i++) {
			motorStop(Motor_set + i);
		}
	}
}
