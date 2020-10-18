/*
 * setter.c
 *
 *  Created on: Oct 9, 2020
 *      Author: rzesz
 */
#include "setter.h"
#include <math.h>

MotorErr set(Motor_T *sett) {
	MotorErr retVal = MOTOR_OK;
	if(sett->device.points_num == -1)
		sett->device.points_num = get_amount_of_times(sett->fifo);
	uint16_t time = read_data(&(sett->fifo));
	if(time == 0)
	{
		return MOTOR_ERROR;
	}
	uint16_t length = round(SLIDER_LENGHT / sett->device.points_num);
	int stepSize = sett->device.stepSize;
	sett->counter.stepLeft = set_stepLeft(length, stepSize);
	sett->counter.changeTime = sett->counter.stepLeft;
	sett->counter.pulse = set_pulse(time, set_stepLeft(length, stepSize), length, stepSize);

	return retVal;
}
uint16_t set_stepLeft(uint16_t len, int step)
{
	return round((2*len*10)/step);
}
uint16_t set_pulse(uint16_t time, uint16_t (*fun)(uint16_t len, int step), uint16_t len, int step)
{
	return round((TIM_FREQ/fun(len, step))*time);
}


