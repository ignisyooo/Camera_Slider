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

int poteg(int base, uint8_t pot) {
    if (pot == 0)
        return 1;
    else if (pot % 2)
        return base * poteg(base, pot - 1);
    else {
        int temp = poteg(base, pot / 2);
        return temp * temp;
    }
}

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
	float stepSize = sett->device.stepSize;
	sett->counter.stepLeft = set_stepLeft(len, stepSize, micro);
	//int (*fun)(uint16_t, int) = &set_stepLeft;
	int stepLeftx2 = sett->counter.stepLeft;
	sett->counter.pulse = set_pulse(time, stepLeftx2);
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
	sett->flags.direction = (sett->device.positionEnd>sett->device.positionStart)? CW:CWC;
	float stepSize = sett->device.stepSize;
	sett->counter.stepLeft = set_stepLeft(diff, stepSize, micro);
	int stepLeftx2 = sett->counter.stepLeft;
	sett->counter.pulse = set_pulse(time, stepLeftx2);
	sett->counter.changeTime = sett->counter.pulse;

	return retVal;
}
int set_stepLeft(uint16_t len, float step, uint8_t micro) {
	return (ceil((2 *10* len) / step)* poteg(2,micro));
}
uint16_t set_pulse(uint16_t time, int stepleft) {
	return (ceil(TIM_FREQ * time) / stepleft);
}

