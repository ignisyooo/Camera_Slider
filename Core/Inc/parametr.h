/*
 * parametr.h
 *
 *  Created on: 6 paź 2020
 *      Author: rzeszutko
 */
#ifndef INC_PARAMETR_H_
#define INC_PARAMETR_H_

#include "Objects.h"
#include "main.h"
#include "FIFO.h"
#include "usart.h"
#include "self_timer.h"

#define UARTpoint 35

typedef HAL_StatusTypeDef ErrUart;

volatile uint16_t data[UARTpoint];

typedef enum
{
	data_available,
	data_unavailable,
	data_confirm,
	data_stop
}DataReadEnum;

uint8_t msg[20];
uint16_t msg_size;
uint8_t msg_v2[10];
uint16_t msg_size2;



void UART_WriteData(Motor_T *data, uint16_t *tab, Trigger_T *time);
void UART_Confirm(void);
void UART_startmove(void);
DataReadEnum DataReceive(uint16_t *data);
#endif /* INC_PARAMETR_H_ */
