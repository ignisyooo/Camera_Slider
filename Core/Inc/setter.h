/*
 * setter.h
 *
 *  Created on: Oct 9, 2020
 *      Author: rzesz
 */

#ifndef INC_SETTER_H_
#define INC_SETTER_H_

#include "Objects.h"

int poteg(int base, uint8_t pot);
MotorErr set(Motor_T *sett);
int set_stepLeft(uint16_t len, float step, uint8_t micro);
uint16_t set_pulse(uint16_t time, int stepleft);
MotorErr set_for_angle(Motor_T *sett);


#endif /* INC_SETTER_H_ */
