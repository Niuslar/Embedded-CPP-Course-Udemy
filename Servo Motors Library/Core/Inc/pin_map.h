/*
 * pin_map.h
 *
 *  Created on: Feb 6, 2022
 *      Author: niuslar
 */

#ifndef INC_PIN_MAP_H_
#define INC_PIN_MAP_H_

#include "main.h"

typedef struct
{
	GPIO_TypeDef* gpio_port;
	uint16_t 	gpio_pin;
}pin_struct_t;


#endif /* INC_PIN_MAP_H_ */
