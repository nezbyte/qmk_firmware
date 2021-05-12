#include QMK_KEYBOARD_H


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _NUMPAD 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NUMPAD
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | GUI  |Lower |MehSpc|Space |Raise | GUI  | Meh |  Meh  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_MEH,  KC_MEH,   KC_ENT   \
),
  /* KC_LCTL, KC_MEH, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, ______, ______,   KC_ENT */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | PgDn |      | Left | Down |  Up  |Right | Home |Delete|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | PgUp |      |      |      |Insert| End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |NUMPAD|      |             |      |      | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______,   KC_1,      KC_2,    KC_3,        KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______,   _______,   _______, _______,     KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_DEL,  \
  _______,   _______,   _______, _______,     _______, KC_PGUP, _______, _______, _______, KC_INS,  KC_END,  _______, \
  _______,   _______,   _______, TT(_NUMPAD), _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   /  |   {  |  =   |  [   |  ]   |   -  |   }  |   \  |   :  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   `  |      |      |  +   |      |      |   _  |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Play | Next |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
   KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC , \
  _______, KC_TILD, KC_SLSH, KC_LCBR, KC_EQL,  KC_LBRC, KC_RBRC, KC_MINS, KC_RCBR, KC_BSLS, KC_COLN, KC_PIPE, \
  _______, KC_GRV,  _______, _______, KC_PLUS, _______, _______, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, _______  \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|  Up  |      | Home | PGUP |  7   |  8   |  9   |  -   |  *   |      |
 * |-------------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right| End  | PGDN |  4   |  5   |  6   |  +   |  /   |      |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  1   |  2   |  3   |Enter |Enter |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |         0   |  0   |  .   |Enter |Enter |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( \
  _______,   _QWERTY,     KC_UP,   _______,   _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PAST, _______,  \
  _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PSLS, _______,  \
  _______,   _______,   _______,   _______,   _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_PENT, _______,  \
  _______,   _______,   _______,   _______,   _______, _______, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, _______   \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |MSBTN1| MS UP|MSBTN2| WHLUP|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 | MS LT| MS DN| MS RT| WHLDN|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,  KC_DEL, \
  _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, \
  _______,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
