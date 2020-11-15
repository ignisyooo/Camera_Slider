/*
 * parametr.c
 *
 *  Created on: 6 paź 2020
 *      Author: rzesz
 */

#include "main.h"
#include "parametr.h"
#include <stdio.h>

ErrUart Uart_readData(Motor_T *sett) {
	uint8_t wyraz[50];
	uint16_t size = 0;
	ErrUart retval = HAL_OK;
	bool send = false;
	bool receive = false;

	for (int i = 0; i < MOTORS_NUM - 2; i++) {
		size = sprintf(wyraz, "Enter the numbers of stop points: \n\r");

		while (retval != HAL_OK && send) {
			retval = HAL_UART_Transmit_IT(&huart3, wyraz, size);
			send = true;
		}
		while (retval != HAL_OK && !receive) {
			retval = HAL_UART_Receive_IT(&huart3, &points[i], sizeof(uint8_t));
			receive = true;
		}
		for (int j = 0; j < points[i]; j++) {
			send = false;
			receive = true;
			size = sprintf(wyraz, "Enter the speed from point %d to %d: \n\r",
					j, j + 1);
			while (retval != HAL_OK && !send) {
				retval = HAL_UART_Transmit_IT(&huart3, wyraz, size);
				send = true;
			}
			while (retval != HAL_OK && !receive) {
				retval = HAL_UART_Receive_IT(&huart3, data[j], sizeof(uint8_t));
				receive = true;
			}
			Uart_write_data_to_Motor_T(sett + i, retval, points[j], data[j], j);

		}
	}

	return retval;
}

ErrUart Uart_write_data_to_Motor_T(Motor_T *sett, ErrUart ret, uint8_t points,
		uint8_t speed, int idx) {
	if (ret != HAL_OK) {
		return ret;
	} else {
		//sett->device.speed[idx] = speed;
		sett->device.points_num = points;
	}
	return ret;
}

