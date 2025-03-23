/**
 * @file led.hpp
 *
 * @brief Proxy LED class header
 *
 * @date 09/2024
 */

#ifndef LED_HPP
#define LED_HPP

#include <cstdint>
#include <gpio.h>
#include <stm32f1xx_hal_gpio.h>

/**
 * @brief Class for controlling a LED
 */
class Led {
public:
    /**
     * @brief Constructor for Led class
     *
     * @param port LED port
     * @param pin LED pin
     * @param on_state GPIO pin state when LED is on
     */
    Led(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState on_state = GPIO_PIN_SET);

    /**
     * @brief Turn on the LED
     */
    void on();

    /**
     * @brief Turn off the LED
     */
    void off();

    /**
     * @brief Toggle the LED
     */
    void toggle();

private:
    GPIO_TypeDef* port;
    uint16_t      pin;
    GPIO_PinState on_state;
};

#endif  // LED_HPP
