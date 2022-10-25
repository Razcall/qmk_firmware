/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Armando Magalhaes <@armand1m>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_layers {
    L_BASE,
    L_LOWER,
    L_RAISE,
    L_ADJUST,
    L_GAMING ,
    L_RAGAMING ,
    L_FN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(6, KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                      KC_LALT, MO(1), MT(MOD_LSFT, KC_SPC),                      KC_ENT,   MO(2), MT(MOD_RALT, KC_DEL)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,   TG(4),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,   _______,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
 ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_PSCR, KC_HOME, KC_PGUP,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_NUBS, XXXXXXX, XXXXXXX,  KC_END, KC_PGDN,             KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  MO(3),  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       RESET, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PMNS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLD, KC_VOLU,                      KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_PDOT,  KC_NUM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_MUTE,                      KC_PSLS,   KC_P1,   KC_P2,   KC_P3,   KC_P0, KC_PEQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(6, KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,  KC_G,                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   MO(5),  KC_SPC,     KC_ENT,   MO(5), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,    TG(4),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

   [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,    KC_F8,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

};

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_GAMING 16
#define L_RAGAMING 32
#define L_FN 64

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Home"), false);
            break;
        case L_LOWER:
        case L_GAMING|L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
        case L_GAMING|L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        case L_GAMING:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
        case L_RAGAMING:
        case L_RAGAMING|L_GAMING:
            oled_write_ln_P(PSTR("Raised Gaming"), false);
            break;
        case L_FN:
        case L_FN|L_LOWER:
        case L_FN|L_RAISE:
        case L_FN|L_GAMING:
            oled_write_ln_P(PSTR("Functions"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

//void oled_render_logo(void) {
//    static const char PROGMEM crkbd_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//        0};
//    oled_write_P(crkbd_logo, false);
//}

void oled_render_razkb(void) {
    // 'razkb', 128x32px
    static const char PROGMEM razkb[] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F,
        0x3F, 0xBF, 0xBF, 0xBF, 0xBE, 0xBE,
        0xFE, 0x7C, 0x7C, 0xFC, 0xF8, 0xF8,
        0x78, 0xF0, 0xF0, 0xB0, 0xA0, 0xA0,
        0xA0, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x00, 0x00, 0x01, 0x03, 0x03, 0x07,
        0x07, 0x0F, 0x8F, 0x9F, 0xBE, 0xBC,
        0xBC, 0xF8, 0x70, 0x60, 0xC0, 0x81,
        0x03, 0x0F, 0x1F, 0x3C, 0xF0, 0x80,
        0x80, 0x87, 0xBF, 0xBF, 0x80, 0x80,
        0x80, 0xBE, 0x1F, 0x07, 0x81, 0x80,
        0xA0, 0xB8, 0xBC, 0x9E, 0x8F, 0x87,
        0x87, 0x83, 0x81, 0x80, 0xC0, 0x60,
        0x70, 0x70, 0xF8, 0xF8, 0xFC, 0xFC,
        0x7E, 0x7F, 0x3F, 0xBF, 0xBF, 0x9F,
        0x9F, 0x9F, 0x8F, 0x8F, 0x8F, 0x87,
        0x87, 0x87, 0x07, 0x03, 0x03, 0x03,
        0x01, 0x01, 0x01, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x00, 0xFF, 0xFF, 0xF9, 0x61,
        0x03, 0x03, 0x03, 0x07, 0x0F, 0xFE,
        0xFE, 0xDF, 0x07, 0x07, 0x03, 0x03,
        0x03, 0x01, 0x01, 0x01, 0x01, 0x03,
        0x03, 0x03, 0x07, 0x07, 0xDE, 0xFC,
        0xF8, 0xFC, 0x3E, 0x0F, 0x07, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x07, 0x1E,
        0x7C, 0xF9, 0xFD, 0xFE, 0xCF, 0x87,
        0x03, 0x03, 0x03, 0x01, 0x01, 0x01,
        0x01, 0x03, 0x03, 0x03, 0x07, 0xDF,
        0xFF, 0xFB, 0xF9, 0xE1, 0xFF, 0xFF,
        0x1F, 0x03, 0x03, 0x01, 0x03, 0x03,
        0x1F, 0x1F, 0x0F, 0x07, 0x03, 0x03,
        0xC3, 0xE7, 0xFF, 0xCF, 0x87, 0x03,
        0x03, 0x03, 0x03, 0x01, 0x01, 0x01,
        0x01, 0x03, 0x03, 0x03, 0x07, 0x0F,
        0xFE, 0xFC, 0x7C, 0x1E, 0x0F, 0x07,
        0x03, 0x03, 0x01, 0xC3, 0xFF, 0xFF,
        0x3E, 0x00, 0x00, 0x04, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0xFC, 0x80, 0x80,
        0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
        0xC0, 0xC0, 0x7E, 0xFF, 0xFF, 0xC3,
        0x80, 0xC0, 0xC0, 0xE0, 0xF0, 0x78,
        0x3E, 0x1F, 0x07, 0x03, 0x07, 0x3F,
        0xFE, 0xF8, 0xC0, 0x80, 0x82, 0xE6,
        0xFE, 0xE3, 0xC0, 0xC0, 0x8C, 0xDE,
        0xFF, 0xFF, 0xCF, 0xC1, 0xC0, 0xE0,
        0xF0, 0x78, 0x3C, 0x1E, 0x3C, 0x78,
        0xF0, 0xE0, 0xC0, 0x81, 0xFF, 0xFF,
        0xFF, 0xDF, 0xCF, 0xC7, 0x86, 0x86,
        0x82, 0x8A, 0x88, 0x8C, 0xDC, 0xDE,
        0xDF, 0xFF, 0x7B, 0x01, 0x00, 0x00,
        0x0F, 0x3F, 0xFF, 0xF0, 0xC0, 0x80,
        0xC0, 0xE0, 0xF8, 0x7C, 0x38, 0x70,
        0xF0, 0xE3, 0xEF, 0xFF, 0xFF, 0xFF,
        0xC7, 0x80, 0x80, 0x9B, 0x9A, 0x9A,
        0x9A, 0x9A, 0x9A, 0xDA, 0xC0, 0xE0,
        0xFC, 0x7E, 0x3F, 0x7F, 0xF0, 0xE0,
        0xC0, 0xC0, 0x80, 0x86, 0xDF, 0xFF,
        0xFB, 0x00, 0x00, 0x00, 0x30, 0x38,
        0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
        0xFD, 0xF9, 0xF1, 0x71, 0x71, 0x71,
        0x30, 0x30, 0x30, 0x10, 0x18, 0x1C,
        0x0E, 0x0F, 0x0E, 0x0D, 0x05, 0x01,
        0x01, 0x01, 0x00, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x81, 0xC1, 0xC1, 0xE1,
        0xE1, 0xF1, 0xF0, 0xF0, 0x70, 0x30,
        0x18, 0x1C, 0x0E, 0x01, 0x01, 0x81,
        0xC1, 0xE1, 0xF0, 0x31, 0x01, 0x01,
        0x01, 0xE1, 0xF1, 0xE1, 0x01, 0x01,
        0x01, 0x61, 0xE1, 0xE0, 0x80, 0x00,
        0x00, 0x00, 0x38, 0x78, 0xF0, 0xF1,
        0xE1, 0xC1, 0x81, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x18, 0x1C, 0x38, 0x38,
        0x78, 0xF9, 0xF9, 0xF1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE0, 0xC0, 0xC0, 0xC0,
        0x80, 0x80, 0x81, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00,
    };
    oled_write_raw_P(razkb, sizeof(razkb));
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        //oled_render_logo();
        oled_render_razkb();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
