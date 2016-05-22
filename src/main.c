/**
 * led-watch
 *
 * Kevin Cuzner
 */

#include "stm32f1xx.h"

int main(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    GPIOB->CRL = GPIO_CRL_MODE0_0 | GPIO_CRL_MODE0_1;

    while (1)
    {
        GPIOB->BSRR = GPIO_BSRR_BS0;
        for (uint16_t i = 0; i != 0xffff; i++) { }
        GPIOB->BSRR = GPIO_BSRR_BR0;
        for (uint16_t i = 0; i != 0xffff; i++) { }
    }

    return 0;
}

