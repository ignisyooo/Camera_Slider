/*
 * setter.c
 *
 *  Created on: Oct 9, 2020
 *      Author: rzesz
 */
#include "setter.h"

void set(Motor_T *sett)
{
	sett->counter.pulse = 200;
	sett->counter.changeTime =sett->counter.pulse;



}

