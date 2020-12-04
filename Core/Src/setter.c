/*
 * setter.c
 *
 *  Created on: Oct 9, 2020
 *      Author: rzesz
 */
#include "setter.h"
#include <math.h>

static uint8_t stoppingPoint;
uint16_t time;

MotorErr set(Motor_T *sett) {
	MotorErr retVal = MOTOR_OK;
	uint16_t len;
	uint8_t micro = sett->device.microstep;
	if (sett->device.points_num == (uint8_t) -1)
		sett->device.points_num = get_amount_of_times(sett->fifo);
	stoppingPoint = sett->device.points_num;
	read_data(&(sett->fifo), &time, &len);
	if (!time) {
		return MOTOR_ERROR;
	}
	//uint16_t length = round(len / sett->device.points_num);
	int stepSize = sett->device.stepSize;
	sett->counter.stepLeft = set_stepLeft(len, stepSize);
	//int (*fun)(uint16_t, int) = &set_stepLeft;
	int stepLeftx2 = sett->counter.stepLeft;
	sett->counter.pulse = set_pulse(time, stepLeftx2, micro);
	sett->counter.changeTime = sett->counter.pulse;

	return retVal;
}
MotorErr set_for_angle(Motor_T *sett) {
	MotorErr retVal = MOTOR_OK;
	uint8_t micro = sett->device.microstep;
	if (sett->device.points_num == (uint8_t) -1)
		sett->device.points_num = stoppingPoint;
	read_data(&(sett->fifo), &(sett->device.positionStart), &(sett->device.positionEnd));
	if (sett->device.positionStart != 0 && sett->counter.pulse == 0)
		prepareMotor(sett);
	if (time == 0)
		return MOTOR_ERROR;
	uint16_t diff = abs(sett->device.positionEnd - sett->device.positionStart);
	int stepSize = sett->device.stepSize;
	sett->counter.stepLeft = set_stepLeft(diff / stoppingPoint, stepSize);
	int stepLeftx2 = sett->counter.stepLeft;
	sett->counter.pulse = set_pulse(time, stepLeftx2, micro);
	sett->counter.changeTime = sett->counter.pulse;

	return retVal;
}
int set_stepLeft(uint16_t len, int step) {
	return ceil((2 *10* len) / step);
}
uint16_t set_pulse(uint16_t time, int stepleft, uint8_t micro) {
	return ((ceil(TIM_FREQ * time) / stepleft) * pow(2, micro));
}

