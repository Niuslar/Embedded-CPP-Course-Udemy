/*
 * cpp_link.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: niuslar
 */

#include "lcd.h"
#include "main.h"

#ifdef __cplusplus

extern "C"
{
#endif

    void cpp_main(void)
    {
        /* Main implementation */

        pin_struct_t lcd_rs = {LCD_RS_GPIO_Port, LCD_RS_Pin};
        pin_struct_t lcd_en = {LCD_EN_GPIO_Port, LCD_EN_Pin};
        pin_struct_t lcd_d4 = {LCD_D4_GPIO_Port, LCD_D4_Pin};
        pin_struct_t lcd_d5 = {LCD_D5_GPIO_Port, LCD_D5_Pin};
        pin_struct_t lcd_d6 = {LCD_D6_GPIO_Port, LCD_D6_Pin};
        pin_struct_t lcd_d7 = {LCD_D7_GPIO_Port, LCD_D7_Pin};

        CLCD lcd_1(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7);

        lcd_1.print('N');
        lcd_1.setCursor(0, 0);

        uint8_t number = 0;

        while (1)
        {
            lcd_1.print(number);
            lcd_1.setCursor(0, 0);
            number++;
            HAL_Delay(100);
        }
    }

#ifdef __cplusplus
}
#endif
