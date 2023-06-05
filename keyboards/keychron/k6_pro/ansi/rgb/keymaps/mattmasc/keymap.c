#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "features/select_word.h"
#include "features/mouse_turbo_click.h"

#include "utility.h"

// All custom keycodes and aliases can be found in precondition_keymap.h
#include "precondition_keymap.h"

// clang-format off
enum layers {
    _WIN_BASE,
    _GAME,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
    _SETT,
    _1,
    _2,
    _3,
    _MAC_BASE,
    _MAC_FN1,
};

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WIN_BASE] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,  KC_EQL,          KC_BSPC,       KC_DELETE,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
        KC_TAB,      KC_X,    KC_P,    KC_L,    KC_M,    KC_K,  KC_LBRC, KC_COMM,   KC_W,    KC_O,    KC_U,    KC_Q,   KC_SLSH,     KC_BSLS,     KC_HOME,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
        KC_CAPS,     HOME_S,  HOME_N,  HOME_R,  HOME_T,   KC_G,  KC_RBRC,   KC_Y,   HOME_C,  HOME_A,  HOME_E,  HOME_I,           KC_ENT,         KC_PGUP,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
          LSFT_COMPL1,       KC_Z,    KC_B,    KC_H,    KC_D,    KC_V,   TD_DOT,   KC_F,  KC_QUOT, KC_SCLN,   KC_J,     RSFT_COMPL2,   KC_UP,   KC_PGDN,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
      KC_LCTL,    KC_LALT,    REPEAT_NAV,                         SPC_SYM,                         GRV_NUM, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN,  KC_RGHT
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_GAME] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
    KC_ESC,  KC_EQL,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,          KC_BSPC,       KC_DELETE,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
        KC_TAB,    KC_SCLN,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,      KC_RBRC,     KC_HOME,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
        KC_CAPS,    KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,  KC_BSLS,         GAME_CHAT,        KC_PGUP,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
           KC_LCTL,        KC_LALT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM,  TD_DOT,       KC_RSFT,     KC_UP,   KC_PGDN,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
     KC_QUOT,     KC_SLSH,       TURBO,                          KC_SPC,                          REPEAT_NAV,SPC_SYM,GRV_NUM,KC_LEFT, KC_DOWN, KC_RGHT
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_NAV] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,         KC_TRNS,         KC_TRNS,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
        KC_TRNS,  KC_TRNS,WIN_SELWORD,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_HOME, KC_END, KC_BSPC, KC_DELETE, KC_TRNS,     KC_TRNS,      KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
         KC_TRNS,   KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,          KC_TRNS,         KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
            KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
     KC_TRNS,     KC_TRNS,      KC_TRNS,                           KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_NUM] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        KC_TRNS,        KC_TRNS,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
       KC_TRNS,     KC_ASTR,  KC_6,   KC_5,  KC_4,  KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,WIN_SELWORD,KC_TRNS,KC_TRNS,     KC_TRNS,    KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
         KC_TRNS,     KC_3,    KC_2,    KC_1,   KC_0,   KC_EQL, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT,  KC_LGUI,         KC_TRNS,        KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
           KC_TRNS,         KC_BSLS, KC_9,   KC_8,    KC_7,  KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
      KC_TRNS,    KC_TRNS,     KC_TRNS,                                KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_SYM] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,        KC_TRNS,        KC_TRNS,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
     KC_TRNS, LCTL(KC_Q),LCTL(KC_W),LCTL(KC_E),LCTL(KC_R),LCTL(KC_T),KC_TRNS, KC_TRNS, KC_BSLS, KC_PLUS, M_CIRC, KC_EUR, KC_TRNS,   KC_TRNS,   KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
     CW_TOGG, LCTL(KC_A),LCTL(KC_S),LCTL(KC_D),LCTL(KC_F),LCTL(KC_G), KC_TRNS,  M_TILD, KC_LBRC, KC_RBRC, KC_HASH, KC_DLR,     KC_TRNS,        KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
       KC_TRNS,  LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_B), KC_TRNS, M_GRV, KC_LABK, KC_RABK, KC_PERC,     KC_TRNS,     KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
      KC_TRNS,    KC_TRNS,     KC_TRNS,                                KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_FUN] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,         KC_TRNS,         KC_TRNS,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_F7,  KC_F8,   KC_F9,  KC_F12,      KC_TRNS,    KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
        KC_TRNS,    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F4,   KC_F5,   KC_F6,   KC_F11,          KC_TRNS,        KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
           KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F10,      KC_TRNS,     KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
      KC_TRNS,     KC_TRNS,     KC_TRNS,                          KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_SETT] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS, KC_BRID, KC_BRIU, KC_TASK, KC_FILE, RGB_VAD,  RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,        KC_TRNS,      TG(_GAME),
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
       KC_TRNS,    BT_HST1, BT_HST2, BT_HST3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     AC_TOGG,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
        RGB_TOG,    RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,        KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
            KC_TRNS,       RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_1] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
       KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,        KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
           KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
      KC_TRNS,    KC_TRNS,     KC_TRNS,                                KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_2] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
       KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,        KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
           KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
      KC_TRNS,    KC_TRNS,     KC_TRNS,                                KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_3] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
   KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
       KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,        KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
           KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
      KC_TRNS,    KC_TRNS,     KC_TRNS,                                KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
    ),

[_MAC_BASE] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
//|------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                       KC_RCMMD,MO(_MAC_FN1),MO(_FUN), KC_LEFT,  KC_DOWN, KC_RGHT
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
     ),

[_MAC_FN1] = LAYOUT_ansi_68(
//,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------------+--------+.
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RGB_TOG,
//|---------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------------+--------+|
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
//|----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------------+--------+|
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
//|-----------------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+|
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
//|-----------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+|
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
//`------------+------------+------------+--------------------------------------------------------+--------+--------+--------+--------+--------+--------+'
     ),
};

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    switch (other_keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            other_keycode &= 0xff;  // Get base keycode.
    }

    // Allow same-hand holds with tri_layer
    switch (tap_hold_keycode) {
        case REPEAT_NAV:
        case SPC_SYM:
        case GRV_NUM:
        case LSFT_COMPL1:
        case RSFT_COMPL2:
            return true;
    }

    // Allow same-hand holds with non-alpha keys.
    if (other_keycode > KC_Z) { return true; }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);

    switch(layer) {
        case _GAME:
            rgb_matrix_set_color(3, RGB_ORANGE);
            rgb_matrix_set_color(4, RGB_ORANGE);
            rgb_matrix_set_color(17, RGB_ORANGE);
            rgb_matrix_set_color(18, RGB_RED);
            rgb_matrix_set_color(19, RGB_ORANGE);
            rgb_matrix_set_color(20, RGB_ORANGE);
            rgb_matrix_set_color(31, RGB_ORANGE);
            rgb_matrix_set_color(32, RGB_RED);
            rgb_matrix_set_color(33, RGB_RED);
            rgb_matrix_set_color(34, RGB_RED);
            rgb_matrix_set_color(35, RGB_ORANGE);                                                                                                                                                        rgb_matrix_set_color(45, RGB_ORANGE);
            rgb_matrix_set_color(46, RGB_ORANGE);
            rgb_matrix_set_color(47, RGB_ORANGE);
            rgb_matrix_set_color(48, RGB_ORANGE);
            break;
        default:
            break;
    }

    // Layer indicator only on keys with configured keycodes:
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED &&
            keymap_key_to_keycode(layer, (keypos_t){col,row}) <= KC_TRNS) {
                rgb_matrix_set_color(index, RGB_OFF);
            }
        }
    }

    return false;
}

// only runs when when the layer is changed, good for updating LED's and clearing sticky state
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    combo_enable(); // by default, enable combos.

    switch (layer) {
        case _WIN_BASE:
        case _SYM:
            break;
        case _GAME:
            combo_disable(); // Disable combos in game
        default:
            clear_mods();
            set_last_keycode(KC_TRNS);  // Forget last key and mod
            set_last_mods(get_mods());
            break;
    }

    return state;
};


static void process_compl1(uint16_t keycode, uint8_t mods) {
    uint8_t tap_kc = get_tap_kc(keycode);
    switch (tap_kc) {
        case KC_S: SEND_STRING(/*s*/"sion"); set_last_keycode(KC_N); break;
        case KC_T: SEND_STRING(/*t*/"heir"); set_last_keycode(KC_R); break;
        case KC_C: SEND_STRING(/*c*/"iao"); set_last_keycode(KC_O); break;
        case KC_A: SEND_STRING(/*a*/"tion"); set_last_keycode(KC_N); break;
        case KC_E: SEND_STRING(/*e*/"nto"); set_last_keycode(KC_O); break;
        case KC_I: SEND_STRING(/*i*/"tion"); set_last_keycode(KC_N); break;
        case KC_W: SEND_STRING(/*w*/"hich"); set_last_keycode(KC_H); break;
        default: break;
    }
}

static void process_compl2(uint16_t keycode, uint8_t mods) {
    uint8_t tap_kc = get_tap_kc(keycode);
    switch (tap_kc) {
        case KC_S: SEND_STRING(/*s*/"tate"); set_last_keycode(KC_E); break;
        case KC_T: SEND_STRING(/*t*/"here"); set_last_keycode(KC_E); break;
        case KC_C: SEND_STRING(/*c*/"ont"); set_last_keycode(KC_T); break;
        case KC_A: SEND_STRING(/*a*/"bout"); set_last_keycode(KC_T); break;
        case KC_E: SEND_STRING(/*e*/"llo"); set_last_keycode(KC_O); break;
        case KC_I: SEND_STRING(/*i*/"nter"); set_last_keycode(KC_R); break;
        case KC_W: SEND_STRING(/*w*/"ould"); set_last_keycode(KC_D); break;
        default: break;
    }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
  switch (keycode) {
    case REPEAT_NAV:
    case COMPL1:
    case COMPL2:
    case LSFT_COMPL1:
    case RSFT_COMPL2:
      return false;  // Ignore keys.
  }

  return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool ctrled = (mods & MOD_MASK_CTRL);  // Was Ctrl held?
    if (ctrled) {
        switch (keycode) {
            case KC_Y: return C(KC_Z);  // Ctrl + Y reverses to Ctrl + Z.
            case KC_Z: return C(KC_Y);  // Ctrl + Z reverses to Ctrl + Y.
        }
    }

    bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    switch (keycode) {
        case KC_TAB:
            if (shifted) {        // If the last key was Shift + Tab,
                return KC_TAB;    // ... the reverse is Tab.
            } else {              // Otherwise, the last key was Tab,
                return S(KC_TAB); // ... and the reverse is Shift + Tab.
            }
        case KC_DOT: return M_UPDIR;
        case KC_LPRN: return KC_RPRN;
    }

    return KC_TRNS;  // Defer to default definitions.
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_win_select_word(keycode, record, WIN_SELWORD)) { return false; }
    if (!process_mac_select_word(keycode, record, MAC_SELWORD)) { return false; }
    if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }

    switch (keycode) {
        case REPEAT_NAV:
            if (record->tap.count) {
                if (record->event.pressed) {
                    register_mods(get_last_mods());
                    register_code16(get_last_keycode());
                } else {
                    unregister_code16(get_last_keycode());
                    unregister_mods(get_last_mods());
                }
                return false; // Return false to ignore further processing of key
            } else if (record->event.pressed) {
                layer_on(_NAV);
                update_tri_layer(_NAV, _SYM, _FUN);
                update_tri_layer(_NAV, _NUM, _1);
            } else {
                layer_off(_NAV);
                update_tri_layer(_NAV, _SYM, _FUN);
                update_tri_layer(_NAV, _NUM, _1);
            }
            return false;
        case SPC_SYM:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SPC);
                caps_word_off(); // Turn off Caps World
                return false; // Return false to ignore further processing of key
            } else if (record->event.pressed) {
                layer_on(_SYM);
                update_tri_layer(_SYM, _NAV, _FUN);
                update_tri_layer(_SYM, _NUM, _SETT);
            } else {
                layer_off(_SYM);
                update_tri_layer(_SYM, _NAV, _FUN);
                update_tri_layer(_SYM, _NUM, _SETT);
            }
            return false;
        case GRV_NUM:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_GRV);
                return false; // Return false to ignore further processing of key
            } else if (record->event.pressed) {
                layer_on(_NUM);
                update_tri_layer(_NUM, _NAV, _1);
                update_tri_layer(_NUM, _SYM, _SETT);
            } else {
                layer_off(_NUM);
                update_tri_layer(_NUM, _NAV, _1);
                update_tri_layer(_NUM, _SYM, _SETT);
            }
            return false;
        case KC_ESC:                                       // Cancels chat mode in most games
            if (game_chat_set && record->event.pressed) {  // Checks if GAME_CHAT was pressed in-game
                tap_code16(KC_ESC);
                game_chat_set = false;
                layer_invert(_GAME);                     // Switches back to GAMING layer after chatting
            }
            return true; // Let QMK handle the rest
        case KC_ENT:
            if (game_chat_set && record->event.pressed) {  // Checks if GAME_CHAT was pressed in-game
                tap_code16(KC_ENT);
                game_chat_set = false;
                layer_invert(_GAME);                     // Switches back to GAMING layer after chatting
            }
            return true; // Let QMK handle the rest
        // GAME_CHAT: A key that taps enter to enable chat in-game, and temporarily toggles typing layer
        // When done chatting, pressing enter or esc will automatically swap back to game layer
        case GAME_CHAT:
            if (record->event.pressed) {
                tap_code16(KC_ENT);
                layer_invert(_GAME);
                game_chat_set = true;
            }
            return false;
        case LSFT_COMPL1:
            if (record->tap.count && record->event.pressed) {
                process_compl1(get_last_keycode(), get_last_mods());
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RSFT_COMPL2:
            if (record->tap.count && record->event.pressed) {
                process_compl2(get_last_keycode(), get_last_mods());
                return false;        // Return false to ignore further processing of key
            }
            break;
        case COMPL1:
            if (record->event.pressed) {
                process_compl1(get_last_keycode(), get_last_mods());
            }
            return false;
        case COMPL2:
            if (record->event.pressed) {
                process_compl2(get_last_keycode(), get_last_mods());
            }
            return false;
        case M_QUOT: // Types '
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
            }
            return false;
        case M_DQUO: // Types "
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_QUOT)) SS_TAP(X_SPC));
            }
            return false;
        case M_CIRC: // Types ^
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_6)) SS_TAP(X_SPC));
            }
            return false;
        case M_TILD: // Types ~
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_GRV)) SS_TAP(X_SPC));
            }
            return false;
        case M_GRV: // Types `
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
            }
            return false;
        case M_UPDIR: // Types ../
            if (record->event.pressed) {
                SEND_STRING(/*.*/"./");
            }
            return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_T):
        case RCTL_T(KC_C):
            return TAPPING_TERM + 20;
        case LSFT_T(KC_R):
        case RSFT_T(KC_A):
            return TAPPING_TERM + 40;
        case LALT_T(KC_N):
        case LALT_T(KC_E):
            return TAPPING_TERM + 60;
        case LGUI_T(KC_S):
        case RGUI_T(KC_I):
            return TAPPING_TERM + 80;
        default:
            return TAPPING_TERM;
    }
}
