/**
 * @file joystick.hpp
 *
 * @brief Joystick class
 *
 * @date 09/2024
 */

#ifndef JOYSTICK_HPP
#define JOYSTICK_HPP

#include <adc.h>
#include <array>
#include "button.hpp"

/**
 * @brief Class for acquiring a joystick data
 */
class Joystick {
public:
    /**
     * @brief Constructor for Joystick class
     *
     * @param adc_handler Pointer to HAL adc
     */
    Joystick(ADC_HandleTypeDef* handle, void (*init_function)(), Button button);

    /**
     * @brief Get the joystick X axis reading
     *
     * @return uint16_t Joystick X axis reading
     */
    uint8_t get_x();

    /**
     * @brief Get the joystick Y axis reading
     *
     * @return uint16_t Joystick Y axis reading
     */
    uint8_t get_y();

    /**
     * @brief Get the joystick button state
     *
     * @return bool True if button is pressed, false otherwise
     */
    bool is_pressed();

private:
    ADC_HandleTypeDef* handle;
    Button             button;

    std::array<uint32_t, 2> buffer;
};

#endif  // JOYSTICK_HPP
