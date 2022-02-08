/*
 * lcd.h
 *
 *  Created on: Feb 8, 2022
 *      Author: niuslar
 */

#ifndef LCD_H_
#define LCD_H_

#include "pin_map.h"

class CLCD
{
private:
    pin_struct_t rs;
    pin_struct_t en;
    pin_struct_t data_pin[4];

    void writeNibble(char byte);
    void writeByte(GPIO_PinState rs_state, char byte);

public:
    CLCD(pin_struct_t &RS,
         pin_struct_t &EN,
         pin_struct_t &D4,
         pin_struct_t &D5,
         pin_struct_t &D6,
         pin_struct_t &D7);
};

#endif /* LCD_H_ */
