/**
 * @file led.cpp
 *
 * @brief Proxy LED class source
 *
 * @date 09/2024
 */

#include "led.hpp"

Led::Led(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState on_state) : port(port), pin(pin), on_state(on_state) {
    // Implemente as inicializações

    this->off();
}

void Led::on() {
    // Implemente o código para acender o LED
}

void Led::off() {
    // Implemente o código para apagar o LED
}

void Led::toggle() {
    // Implemente o código para inverter o estado do LED
}
