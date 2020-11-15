/*
 * self_timer.h
 *
 *  Created on: Oct 21, 2020
 *      Author: rzesz
 */

#ifndef INC_SELF_TIMER_H_
#define INC_SELF_TIMER_H_


/******************************
 *
 * SLR Camera device : 1
 * Mobile Camera device :0
 *
 *****************************/
#define FREQ_T 1000

#include "tim.h"
#include "Objects.h"
#include "FIFO.h"

typedef struct trigger_Tag
{
	IO_Pin Pin_Trigger;
	uint8_t isOn;
	uint8_t period;
	uint8_t device;
	int changeTime;
	int memTime;
	int Time;
}Trigger_T;

Trigger_T timer_T;
void device_choose(Trigger_T *trig);
int calculate_intterupts(Trigger_T *trig);
void init_t(Trigger_T *trig, Motor_T *sett);
uint8_t run_trigger(Trigger_T *trig);
void set_trigger(Trigger_T *trig, Motor_T *sett);


#endif /* INC_SELF_TIMER_H_ */


