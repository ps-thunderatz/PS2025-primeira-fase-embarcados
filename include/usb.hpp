/**
 * @file usb.hpp
 *
 * @brief USB related
 *
 * @date 09/2024
 */

#ifndef USB_HPP
#define USB_HPP

#include <stdint.h>

class usb {
public:
    usb();

    void send_package(uint8_t x, uint8_t y, bool button);

private:
};

#endif  // USB_HPP
