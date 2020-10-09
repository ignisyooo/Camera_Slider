/*
 * Interrupt.c
 *
 *  Created on: Oct 6, 2020
 *      Author: rzesz
 */

#include "Interrupt.h"
#include "Objects.h"
#include "main.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	for (int i = 0; i < MOTORS_NUM - 2; i++) {
		if (Get_IsOn(&Motor_set[i])) {
			MotorRun(&Motor_set[i]);
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

