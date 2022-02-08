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
};

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

    /* Function set mode */

    /* Wait 5 ms */
    HAL_Delay(5);

    /* Function set mode */

    /* wait more than 100us */
    HAL_Delay(1);
}
