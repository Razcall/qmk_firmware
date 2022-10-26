/* Copyright 2022 toinux
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

#pragma once

enum crkbd_layers {
  _BASE,
  _GAMING,
  _GAMING2,
  _ACCENTS,
  _LOWER,
  _RAISE,
  _FUN,
  _NAV,
  _MOUSE,
  _ADJUST
};

#define CTRLSC LCTL_T(KC_ESC)
#define QUORCTL RCTL_T(KC_QUOT)
#define RALTDEL MT(MOD_RALT,KC_DEL)
#define MOSCLN LT(_MOUSE,KC_SCLN)
#define ACCENTS LT(_ACCENTS,KC_RALT)
#define FUN LT(_FUN,KC_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ENTNAV LT(_NAV,KC_ENT)
#define SFTESC MT(MOD_RSFT,KC_ESC)
#define TABLGUI LGUI_T(KC_TAB)
#define BASE DF(_BASE)
#define GAMING DF(_GAMING)
#define GAMING2 MO(_GAMING2)



#define SC_F1 LSFT(LCTL(KC_F1))
#define SC_F2 LSFT(LCTL(KC_F2))
#define SC_F3 LSFT(LCTL(KC_F3))
#define SC_F4 LSFT(LCTL(KC_F4))

/* Tap Dance keycodes */
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dances.h"
    #define KC_T_SFT T_SFT /* Single tap for Shift, Double tap for CAPS Lock */
#else
    #define KC_T_SFT KC_LSFT
#endif