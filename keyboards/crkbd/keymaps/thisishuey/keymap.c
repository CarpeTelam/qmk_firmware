#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef OLED_DRIVER_ENABLE
  static uint32_t oled_timer = 0;
#endif

extern uint8_t is_master;

enum layers {
  _QWERTY,
  _MOUSE,
  _NUMBER,
  _NAVIGATION,
  _SHORTCUT,
  _FUNCTION,
  _MEDIA
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
#define CTL_RHT RCTL(KC_RIGHT)

#define NAV_1 LT(_MOUSE, KC_ESCAPE)
#define NAV_2 LT(_NUMBER, KC_BSPACE)
#define NAV_3 LT(_NAVIGATION, KC_DELETE)
#define NAV_4 LT(_MEDIA, KC_TAB)
#define NAV_5 LT(_FUNCTION, KC_SPACE)
#define NAV_6 LT(_SHORTCUT, KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    CTL_LFT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, CTL_RHT,
    KC_CAPS,   SFT_A,   CTL_S,   ALT_D,   GUI_F,    KC_G,                        KC_H,   GUI_J,   ALT_K,   CTL_L, SFT_SCN, KC_CAPS,
     KC_MEH,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_MEH,
                                          NAV_1,   NAV_2,   NAV_3,     NAV_4,   NAV_5,   NAV_6
  ),

  [_MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,   KC_BTN1, KC_BTN2, KC_BTN3
  ),

  [_NUMBER] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_EQL,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                     KC_MINS,    KC_4,    KC_5,    KC_6, KC_QUOT, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,   KC_LBRC, KC_RBRC, XXXXXXX
  ),

  [_NAVIGATION] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX,
    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_INS, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_DEL, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_MEDIA] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_FIND, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT,                     XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
    XXXXXXX,   KC_NO, KC_MRWD, KC_EJCT, KC_MUTE, KC_MFFD,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        XXXXXXX, KC_MPLY, KC_MSTP,   XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_FUNCTION] = LAYOUT(
    XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                     XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_SHORTCUT] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                         KC_CUT, KC_COPY, KC_PSTE,   XXXXXXX, XXXXXXX, XXXXXXX
  )
};

#ifdef OLED_DRIVER_ENABLE
  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
  }

  void render_space(void) {
    oled_write_P(PSTR("     "), false);
  }

  void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
      oled_write_P(gui_on_1, false);
    } else {
      oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
      oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
      oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
      oled_write_P(off_on_1, false);
    } else {
      oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
      oled_write_P(alt_on_1, false);
    } else {
      oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
      oled_write_P(gui_on_2, false);
    } else {
      oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
      oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
      oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
      oled_write_P(off_on_2, false);
    } else {
      oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
      oled_write_P(alt_on_2, false);
    } else {
      oled_write_P(alt_off_2, false);
    }
  }

  void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(ctrl_on_1, false);
    } else {
      oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
      oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(off_on_1, false);
    } else {
      oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(shift_on_1, false);
    } else {
      oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(ctrl_on_2, false);
    } else {
      oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
      oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(off_on_2, false);
    } else {
      oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(shift_on_2, false);
    } else {
      oled_write_P(shift_off_2, false);
    }
  }

  void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
  }

  void render_layer_state(uint8_t base) {
    static const char PROGMEM default_layer[] = {
      0x20, 0x9d, 0x9e, 0x9f, 0x20,
      0x20, 0xbd, 0xbe, 0xbf, 0x20,
      0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    static const char PROGMEM low_layer[] = {
      0x20, 0x9a, 0x9b, 0x9c, 0x20,
      0x20, 0xba, 0xbb, 0xbc, 0x20,
      0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM mid_layer[] = {
      0x20, 0x94, 0x95, 0x96, 0x20,
      0x20, 0xb4, 0xb5, 0xb6, 0x20,
      0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM high_layer[] = {
      0x20, 0x97, 0x98, 0x99, 0x20,
      0x20, 0xb7, 0xb8, 0xb9, 0x20,
      0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    if(layer_state_is(base)) {
      oled_write_P(low_layer, false);
    } else if(layer_state_is(base + 1)) {
      oled_write_P(mid_layer, false);
    } else if(layer_state_is(base + 2)) {
      oled_write_P(high_layer, false);
    } else {
      oled_write_P(default_layer, false);
    }
  }

  void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state(4);
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
  }

  void render_status_secondary(void) {
    render_logo();
    render_space();
    render_layer_state(1);
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
  }

  void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
      oled_off();
      return;
    }
    #ifndef SPLIT_KEYBOARD
      else { oled_on(); }
    #endif

    if (is_master) {
      render_status_main();
    } else {
      render_status_secondary();
    }
  }

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef OLED_DRIVER_ENABLE
      oled_timer = timer_read32();
    #endif
  }
  return true;
}
