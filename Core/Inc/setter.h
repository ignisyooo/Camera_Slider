/*
 * setter.h
 *
 *  Created on: Oct 9, 2020
 *      Author: rzesz
 */

#ifndef INC_SETTER_H_
#define INC_SETTER_H_

#include "Objects.h"

MotorErr set(Motor_T *sett);
uint16_t set_stepLeft(uint16_t len, int step);
uint16_t set_pulse(uint16_t time, uint16_t (*fun)(uint16_t len, int step), uint16_t len, int step);

#endif /* INC_SETTER_H_ */
