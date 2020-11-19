/*
 * parametr.c
 *
 *  Created on: 6 paź 2020
 *      Author: rzesz
 */

#include "parametr.h"
#include <stdio.h>
#include <stdint.h>

uint8_t komunikat[23];
uint16_t dl_kom;

void UART_Confirm(void) {
	dl_kom=0;
	dl_kom=sprintf((char*) komunikat, "Starting...");

	HAL_UART_Transmit_IT(&huart3, komunikat, dl_kom);
}

void UART_WriteData(Motor_T *data, uint16_t *tab, Trigger_T *time) {
	uint8_t i = 0;
	while ((uint16_t) -1 != tab[i])
		write_data_to_FIFO(&(data->fifo), tab[i++]);
	(data + 1)->device.positionStart = (int16_t) tab[++i];
	(data + 1)->device.positionEnd = (int16_t) tab[++i];
	i++;
	(data + 2)->device.positionStart = (int16_t) tab[++i];
	(data + 2)->device.positionEnd = (int16_t) tab[++i];
	i++;
	time->device = tab[++i];
	time->period = tab[++i];

	UART_Confirm();
}

DataReadEnum DataReceive(uint16_t *data)
{
	DataReadEnum retVal = data_unavailable;
	for(int i=0;i<UARTpoint;++i)
	{
		if(data[i] == (uint16_t)-2)
		{
			retVal = data_available;
		}
	}
	return retVal;
}
