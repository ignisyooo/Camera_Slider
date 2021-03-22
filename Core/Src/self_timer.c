/*
 * self_timer.c
 *
 *  Created on: Oct 21, 2020
 *      Author: rzeszutko
 */
#include "self_timer.h"

void device_choose(Trigger_T *trig) {
	trig->Pin_Trigger.PORT =
			(0 == trig->device) ? CAMERA_T_GPIO_Port : MOBILE_T_GPIO_Port;
	trig->Pin_Trigger.PIN = (0 == trig->device) ? CAMERA_T_Pin : MOBILE_T_Pin;
	HAL_GPIO_WritePin(trig->Pin_Trigger.PORT,trig->Pin_Trigger.PIN, GPIO_PIN_RESET);
}

int calculate_intterupts(Trigger_T *trig) {
	return (FREQ_T * trig->period);
}

uint8_t run_trigger(Trigger_T *trig) {
	uint32_t diff = trig->memTime-trig->changeTime;
	--(trig->changeTime);
	if (trig->changeTime <= 0) {
		trig->isOn = 1;
		--(trig->Time);
		trig->changeTime=trig->memTime;
		HAL_GPIO_WritePin(trig->Pin_Trigger.PORT,trig->Pin_Trigger.PIN, GPIO_PIN_SET);
		if(trig->Time<=0)
			HAL_TIM_Base_Stop_IT(&htim7);
	}
	if(diff==100 && trig->isOn)
	{
		trig->isOn=0;
		HAL_GPIO_WritePin(trig->Pin_Trigger.PORT,trig->Pin_Trigger.PIN, GPIO_PIN_RESET);
	}
	return 1;
}
void set_trigger(Trigger_T *trig, Motor_T *sett) {
	trig->Time = read_time(sett->fifo) / trig->period;
	trig->changeTime = calculate_intterupts(trig);
	trig->memTime = trig->changeTime;
}

void init_t(Trigger_T *trig, Motor_T *sett) {
	device_choose(trig);
	set_trigger(trig, sett);
	trig->isOn = 0;
}
