/*
 * servo.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: niuslar
 */

#include "servo.h"

Servo::Servo(TIM_HandleTypeDef &htim, uint8_t timer_channel)
{
    HAL_TIM_PWM_Start(&htim, timer_channel);
}
