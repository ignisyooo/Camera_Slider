#include "motor.h"
#include "main.h"

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
			(sett->flags.reset) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(sett->Pin_Sleep.PORT, sett->Pin_Sleep.PIN,
			(sett->flags.sleep) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(sett->Pin_Direction.PORT, sett->Pin_Direction.PIN,
			(sett->flags.direction) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

MotorErr Motor_MicroPinSet(Motor_T *sett) {
	MotorErr retValue = MOTOR_OK;
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
	default:
		retValue = MOTOR_ERROR;
	}
	return retValue;
}

void Motor_Init(Motor_T *sett) {
	sett->flags.isOn = 0;
	sett->flags.reset = 0;
	sett->flags.direction = CW;
	sett->flags.sleep = 0;
	sett->flags.stepPhase = LOW;

	sett->counter.pulse = 0;
	sett->counter.stepLeft = 0;
	sett->device.positionStart = 0;
	sett->device.points_num=1;

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


void motorPause(Motor_T *sett)
{
	sett->flags.direction = 0;
	Motor_PinMode(sett);
}

void motorStop(Motor_T *sett)
{
	motorPause(sett);
	sett->flags.sleep = 0;
	sett->flags.reset = 1;
	Motor_PinMode(sett);
}
MotorErr motorRun(Motor_T *sett)
{
	MotorErr retval = MOTOR_OK;
	if(sett->flags.isOn && !sett->flags.reset && !sett->flags.sleep)
	{
		--(sett->counter.changeTime);
		if(sett->counter.changeTime<=0)
		{
			sett->counter.changeTime = sett->counter.pulse;
			--(sett->counter.stepLeft);
			if(sett->counter.stepLeft<=0)
			{
				sett->flags.isOn = 0;
				sett->flags.sleep = 1;
			}

			switch(sett->flags.stepPhase)
			{
			case HIGH:
				sett->flags.stepPhase = LOW;
				break;
			case LOW:
				sett->flags.stepPhase = HIGH;
				if(sett->flags.direction == CWC)
				{
					sett->data.position -= sett->device.stepSize;
				}
				else
				{
					sett->data.position += sett->device.stepSize;
				}
				break;
			default:
				retval = MOTOR_ERROR;
			}
			if(retval == MOTOR_OK)
			{
				Motor_PinMode(sett);
			}
		}
	}
	else
	{
		retval = MOTOR_ERROR;
	}

	return retval;
}
MotorErr motorStartMove(Motor_T *sett)
{
	if(sett->counter.stepLeft <=0 || sett->counter.pulse <=0)
	{
		return MOTOR_ERROR;
	}

	if(sett->flags.reset)
	{
		return MOTOR_ERROR;
	}

	if(sett->flags.stepPhase != LOW)
	{
		return MOTOR_ERROR;
	}

	sett->flags.sleep = 0;
	sett->flags.isOn = 1;

	Motor_PinMode(sett);

	return MOTOR_OK;
}
/*
void motor_run(Motor_T *sett)
{

	Motor_Update_1(sett);
	HAL_Delay(1);
	Motor_Update_2(sett);
	HAL_Delay(10);

	HAL_GPIO_WritePin(MOTOR1_STEP_GPIO_Port, MOTOR1_STEP_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(MOTOR1_STEP_GPIO_Port, MOTOR1_STEP_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);

}
*/
