/*
 * parametr.c
 *
 *  Created on: 6 paź 2020
 *      Author: rzesz
 */

#include "parametr.h"
#include <stdio.h>
#include <stdint.h>

void UART_WriteData(Motor_T *data, uint16_t *tab, Trigger_T *time)
{
	uint8_t i=0;
	while((uint16_t)-1 != tab[i++])
		write_data_to_FIFO(*data->fifo, tab[i]);
	(data+1)->device.positionStart = (int16_t)tab[++i];
	(data+1)->device.positionEnd = (int16_t)tab[++i];
	i++;
	(data+2)->device.positionStart = (int16_t)tab[++i];
	(data+2)->device.positionEnd = (int16_t)tab[++i];
	i++;
	time->device = tab[++i];
	time->period = tab[++1];

}
