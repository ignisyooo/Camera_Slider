/*
 * FIFO.h
 *
 *  Created on: 17 paź 2020
 *      Author: rzeszutko
 */

#ifndef INC_FIFO_H_
#define INC_FIFO_H_

#include <stdint.h>

typedef struct Fifo_data_Tag
{
	struct Fifo_data_Tag *next;
	uint16_t time;
	uint16_t length;
} Fifo_data;

uint8_t get_amount_of_times(Fifo_data *data);
void read_data(Fifo_data **data, uint16_t *a, uint16_t *b);
//Temporary function
static Fifo_data *getLast(Fifo_data *data);
void write_data_to_FIFO(Fifo_data **data, uint16_t val, uint16_t len);
int read_time(Fifo_data *data);

#endif /* INC_FIFO_H_ */
