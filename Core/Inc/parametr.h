/*
 * parametr.h
 *
 *  Created on: 6 paź 2020
 *      Author: rzesz
 */
#ifndef INC_PARAMETR_H_
#define INC_PARAMETR_H_

#include "Objects.h"
#include "main.h"
#include "usart.h"


typedef HAL_StatusTypeDef ErrUart;

uint8_t points[MOTORS_NUM], data[MAX_POINTS];


ErrUart Uart_readData(Motor_T *sett);
ErrUart Uart_write_data_to_Motor_T(Motor_T *sett, ErrUart ret, uint8_t points, uint8_t speed, int idx);
#endif /* INC_PARAMETR_H_ */
