/*
 * Objects.h
 *
 *  Created on: 3 paź 2020
 *      Author: rzeszutko
 */

#ifndef INC_OBJECTS_H_
#define INC_OBJECTS_H_

#include "motor.h"
#include "tim.h"


/*
char * MotorErr_string[4]={
		"MOTOR_OK",
		"MOTOR_ERROR",
		"MOTOR_INTERRUPT_ERROR",
		"MOTOR_TIMEOUT_ERROR"
};
*/
void add_motors(Motor_T * sett);

Motor_T Motor_set[MOTORS_NUM];

MotorErr Err_Mode;






#endif /* INC_OBJECTS_H_ */
