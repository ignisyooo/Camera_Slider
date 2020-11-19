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
#include "FIFO.h"
#include "usart.h"
#include "self_timer.h"

#define UARTpoint 15

typedef HAL_StatusTypeDef ErrUart;

volatile uint16_t data[UARTpoint];

typedef enum
{
	data_available,
	data_unavailable
}DataReadEnum;


void UART_WriteData(Motor_T *data, uint16_t *tab, Trigger_T *time);
void UART_Confirm(void);
DataReadEnum DataReceive(uint16_t *data);
#endif /* INC_PARAMETR_H_ */
