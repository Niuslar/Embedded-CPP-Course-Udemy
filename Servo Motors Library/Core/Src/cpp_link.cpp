
#include "main.h"
#include "servo.h"

#ifdef __cplusplus
extern "C"
{
#endif
    void cpp_main()
    {
        HAL_Init();

        /* GPIO Ports Clock Enable */
        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOH_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        /* Pin structs */
        pin_struct_t PA0 = {GPIOA, GPIO_PIN_0};

        /* Servo instances */
        static Servo servo_1(PA0, TIM2, GPIO_AF2_TIM2, TIM_CHANNEL_1);

        while (1)
        {
            servo_1.turnShaft(SERVO_LEFT_POS);
            HAL_Delay(2000);
            servo_1.turnShaft(SERVO_CENTRE_POS);
            HAL_Delay(2000);
            servo_1.turnShaft(SERVO_RIGHT_POS);
            HAL_Delay(2000);
        }
    }

#ifdef __cplusplus
}
#endif
