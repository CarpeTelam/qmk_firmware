/* Copyright 2020 Boardsource
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

enum layers {
  _QWERTY,
  _MOUSE,
  _NUMBER,
  _NAVIGATION,
  _MEDIA,
  _FUNCTION,
  _CONFIG
};

#define SFT_A LSFT_T(KC_A)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)
#define GUI_J RGUI_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define SFT_SCN RSFT_T(KC_SCOLON)

#define CTL_LFT LCTL(KC_LEFT)
#define CTL_DWN LCTL(KC_DOWN)
#define CTL_UP LCTL(KC_UP)
#define CTL_RHT RCTL(KC_RIGHT)

#define NAV_1 LT(_MOUSE, KC_ESCAPE)
#define NAV_2 LT(_NUMBER, KC_BSPACE)
#define NAV_3 LT(_NAVIGATION, KC_DELETE)
#define NAV_4 LT(_MEDIA, KC_TAB)
#define NAV_5 LT(_FUNCTION, KC_SPACE)
#define NAV_6 LT(_CONFIG, KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12(
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_MEH,  KC_MEH,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      SFT_A,   CTL_S,   ALT_D,   GUI_F,    KC_G, KC_CAPS, KC_CAPS,    KC_H,   GUI_J,   ALT_K,   CTL_L, SFT_SCN,
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, CTL_DWN,  CTL_UP,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
    CTL_LFT, CTL_DWN,   NAV_1,   NAV_2,   NAV_3, CTL_LFT, CTL_RHT,   NAV_4,   NAV_5,   NAV_6,  CTL_UP, CTL_RHT
  ),

  [_MOUSE] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX
  ),

  [_NUMBER] = LAYOUT_ortho_4x12(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,  KC_EQL,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, _______, XXXXXXX, KC_MINS,    KC_4,    KC_5,    KC_6, KC_QUOT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_NAVIGATION] = LAYOUT_ortho_4x12(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, _______, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_INS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_DEL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_TAB,  KC_SPC,  KC_ENT, XXXXXXX, XXXXXXX
  ),

  [_MEDIA] = LAYOUT_ortho_4x12(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_FIND, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, XXXXXXX, _______, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
      KC_NO, KC_MRWD, KC_EJCT, KC_MUTE, KC_MFFD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FUNCTION] = LAYOUT_ortho_4x12(
      KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
      KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_CONFIG] = LAYOUT_ortho_4x12(
      RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_VAD, RGB_HUI, RGB_HUD, RGB_VAI, XXXXXXX, _______, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
    XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, RGB_MOD, RGB_TOG, RGB_M_P, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )

};

