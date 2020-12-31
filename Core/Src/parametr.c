/*
 * parametr.c
 *
 *  Created on: 6 paź 2020
 *      Author: rzesz
 */

#include "parametr.h"
#include <stdio.h>
#include <stdint.h>



void UART_Confirm(void) {
	msg_size = 0;
	msg_size = sprintf((char*) msg, "get");

	HAL_UART_Transmit(&huart3, msg, msg_size, 10);
}

void UART_startmove(void) {
	msg_size2 = 0;
	msg_size2 = sprintf((char*) msg_v2, "start");

	HAL_UART_Transmit(&huart3, msg_v2, msg_size2, 10);
}

void UART_WriteData(Motor_T *data, uint16_t *tab, Trigger_T *time) {
	uint8_t i = 0;
	for (int j = 0; j < MOTORS_NUM; j++) {
		while ((uint16_t) -1 != tab[i]) {
			write_data_to_FIFO(&((data+j)->fifo), tab[i], tab[++i]);
			i++;
		}
		i++;
	}
	time->device = tab[i++];
	time->period = tab[i];

	UART_Confirm();
}

DataReadEnum DataReceive(uint16_t *data) {
	DataReadEnum retVal = data_unavailable;
	for (int i = 0; i < UARTpoint; ++i) {
		if (data[i] == (uint16_t) -2) {
			retVal = data_available;
		} else if (data[i] == (uint16_t) -3) {
			retVal = data_confirm;
		} else if (data[i] == (uint16_t) -4) {
			retVal = data_stop;
		}
	}
	return retVal;
}
