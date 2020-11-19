#ifndef MOTOR_H
#define MOTOR_H

#include "stm32f3xx_hal.h"
#include "main.h"
#include "FIFO.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define MOTORS_NUM 3
#define MAX_POINTS 5
#define TIM_FREQ 1000
#define HIGH 1
#define LOW 0
#define CW 1
#define CWC 0
#define SLIDER_LENGHT 9000 //x*0.1 [mm]


typedef enum MotorErr_Tag {
	MOTOR_OK, MOTOR_ERROR, MOTOR_INTERRUPT_ERROR, MOTOR_TIMEOUT_ERROR
} MotorErr;

/*For now we use only 1 microstep*/
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
		uint8_t stepPhase :1;
	} flags;

	struct {
		uint16_t changeTime;
		int stepLeft;
		uint16_t pulse;
	} counter;

	struct {
		uint8_t points_num;
		uint8_t motor_num;
		float stepSize;
		uint8_t microstep;
		int16_t positionStart;
		int16_t positionEnd;
	} device;

	struct {
		int position;
		double speed;
	} data;

	Fifo_data *fifo;

} Motor_T;

void Motor_Init(Motor_T *sett);
void Motor_PinMode(Motor_T *sett);
MotorErr Motor_MicroPinSet(Motor_T *sett);
MotorErr motorRun(Motor_T *sett);
MotorErr motorStartMove(Motor_T *sett);
MotorErr motorStop(Motor_T *sett);
void prepareMotor(Motor_T *sett);
/* GET FLAGS VALUES */
bool Get_IsOn(Motor_T *sett);
bool Get_Dir(Motor_T *sett);
bool Get_Sleep(Motor_T *sett);
bool Get_Reset(Motor_T *sett);

#endif /* MOTOR_H */
