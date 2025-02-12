// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "tap_dances.h"
#include "keycodes.h"




//quad function tap dance

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
 //   if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    if (!state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_SINGLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 3; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
//static tap xtap_state = {
//  .is_press_action = true,
//  .state = 0
//};

//void x_finished (qk_tap_dance_state_t *state, void *user_data) {
//  xtap_state.state = cur_dance(state);
//  switch (xtap_state.state) {
//    case SINGLE_TAP: register_code(KC_X); break;
//    case SINGLE_HOLD: register_code(KC_LCTRL); break;
//    case DOUBLE_TAP: register_code(KC_ESC); break;
//    case DOUBLE_HOLD: register_code(KC_LALT); break;
//    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
//    //Last case is for fast typing. Assuming your key is `f`:
//    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//  }
//}
//
//void x_reset (qk_tap_dance_state_t *state, void *user_data) {
//  switch (xtap_state.state) {
//    case SINGLE_TAP: unregister_code(KC_X); break;
//    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
//    case DOUBLE_TAP: unregister_code(KC_ESC); break;
//    case DOUBLE_HOLD: unregister_code(KC_LALT);
//    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
//  }
//  xtap_state.state = 0;
//}

// create a global instance of the tapdance state type
static tap sptap_state = {
  .is_press_action = true,
  .state = 0
};

// Pour TD_LSFT_CAPS (T_SFT)
void lsft_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
    } else if (state->count == 2) {
        register_code(KC_CAPS);
    }
}

void lsft_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LSFT);
    } else if (state->count == 2) {
        unregister_code(KC_CAPS);
    }
}

void spcl_finished (qk_tap_dance_state_t *state, void *user_data) {
  sptap_state.state = cur_dance(state);
  switch (sptap_state.state) {
    case SINGLE_TAP: register_code16(KC_SPC); break; 
    case SINGLE_HOLD:register_code(KC_LSFT); break; // for a layer-tap key, use `layer_on(_MY_LAYER)` here
    case DOUBLE_SINGLE_TAP:tap_code16(KC_SPC); register_code16(KC_SPC); break; // allow nesting of 2 parens `((` within tapping term
    case DOUBLE_HOLD: layer_on(_FUN); break;
    case TRIPLE_SINGLE_TAP: tap_code16(KC_SPC); tap_code16(KC_SPC); register_code(KC_SPC); break;
    case TRIPLE_HOLD: tap_code16(KC_SPC); tap_code16(KC_SPC); register_code(KC_SPC);
  }
}

void spcl_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (sptap_state.state) {
    case SINGLE_TAP: unregister_code16(KC_SPC); break;
    case SINGLE_HOLD:unregister_code(KC_LSFT); break; // for a layer-tap key, use `layer_off(_MY_LAYER)` here
    case DOUBLE_SINGLE_TAP:unregister_code16(KC_SPC); break;
    case DOUBLE_HOLD: layer_off(_FUN); break;
    case TRIPLE_SINGLE_TAP: unregister_code(KC_SPC); break;
    case TRIPLE_HOLD: unregister_code(KC_SPC);
  }
  sptap_state.state = 0;
}

// Pour TD_LOW_FUN (T_LOWFUN)
void low_fun_finished (qk_tap_dance_state_t *state, void *user_data) {
    // créez une instance de l'état de tap dance
    tap lowtap_state = {
        .is_press_action = true,
        .state = 0
    };

    // déterminez l'état actuel
    lowtap_state.state = cur_dance(state);

    // agissez en fonction de l'état
    switch (lowtap_state.state) {
        case SINGLE_TAP: 
        case SINGLE_HOLD: 
            layer_on(_LOWER); 
            break;
        case DOUBLE_TAP: 
        case DOUBLE_HOLD: 
            layer_on(_FUN); 
            break;
        // ajoutez des cas pour plus de taps si nécessaire
    }
}

void low_fun_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_off(_LOWER);
    } else if (state->count == 2) {
        layer_off(_FUN);
    }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_finished, lsft_reset),
//    [TD_X_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset),
    [TD_SPC_FUN]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,spcl_finished, spcl_reset),
    [TD_LOW_FUN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, low_fun_finished, low_fun_reset),
};