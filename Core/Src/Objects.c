/*
 * Objects.c
 *
 *  Created on: 3 paź 2020
 *      Author: rzeszutko
 */

#include "main.h"
#include "Objects.h"

char * MotorErr_string[4]={
		"MOTOR_OK",
		"MOTOR_ERROR",
		"MOTOR_INTERRUPT_ERROR",
		"MOTOR_TIMEOUT_ERROR"
};

Motor_T motor1 = {
		.Pin_Direction = { .PORT = MOTOR1_DIR_GPIO_Port, .PIN =
		MOTOR1_DIR_Pin },
		.Pin_Reset = { .PORT = MOTOR1_RESET_GPIO_Port, .PIN =
		MOTOR1_RESET_Pin },
		.Pin_Sleep = { .PORT = MOTOR1_SLEEP_GPIO_Port,
		.PIN = MOTOR1_SLEEP_Pin },
		.Pin_Steep = { .PORT = MOTOR1_STEP_GPIO_Port,
		.PIN = MOTOR1_STEP_Pin},

		.flags = {
				.isOn = 0,
				.reset = 0,
				.sleep = 0,
				.direction = 0,
		},

		.device = {
				.motor_num = 1,
				.microstep =1,
				.positionStart =1,
				.stepSize = 3.0,
		},
};
// Step size from motor2 is in degrees
Motor_T motor2 = {
				.Pin_Direction = { .PORT = MOTOR2_DIR_GPIO_Port, .PIN =
				MOTOR2_DIR_Pin },
				.Pin_Reset = { .PORT = MOTOR2_RESET_GPIO_Port, .PIN =
				MOTOR2_RESET_Pin },
				.Pin_Sleep = { .PORT = MOTOR2_SLEEP_GPIO_Port,
				.PIN = MOTOR2_SLEEP_Pin },
				.Pin_Steep = { .PORT = MOTOR2_STEP_GPIO_Port,
				.PIN = MOTOR2_STEP_Pin},

				.flags = {
						.isOn = 0,
						.reset = 0,
						.sleep = 0,
						.direction = 0,
				},

				.device = {
						.motor_num = 2,
						.microstep =1,
						.positionStart =1,
						.stepSize = 2.9,
				},
};

Motor_T motor3 = {
				.Pin_Direction = { .PORT = MOTOR3_DIR_GPIO_Port, .PIN =
				MOTOR3_DIR_Pin },
				.Pin_Reset = { .PORT = MOTOR3_RESET_GPIO_Port, .PIN =
				MOTOR3_RESET_Pin },
				.Pin_Sleep = { .PORT = MOTOR3_SLEEP_GPIO_Port,
				.PIN = MOTOR3_SLEEP_Pin },
				.Pin_Steep = { .PORT = MOTOR3_STEP_GPIO_Port,
				.PIN = MOTOR3_STEP_Pin},

				.flags = {
						.isOn = 0,
						.reset = 0,
						.sleep = 0,
						.direction = 0,
				},

				.device = {
						.motor_num = 3,
						.microstep =1,
						.positionStart =1,
						.stepSize = 2.9,
				},
};


void add_motors(Motor_T *sett)
{
	sett[0]=motor1;
	sett[1]=motor2;
	sett[2]=motor3;
}


