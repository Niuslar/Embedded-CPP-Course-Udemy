
#include "hc05.h"
#include "main.h"
#include "servo.h"

#ifdef __cplusplus
extern "C"
{
#endif
    void cpp_main()
    {
        HAL_Init();

        char bluetooth_data = '\0';

        /* GPIO Ports Clock Enable */
        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOH_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        /* Pin structs */
        pin_struct_t PA0 = {GPIOA, GPIO_PIN_0};
        pin_struct_t PA10 = {GPIOA, GPIO_PIN_10};

        /* Servo instances */
        static Servo servo_1(PA0, TIM2, GPIO_AF2_TIM2, TIM_CHANNEL_1);

        /* Create bluetooth instance */
        HC05 bluetooth_1(PA10, GPIO_AF4_USART1, USART1, UART_MODE_RX);

        while (1)
        {
            bluetooth_data = bluetooth_1.getChar();

            if (bluetooth_data == 'l')
            {
                servo_1.turnShaft(SERVO_LEFT_POS);
            }
            else if (bluetooth_data == 'm')
            {
                servo_1.turnShaft(SERVO_CENTRE_POS);
            }
            else if (bluetooth_data == 'r')
            {
                servo_1.turnShaft(SERVO_RIGHT_POS);
            }
        }
    }

#ifdef __cplusplus
}
#endif
