// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H

//Tap dance enums
enum custom_tapdances{
    TD_LSFT_CAPS = 0,
//    TD_X_CTL = 1,
//    TD_SPC_FUN = 2,
    TD_SPC_FUN = 1,
    TD_LOW_FUN = 2,  //warning edit index number before adding any.
};

#define T_SFT TD(TD_LSFT_CAPS) /* Tap for Shift, double tap for CAPSLOCK */
//#define X_CTL TD(TD_X_CTL) /* Tap for x, hold for ctl double tap for escape double hold for alt */
#define T_SPCFUN TD(TD_SPC_FUN)  /* Tap for SPACE, hold for SHIFT, double tap for space, double hold for Function layer */
#define T_LOWFUN TD(TD_LOW_FUN) /*Tap/hold for LOW double tap for Function  layer*/

// Copyright 2022 
//https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_tap_dance.md
//'Quad Function Tap-Dance'

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
  TRIPLE_SINGLE_TAP = 8,
};



int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
//void x_finished (qk_tap_dance_state_t *state, void *user_data);
//void x_reset (qk_tap_dance_state_t *state, void *user_data);

//Functions associated with individual tap dances for the space tap dance
void spcl_finished (qk_tap_dance_state_t *state, void *user_data);
void spcl_reset (qk_tap_dance_state_t *state, void *user_data);

