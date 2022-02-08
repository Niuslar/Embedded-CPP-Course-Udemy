/*
 * lcd.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: niuslar
 */

#include "lcd.h"

enum LCD_COMMANDS
{
    FUNCTION_SET_8BIT = 0x03,
    FUNCTION_SET_4BIT = 0x02,
    FUNCTION_SET_2LINE_5X8DOTS = 0x28,
    CLEAR_DISPLAY = 0x01,
    DISPLAY_ON_CURSOR_ON = 0x0E,
    DISPLAY_ON_CURSOR_OFF = 0x0C,
    ENTRY_MODE_INCREMENT_CURSOR = 0x06
};

uint8_t ddram_addres[2][16] = {{0x00,
                                0x01,
                                0x02,
                                0x03,
                                0x04,
                                0x05,
                                0x06,
                                0x07,
                                0x08,
                                0x09,
                                0x0A,
                                0x0B,
                                0x0C,
                                0x0D,
                                0x0E,
                                0x0F},
                               {0x40,
                                0x41,
                                0x42,
                                0x43,
                                0x44,
                                0x45,
                                0x46,
                                0x47,
                                0x48,
                                0x49,
                                0x4A,
                                0x4B,
                                0x4C,
                                0x4D,
                                0x4E,
                                0x4F}};

void CLCD::writeByte(GPIO_PinState rs_state, char byte)
{
    /* Set RS pin to write instruction or data */
    HAL_GPIO_WritePin(rs.gpio_port, rs.gpio_pin, rs_state);

    /* Send High Nibble */
    CLCD::writeNibble((byte >> 4) & 0x0F);

    /* Send Low Nibble */
    CLCD::writeNibble(byte & 0x0F);
}

void CLCD::writeBytes(const char *p_data)
{
    while (*p_data != '\0')
    {
        CLCD::writeByte(GPIO_PIN_SET, *p_data);
        p_data++;
    }
}

void CLCD::writeNibble(char nibble)
{
    const GPIO_PinState gpio_pin_states[2] = {GPIO_PIN_RESET, GPIO_PIN_SET};
    for (uint8_t bit = 0; bit < 4; bit++)
    {
        uint8_t pin_state = (nibble >> bit) & 1;

        HAL_GPIO_WritePin(data_pin[bit].gpio_port,
                          data_pin[bit].gpio_pin,
                          gpio_pin_states[pin_state]);
    }

    /* High to low pulse on EN pin to trasnfer nibble */
    HAL_GPIO_WritePin(en.gpio_port, en.gpio_pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(en.gpio_port, en.gpio_pin, GPIO_PIN_RESET);
    HAL_Delay(1);
}

CLCD::CLCD(pin_struct_t &RS,
           pin_struct_t &EN,
           pin_struct_t &D4,
           pin_struct_t &D5,
           pin_struct_t &D6,
           pin_struct_t &D7)
{
    /* Private variables initialisation */
    rs = RS;
    en = EN;
    data_pin[0] = D4;
    data_pin[1] = D5;
    data_pin[2] = D6;
    data_pin[3] = D7;

    /* LCD Initialisation sequence */

    /* Power on delay of at least 15 ms */
    HAL_Delay(16);

    /* Set RS pin to write instructions */
    HAL_GPIO_WritePin(rs.gpio_port, rs.gpio_pin, GPIO_PIN_RESET);

    /* Function set mode */
    CLCD::writeByte(GPIO_PIN_RESET, FUNCTION_SET_8BIT);

    /* Wait for more than 4.1 ms */
    HAL_Delay(5);

    /* Function set mode */
    CLCD::writeByte(GPIO_PIN_RESET, FUNCTION_SET_8BIT);

    /* wait more than 100us */
    HAL_Delay(1);

    /* 4-bit operation commands */
    uint8_t four_bit_cmd_settings[5] = {FUNCTION_SET_4BIT,
                                        FUNCTION_SET_2LINE_5X8DOTS,
                                        CLEAR_DISPLAY,
                                        DISPLAY_ON_CURSOR_OFF,
                                        ENTRY_MODE_INCREMENT_CURSOR};

    for (uint8_t cmd = 0; cmd < 5; cmd++)
    {
        CLCD::writeByte(GPIO_PIN_RESET, four_bit_cmd_settings[cmd]);
    }
}

/* Row and column indexes start from 0 */
void CLCD::setCursor(uint8_t row, uint8_t columns)
{
    if (row > 1 || columns > 15)
    {
        /* Exit method */
        return;
    }

    uint8_t ddram_addr = ddram_addres[row][columns];

    char byte = (1 << 7) | ddram_addr;

    CLCD::writeByte(GPIO_PIN_RESET, byte);
}

void CLCD::print(char data)
{
    CLCD::writeByte(GPIO_PIN_SET, data);
}

void CLCD::print(const char *p_data)
{
    CLCD::writeBytes(p_data);
}
