/*
 * hc05.h
 *
 *  Created on: Feb 7, 2022
 *      Author: niuslar
 */

#ifndef INC_HC05_H_
#define INC_HC05_H_

#include "pin_map.h"

class HC05
{
private:
    UART_HandleTypeDef huart;

public:
    HC05(pin_struct_t &uart_pin,
         uint8_t gpio_AF_UARTx,
         USART_TypeDef *USARTx,
         uint32_t mode);

    char getChar(void);
};

#endif /* INC_HC05_H_ */
