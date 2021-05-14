#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3
#define _ADJUST 16

enum custom_keycodes {
  CK_BACK = TO(_QWERTY),
  CK_LOW  = MO(_LOWER),
  CK_RAS  = MO(_RAISE),
  CK_NUM  = TG(_NUMPAD)
};

// enum layers {
//   _QWERTY,
//   _LOWER,
//   _RAISE,
//   _ADJUST,
//   _NUMPAD
// };
// enum custom_keycodes {
//   BASE = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   NUMPAD,
//   ADJUST
// };

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  G(KC_L), RGB_TOG, KC_PSCR,         CK_NUM,  KC_EQL,  KC_PLUS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_INS,  KC_CAPS, KC_VOLU,         KC_7,    KC_8,    KC_9,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_F11,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_PGUP, KC_HOME, KC_VOLD,         KC_4,    KC_5,    KC_6,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_PGDN, KC_END,  KC_MUTE,         KC_1,    KC_2,    KC_3,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_LBRC, KC_RBRC, KC_MNXT,         KC_0,    KC_UP,   KC_DOT,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, CK_LOW, KC_SPC, XXXXXXX, KC_MEH,  KC_MPLY,         KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  CK_RAS, KC_RGUI, KC_RALT, KC_RCTL, KC_ENT   \
),
[_LOWER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_PGDN, _______, _______, _______, _______,       _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
[_RAISE] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______,       _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  \
    _______, _______, KC_LPRN, KC_LBRC, KC_PLUS, KC_LCBR, _______, _______, _______,       _______, _______, _______, KC_RCBR, KC_MINS, KC_RBRC, KC_RPRN, _______, KC_PIPE, \
    _______, _______, _______, _______, KC_EQL,  _______, _______, _______, _______,       _______, _______, _______, _______, KC_UNDS, _______, _______, KC_BSLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
[_NUMPAD] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_C,    KC_EQL,  KC_PSLS, KC_PAST, _______, _______,       _______, _______, _______, KC_C,    KC_EQL,  KC_PSLS, KC_PAST, _______, _______, \
    _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______, _______,       _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______, _______, \
    _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______, _______,       _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_PPLS, _______, _______, \
    _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ENT,  _______, _______,       _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ENT,  _______, _______, \
    _______, _______, _______, KC_0,    _______, KC_DOT,  _______, _______, _______,       _______, _______, _______, KC_0,    _______, KC_DOT,  _______, _______, _______  \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
void matrix_init_user(void) {
  rgblight_enable();
}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
      case _QWERTY:
        // rgblight_setrgb(0x00, 0x00, 0xFF);
        rgblight_setrgb(0x00, 0x00, 0x00);
        break;
      case _LOWER:
        // rgblight_setrgb(0x00, 0xA0, 0xFF);
        rgblight_setrgb(0x00, 0x70, 0x99);
        break;
      case _RAISE:
        // rgblight_setrgb(0xFF, 0x00, 0x00);
        rgblight_setrgb(0x99, 0x00, 0x00);
        break;
      case _ADJUST:
        // rgblight_setrgb(0xFF, 0x20, 0x00);
        rgblight_setrgb(0x99, 0x10, 0x00);
        break;
      case _NUMPAD:
        // rgblight_setrgb(0xFF, 0x00, 0xFF);
        rgblight_setrgb(0x99, 0x00, 0x99);
        break;
    }

    old_layer = new_layer;
  }

  #endif //RGBLIGHT_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

