/*
 * servo.h
 *
 *  Created on: Feb 6, 2022
 *      Author: niuslar
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "pin_map.h"

enum
{
    SERVO_RIGHT_POS = 1440,
    SERVO_CENTRE_POS = 2400,
    SERVO_LEFT_POS = 3360
};

class Servo
{
private:
    TIM_HandleTypeDef htim;
    uint8_t pwm_ch;

public:
    Servo(pin_struct_t &servo_pin,
          TIM_TypeDef *TIMx,
          uint8_t gpio_AF_TIM_x,
          uint8_t pwm_channel);
    void turnShaft(uint32_t position);
};

#endif /* INC_SERVO_H_ */
