#include "motor.h"
#include "main.h"

#define CW 1
#define CWC 0
/*********************************************
 * Microstep:
 *
 * 0 -> Full steep
 * 1 -> 1/2 steep
 * 2 -> 1/4 steep
 * 3 -> 1/8 steep
 * 4 -> 1/16 steep
 *
 * While init mircosteep is set to 0 ( Full steep)
 ********************************************/

void Motor_PinMode(Motor_T *sett) {
	HAL_GPIO_WritePin(sett->Pin_Steep.PORT, sett->Pin_Steep.PIN,
			(sett->flags.isOn) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(sett->Pin_Reset.PORT, sett->Pin_Reset.PIN,
			(sett->flags.reset) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(sett->Pin_Sleep.PORT, sett->Pin_Sleep.PIN,
			(sett->flags.sleep) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(sett->Pin_Direction.PORT, sett->Pin_Direction.PIN,
			(sett->flags.direction) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void Motor_MicroPinSet(Motor_T *sett) {
	switch (sett->device.microstep) {
	case 0:
		HAL_GPIO_WritePin(sett->MS1.PORT, sett->MS1.PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(sett->MS2.PORT, sett->MS2.PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(sett->MS3.PORT, sett->MS3.PIN, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(sett->MS1.PORT, sett->MS1.PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(sett->MS2.PORT, sett->MS2.PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(sett->MS3.PORT, sett->MS3.PIN, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(sett->MS1.PORT, sett->MS1.PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(sett->MS2.PORT, sett->MS2.PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(sett->MS3.PORT, sett->MS3.PIN, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(sett->MS1.PORT, sett->MS1.PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(sett->MS2.PORT, sett->MS2.PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(sett->MS3.PORT, sett->MS3.PIN, GPIO_PIN_RESET);
		break;

	case 4:
		HAL_GPIO_WritePin(sett->MS1.PORT, sett->MS1.PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(sett->MS2.PORT, sett->MS2.PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(sett->MS3.PORT, sett->MS3.PIN, GPIO_PIN_SET);
		break;
	}
}

void Motor_Init(Motor_T *sett) {
	sett->flags.isOn = 0;
	sett->flags.reset = 0;
	sett->flags.direction = CW;
	sett->flags.sleep = 1;

	sett->device.positionStart = 0;
	sett->device.speed = 0;

	sett->device.microstep = 0;
	Motor_PinMode(sett);
	Motor_MicroPinSet(sett);
}

bool Get_IsOn(Motor_T *sett)
{
	return sett->flags.isOn;
}
bool Get_Dir(Motor_T *sett)
{
	return sett->flags.direction;
}
bool Get_Sleep(Motor_T *sett)
{
	return sett->flags.sleep;
}
bool Get_Return(Motor_T *sett)
{
	return sett->flags.reset;
}

void Motor_Update(Motor_T *sett)
{
	//sett->flags.isOn=1;
	sett->flags.reset=1;
	sett->flags.sleep=1;
	Motor_PinMode(sett);
	//HAL_GPIO_WritePin(sett->Pin_Steep.PORT, sett->Pin_Steep.PIN, GPIO_PIN_SET);
	HAL_Delay(2);
}
