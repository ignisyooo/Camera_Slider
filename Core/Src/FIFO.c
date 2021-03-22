/*
 * FIFO.c
 *
 *  Created on: 17 paź 2020
 *      Author: rzeszutko
 */

#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t get_amount_of_times(Fifo_data *data)
{
	uint8_t size = 1;
	if (!data)
	{
		return 0;
	}
	while (data->next)
	{
		size++;
		data = data->next;
	}
	return size;
}

void read_data(Fifo_data **data, uint16_t *a, uint16_t *b)
{
	if (*data == NULL)
	{
		*a = 0;
		*b = 0;
	}
	else
	{
		Fifo_data *new = NULL;
		*a = (*data)->time;
		*b = (*data)->length;
		new = (*data)->next;
		free(*data);
		(*data) = new;
	}
}

static Fifo_data *getLast(Fifo_data *data)
{
	if (data)
	{
		while (data->next)
			data = data->next;
	}
	return data;
}

void write_data_to_FIFO(Fifo_data **data, uint16_t val, uint16_t len)
{
	if (*data)
	{
		Fifo_data *current = getLast(*data);
		current->next = (Fifo_data *)malloc(sizeof(Fifo_data));
		current->next->next = NULL;
		current->next->time = val;
		current->next->length = len;
	}
	else
	{
		(*data) = (Fifo_data *)malloc(sizeof(Fifo_data));
		(*data)->next = NULL;
		(*data)->time = val;
		(*data)->length = len;
	}
}
int read_time(Fifo_data *data)
{
	int time = 0;
	if (!data)
	{
		return 0;
	}
	else
	{
		while (data)
		{
			time += data->time;
			data = data->next;
		}
	}
	return time;
}
