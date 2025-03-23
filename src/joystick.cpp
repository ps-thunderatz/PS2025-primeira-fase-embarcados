/**
 * @file joystick.cpp
 *
 * @brief Joystick class implementation
 *
 * @date 09/2024
 */

#include "joystick.hpp"
#include <cstdint>
// Inclua os arquivos necessários

Joystick::Joystick(ADC_HandleTypeDef* handle, void (*init_function)(), Button button) : handle(handle), button(button) {
    // Implemente as inicializações
}

uint8_t Joystick::get_x() {
    // Implemente o código para obter a posição do eixo X
}

uint8_t Joystick::get_y() {
    // Implemente o código para obter a posição do eixo Y
}

bool Joystick::is_pressed() {
    // Implemente o código para verificar se o botão foi pressionado
}
