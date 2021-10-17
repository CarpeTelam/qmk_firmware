/* Copyright 2021 Dave Vandyke <kzar@kzar.co.uk>,
 *   Based upon Xyverz's Kinesis keymap Copyright 2017-2020.
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
#include "version.h"

enum layer_names {_DEFAULT, _MOUSE, _NUMBER, _NAVIGATION, _MEDIA, _FUNCTION, _SHORTCUT};

// Custom keycodes for layer keys
#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)
#define GUI_J RGUI_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SCN RSFT_T(KC_SCOLON)

#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RHT RCTL(KC_RGHT)

#define NAV_1 LT(_MOUSE, KC_ESCAPE)
#define NAV_2 LT(_NUMBER, KC_BSPACE)
#define NAV_3 LT(_NAVIGATION, KC_DELETE)
#define NAV_4 LT(_MEDIA, KC_TAB)
#define NAV_5 LT(_FUNCTION, KC_SPACE)
#define NAV_6 LT(_SHORTCUT, KC_ENTER)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT (
    // Left Hand
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    CTL_LFT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    KC_CAPS,   SFT_A,   CTL_S,   ALT_D,   GUI_F,    KC_G,
     KC_MEH,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
             KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
                                                           CTL_LFT, KC_HYPR,
                                                                     KC_MEH,
                                                    NAV_2,   NAV_3,   NAV_1,

    // Right Hand
      KC_F9, KC_F10,  KC_F11,  KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, KC_HOME,  KC_END,
                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CTL_RHT,
                                 KC_H,   GUI_J,   ALT_K,   CTL_L, SFT_SCN, KC_CAPS,
                                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_MEH,
                                       KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
            KC_HYPR, CTL_RHT,
             KC_MEH,
              NAV_6,   NAV_4,   NAV_5
  ),

  [_MOUSE] = LAYOUT (
    // Left Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX,
    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,
                                                                   XXXXXXX,
                                                 XXXXXXX, XXXXXXX, XXXXXXX,

    // Right Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
                               KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX,
             XXXXXXX,
             KC_BTN3, KC_BTN1, KC_BTN2
  ),

  [_NUMBER] = LAYOUT (
    // Left Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,
                                                                   XXXXXXX,
                                                 XXXXXXX, XXXXXXX, XXXXXXX,

    // Right Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                KC_EQL,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
                               KC_MINS,    KC_4,    KC_5,    KC_6, KC_QUOT, XXXXXXX,
                                KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX,
             XXXXXXX,
             XXXXXXX, KC_LBRC, KC_RBRC
  ),

  [_NAVIGATION] = LAYOUT (
    // Left Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,
                                                                   XXXXXXX,
                                                 XXXXXXX, XXXXXXX, XXXXXXX,

    // Right Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX,
                               KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_INS, XXXXXXX,
                               KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_DEL, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX,
             XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_MEDIA] = LAYOUT (
    // Left Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_FIND, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT,
    XXXXXXX, XXXXXXX, KC_MRWD, KC_EJCT, KC_MUTE, KC_MFFD,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,
                                                                   XXXXXXX,
                                                 KC_MPLY, KC_MSTP, XXXXXXX,

    // Right Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX,
             XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FUNCTION] = LAYOUT (
    // Left Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
    XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,
                                                                   XXXXXXX,
                                                 XXXXXXX, XXXXXXX, XXXXXXX,

    // Right Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX,
             XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SHORTCUT] = LAYOUT (
    // Left Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,
                                                                   XXXXXXX,
                                                 KC_COPY, KC_PSTE,  KC_CUT,

    // Right Hand
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX,
             XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX
  )

};

