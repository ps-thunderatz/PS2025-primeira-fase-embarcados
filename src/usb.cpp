/**
 * @file usb.cpp
 *
 * @brief USB related
 *
 * @date 09/2024
 */

#include "usb_device.h"
#include <usbd_cdc_if.h>

#include "usb.hpp"

constexpr uint8_t START_BYTE = 0x7E;
constexpr uint8_t END_BYTE = 0x7F;

usb::usb() {
    MX_USB_DEVICE_Init();
}

void usb::send_package(uint8_t x, uint8_t y, bool button) {
    uint8_t data[5] = {START_BYTE, x, y, button, END_BYTE};

    CDC_Transmit_FS(data, sizeof(data));
}
