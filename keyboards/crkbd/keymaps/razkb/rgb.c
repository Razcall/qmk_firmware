/* Copyright 2022 @toinux
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */


#include QMK_KEYBOARD_H
#include "keycodes.h"

static const char gaming_leds[] = {18, 19, 22, 16};
static const char gamingarround_leds[] = {10, 11, 12, 17, 23};
static const char gamingextra_leds[] = {6, 14, 15, 20, 21,25, 26};
static const char gaming2_leds[] = {23, 18, 17, 10, 9, 22, 19, 16, 11, 8};
static const char nav_leds1[] = {35, 38, 43, 46};
static const char nav_leds2[] = {34, 36, 37, 39, 44, 50};
static const char nav_noled[] = {42, 45, 47, 48, 49};
static const char fun_leds[] = {45, 44, 37, 46, 43, 38, 47, 42, 39, 40};
static const char fun_leds2[] = {41, 48, 49, 52, 53};
static const char fn_leds[] = {10, 11, 12, 15, 16, 17, 18, 19, 20, 21, 22, 23};
static const char mouse_leds1[] = {11, 16, 17, 19};
static const char mouse_leds2[] = {38, 43, 46};
static const char railow_leds1[] = {23, 18, 17, 10, 9, 8, 36, 37, 44, 45, 50, 38, 43, 46, 49, 52};
static const char lowarrows_leds[] = {19, 16, 11, 8};
static const char raivol_leds[] = {15, 12, 7};


void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(26, RGB_RED);
    }
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _GAMING:
            if (is_keyboard_master()) {
                for (uint8_t i = 0; i < 4; i++) {
                    rgb_matrix_set_color(gaming_leds[i], RGB_RED);
                }
                for (uint8_t i = 0; i < 5; i++) {
                    rgb_matrix_set_color(gamingarround_leds[i], RGB_ORANGE);
                }
                for (uint8_t i = 0; i < 7 ; i++) {
                    rgb_matrix_set_color(gamingextra_leds[i], RGB_GOLD);
                }
            }
            break;
        case _GAMING2:
            if (is_keyboard_master()) {
                for (uint8_t i = 0; i < 10; i++) {
                    rgb_matrix_set_color(gaming2_leds[i], RGB_GREEN);
                }
            }
            break;
        case _NAV:
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color(fn_leds[i], RGB_ORANGE);
            }
            for (uint8_t i = 0; i < 4; i++) {
                rgb_matrix_set_color(nav_leds1[i], RGB_TEAL);
            }
            for (uint8_t i = 0; i < 6; i++) {
                rgb_matrix_set_color(nav_leds2[i], RGB_YELLOW);
            }
            for (uint8_t i = 0; i < 5
                ; i++) {
                rgb_matrix_set_color(nav_noled[i], RGB_BLACK);
            }
            break;
        case _FUN:
            for (uint8_t i = 0; i < 12; i++) {
                rgb_matrix_set_color(fn_leds[i], RGB_ORANGE);
            }
            for (uint8_t i = 0; i < 10; i++) {
                rgb_matrix_set_color(fun_leds[i], RGB_GREEN);
            }
            for (uint8_t i = 0; i < 5; i++) {
                rgb_matrix_set_color(fun_leds2[i], RGB_GOLD);
            }
            rgb_matrix_set_color(33, RGB_RED);
            break;
        case _ADJUST:
                rgb_matrix_set_color(6, RGB_RED);  
            break;
        case _MOUSE:
            for (uint8_t i = 0; i < 4; i++) {
                rgb_matrix_set_color(mouse_leds1[i], RGB_PURPLE);
            }
            for (uint8_t i = 0; i < 3; i++) {
                rgb_matrix_set_color(mouse_leds2[i], RGB_YELLOW);
            }
            break;
        case _LOWER:
            for (uint8_t i = 0; i < 16; i++) {
                rgb_matrix_set_color(railow_leds1[i], RGB_CORAL);
            }
            for (uint8_t i = 0; i < 4; i++) {
                rgb_matrix_set_color(lowarrows_leds[i], RGB_SPRINGGREEN);
            }
            rgb_matrix_set_color(21, RGB_GREEN);
            break;
        case _RAISE:
            for (uint8_t i = 0; i < 16; i++) {
                rgb_matrix_set_color(railow_leds1[i], RGB_CHARTREUSE);
            }
            for (uint8_t i = 0; i < 3; i++) {
                rgb_matrix_set_color(raivol_leds[i], RGB_PINK);
            }
            break;
    }
}

