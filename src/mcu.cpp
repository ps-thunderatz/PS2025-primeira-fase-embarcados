/**
 * @file mcu.cpp
 *
 * @brief MCU related
 */

#include <dma.h>
#include <stdint.h>

#include "mcu.hpp"

#include "gpio.h"
#include "main.h"

/*****************************************
 * Public Function Body Definitions
 *****************************************/

void mcu::init(void) {
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_DMA_Init();
}

void mcu::sleep(uint32_t ms) {
    HAL_Delay(ms);
}
