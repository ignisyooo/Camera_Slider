#ifndef MOTOR_H
#define MOTOR_H

#include "stm32f3xx_hal.h"
#include "main.h"

#define  MOTORS_NUM 3


typedef struct {
	GPIO_TypeDef *PORT;
	uint16_t PIN;
} IO_Pin;

typedef struct Motor_Tag {
	IO_Pin Pin_Reset;
	IO_Pin Pin_Sleep;
	IO_Pin Pin_Direction;
	IO_Pin Pin_Steep;
	IO_Pin MS1;
	IO_Pin MS2;
	IO_Pin MS3;



	struct {
		uint8_t isOn :1;
		uint8_t reset :1;
		uint8_t sleep :1;
		uint8_t direction :1;
	}flags;

	//struct Motor_Tag *motors[MOTORS_NUM];

	struct
	{
		uint8_t motor_num;
		double speed;
		uint8_t microstep;
		int positionStart;
	}device;
}Motor_T;

void Motor_Init(Motor_T* sett);
void Motor_PinMode(Motor_T *sets);
void Motor_MicroPinSet(Motor_T *sett);

#endif /* MOTOR_H */
