/**
 * @file button.cpp
 *
 * @brief Proxy Button class source
 *
 * @date 09/2024
 */

#include "button.hpp"

Button::Button(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState pressed_state) :
    port(port), pin(pin), pressed_state(pressed_state) { }

bool Button::is_pressed() {
    // Implemente o código para verificar se o botão foi pressionado
}
