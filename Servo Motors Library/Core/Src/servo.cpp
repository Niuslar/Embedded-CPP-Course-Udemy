/*
 * servo.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: niuslar
 */

#include "servo.h"

Servo::Servo(pin_struct_t &servo_pin,
             TIM_TypeDef *TIMx,
             uint8_t gpio_AF_TIM_x,
             uint8_t pwm_channel)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*Configure Servo pin */
    GPIO_InitStruct.Pin = servo_pin.gpio_pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = gpio_AF_TIM_x;
    HAL_GPIO_Init(servo_pin.gpio_port, &GPIO_InitStruct);

    /* TIM Config */
    TIM_OC_InitTypeDef sConfigOC = {0};
    TIM_HandleTypeDef htim;

    htim.Instance = TIMx;
    htim.Init.Prescaler = 10 - 1;
    htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim.Init.Period = 32000 - 1;
    htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    HAL_TIM_PWM_Init(&htim);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 2400;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, pwm_channel);

    /* Start PWM */
    HAL_TIM_PWM_Start(&htim, pwm_channel);
}
