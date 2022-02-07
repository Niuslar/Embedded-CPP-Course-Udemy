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
    Servo(pin_struct_t &servo_pin,
          TIM_TypeDef *TIMx,
          uint8_t gpio_AF_TIM_x,
          uint8_t pwm_channel);
};

#endif /* INC_SERVO_H_ */
