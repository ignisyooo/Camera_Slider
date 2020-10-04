/*
 * Objects.c
 *
 *  Created on: 3 paź 2020
 *      Author: rzeszutko
 */

#include "main.h"
#include "Objects.h"

Motor_T motor1 = {
		.Pin_Direction = { .PORT = MOTOR1_DIR_GPIO_Port, .PIN =
		MOTOR1_DIR_Pin },
		.Pin_Reset = { .PORT = MOTOR1_RESET_GPIO_Port, .PIN =
		MOTOR1_RESET_Pin },
		.Pin_Sleep = { .PORT = MOTOR1_SLEEP_GPIO_Port,
		.PIN = MOTOR1_SLEEP_Pin },
		.Pin_Steep = { .PORT = MOTOR1_STEP_GPIO_Port,
		.PIN = MOTOR1_STEP_GPIO_Port },
		.MS1 = { .PORT = MOTOR1_MS1_GPIO_Port,
		. PIN = MOTOR1_MS1_Pin },
		.MS2 = { .PORT = MOTOR1_MS2_GPIO_Port, . PIN =
		MOTOR1_MS2_Pin },
		.MS3 = { .PORT = MOTOR1_MS3_GPIO_Port, . PIN =
		MOTOR1_MS3_Pin },

		.flags = {
				.isOn = 0,
				.reset = 0,
				.sleep = 0,
				.direction = 0,
		},

		.device = {
				.motor_num = 1,
				.speed = 0,
				.microstep =1,
				.positionStart =1,
		},
};

void add_motors(Motor_T *sett)
{
	sett[0]=&motor1;
	sett[1]=&motor2;
	sett[2]=&motor3;
}

