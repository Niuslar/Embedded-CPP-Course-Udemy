/*
 * hc05.cpp
 *
 *  Created on: Feb 7, 2022
 *      Author: niuslar
 */

#include "hc05.h"

HC05::HC05(pin_struct_t &uart_pin,
           uint8_t gpio_AF_UARTx,
           USART_TypeDef *USARTx,
           uint32_t mode)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Config */
    GPIO_InitStruct.Pin = uart_pin.gpio_pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = gpio_AF_UARTx;
    HAL_GPIO_Init(uart_pin.gpio_port, &GPIO_InitStruct);

    /* UART Config */
    huart.Instance = USARTx;
    huart.Init.BaudRate = 9600;
    huart.Init.WordLength = UART_WORDLENGTH_8B;
    huart.Init.StopBits = UART_STOPBITS_1;
    huart.Init.Parity = UART_PARITY_NONE;
    huart.Init.Mode = mode;
    huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart.Init.OverSampling = UART_OVERSAMPLING_16;
    huart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

    HAL_UART_Init(&huart);
}

char HC05::getChar(void)
{
    /* Read Receive Data Register */
    char data = (char)huart.Instance->RDR;
    return data;
}
