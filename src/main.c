/**
 * STM32F103C8 Blink Demonstration
 *
 * Kevin Cuzner
 */

#include "stm32f1xx.h"

int main(void)
{
    //Step 1: Enable the clock to PORT B
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

    //Step 2: Change PB0's mode to 0x3 (output) and cfg to 0x0 (push-pull)
    GPIOB->CRL = GPIO_CRL_MODE0_0 | GPIO_CRL_MODE0_1;

    while (1)
    {
        //Step 3: Set PB0 high
        GPIOB->BSRR = GPIO_BSRR_BS0;
        for (uint16_t i = 0; i != 0xffff; i++) { }
        //Step 4: Reset PB0 low
        GPIOB->BSRR = GPIO_BSRR_BR0;
        for (uint16_t i = 0; i != 0xffff; i++) { }
    }

    return 0;
}

