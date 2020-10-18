/*
 * FIFO.c
 *
 *  Created on: 17 paź 2020
 *      Author: rzeszutko
 */

#include "FIFO.h"
#include <stdio.h>

uint8_t get_amount_of_times(Fifo_data *data) {
	uint8_t size = 1;
	if (!data) {
		return 0;
	}
	while (data->next) {
		size++;
		data = data->next;
	}
	return size;
}

uint16_t read_data(Fifo_data **data) {
	uint16_t retVal;
	if (*data) {
		return -1;
	} else {
		Fifo_data *new = NULL;
		retVal = (*data)->time;
		new = (*data)->next;
		free(*data);
		(*data) = new;
		return retVal;
	}
}

// Temporary function
Fifo_data *getLast(Fifo_data *data)
{
	if(data)
	{
		while(data->next)
			data=data->next;
	}
	return data;
}
void write_data_to_FIFO(Fifo_data **data, uint16_t val)
{
	if(*data)
	{
		Fifo_data * current =getLast(*data);
		current->next=(Fifo_data *)malloc(sizeof(Fifo_data));
		current->next->next = NULL;
		current->next->time= val;
	}
	else
	{
		(*data)=(Fifo_data*)malloc(sizeof(Fifo_data));
		(*data)->next=NULL;
		(*data)->time=val;
	}
}
