#pragma once

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_S LGUI_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_R LSFT_T(KC_R)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_C RCTL_T(KC_C)
#define HOME_A RSFT_T(KC_A)
#define HOME_E LALT_T(KC_E)
#define HOME_I RGUI_T(KC_I)

#define REPEAT_NAV LT(0, QK_REP)
#define GRV_NUM LT(0, KC_GRV)
#define SPC_SYM LT(0, KC_SPC)

#define LSFT_COMPL1 LSFT_T(COMPL1)
#define RSFT_COMPL2 RSFT_T(COMPL2)

#define KC_EUR RALT(KC_5)

enum custom_keycodes {
  WIN_SELWORD = SAFE_RANGE,
  MAC_SELWORD,
  GAME_CHAT,
  TURBO,
  M_QUOT,
  M_DQUO,
  M_CIRC,
  M_TILD,
  M_GRV,
  M_UPDIR,
  COMPL1,
  COMPL2,
  // Other custom keys...
};

// Tap dance enums
enum {
    DOT_TD,
};

#define TD_DOT TD(DOT_TD)

bool game_chat_set;
