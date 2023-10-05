#pragma once

#include "layers.h"

// clang-format off

// Tap dance codes

enum {
    DOT_TD,
    BOOT_TD,
    QWRT_TD,
    SNRT_TD,
    GAME_TD,
    OPP_TD,
    SWBT_TD,
    OFF_TD,
};

// Tap dance keycodes

#define TD_DOT TD(DOT_TD)

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    M_QWRT,
    M_SNRT,
    M_GCHAT,

    M_SELWORD,
    M_TURBO,
    M_LLOCK,

    SC_TOGG,

    // Case modes
    CM_WORD,
    CM_CAMEL,
    CM_SLASH,
    CM_SNAKE,
    CM_KEBAB,
    CM_XCASE,

    // Begin macros that can be shifted
    SFT_MACRO_START,

    // Common shortcuts
    S_PRVWD, S_NXTWD, S_HOME, S_END, S_COPY, S_PASTE, S_CUT, S_UNDO, S_REDO, S_SELC,

    // Begin macros used to write text
    STR_MACRO_START,

    M_BTIC, M_DQUO, M_SQUO, M_CIRC, M_TILD, M_DDS, M_CUR,

    // End macros that can be shifted
    SFT_MACRO_END,

    // End macros used to write text
    STR_MACRO_END,

    CUSTOM_KEYCODE_END
};

#define M_REP LT(_SYM,QK_REP)

#define ALT_LMGC RALT_T(KC_LEFT)
#define ALT_RMGC RALT_T(KC_RGHT)

// Left-hand home row mods
#define HOME_S LGUI_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_R LSFT_T(KC_R)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_C LCTL_T(KC_C)
#define HOME_A LSFT_T(KC_A)
#define HOME_E LALT_T(KC_E)
#define HOME_I LGUI_T(KC_I)

// Left-hand symbol home row mods
#define HOME_PE LGUI_T(KC_PERC)
#define HOME_LP LALT_T(KC_LPRN)
#define HOME_RP LSFT_T(KC_RPRN)
#define HOME_CO LCTL_T(KC_COLN)

// Right-hand symbol home row mods
#define HOME_EQ LCTL_T(KC_EQL)
#define HOME_PL LSFT_T(KC_PLUS)
#define HOME_MI LALT_T(KC_MINS)
#define HOME_EX LGUI_T(KC_EXLM)

uint16_t extract_tapping_keycode(uint16_t keycode);
bool is_string_macro_keycode(uint16_t keycode);
bool is_shift_macro_keycode(uint16_t keycode);
bool on_mac(void);
void clear_oneshot_shift(void);

// clang-format on
