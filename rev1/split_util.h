#ifndef SPLIT_KEYBOARD_UTIL_H
#define SPLIT_KEYBOARD_UTIL_H

#include <stdbool.h>
#include "eeconfig.h"

#define SLAVE_I2C_ADDRESS           0x32

#define OLED_FONT_WIDTH 24
#define OLED_FONT_HEIGHT 32

extern volatile bool isLeftHand;

// slave version of matix scan, defined in matrix.c
void matrix_slave_scan(void);

void split_keyboard_setup(void);
bool has_usb(void);

void matrix_master_OLED_init (void);

#endif