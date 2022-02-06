/*
 * servo.h
 *
 *  Created on: Feb 6, 2022
 *      Author: niuslar
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "pin_map.h"

class Servo
{
private:
public:
    Servo(TIM_HandleTypeDef &htim, uint8_t timer_channel);
};

#endif /* INC_SERVO_H_ */
