#ifndef MOTOR_H
#define MOTOR_H

#include "stm32f3xx_hal.h"
#include "main.h"
#include <stdbool.h>

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
		bool isOn :1;
		bool reset :1;
		bool sleep :1;
		bool direction :1;
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
void Motor_PinMode(Motor_T *sett);
void Motor_MicroPinSet(Motor_T *sett);
void Motor_Update(Motor_T *sett);
/* GET FLAGS VALUES */
bool Get_IsOn(Motor_T *sett);
bool Get_Dir(Motor_T *sett);
bool Get_Sleep(Motor_T *sett);
bool Get_Reset(Motor_T *sett);


#endif /* MOTOR_H */
