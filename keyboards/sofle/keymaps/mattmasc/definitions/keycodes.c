#include QMK_KEYBOARD_H

#include "keycodes.h"

uint16_t extract_tapping_keycode(uint16_t keycode) {
    // Return tapping keycode for tap dances
    switch (keycode) {
        case TD_DOT:
            return KC_DOT;
        default:
            break;
    }
    // Return tapping keycode for custom layer taps
    switch (keycode) {
        case M_REP:
            return KC_TRNS;
        default:
            break;
    }
    // Return tapping keycode for basic mod taps
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return keycode &= 0xff;
    }
    // Return tapping keycode for basic keycode
    return keycode;
}

bool is_string_macro_keycode(uint16_t keycode) {
    return keycode > STR_MACRO_START && keycode < STR_MACRO_END;
}

bool is_shift_macro_keycode(uint16_t keycode) {
    return keycode > SFT_MACRO_START && keycode < SFT_MACRO_END;
}

bool on_mac(void) {
    return keymap_config.swap_lctl_lgui;
}

void clear_oneshot_shift(void) {
    uint8_t oneshot_mods = get_oneshot_mods();
    if (oneshot_mods) {
        clear_oneshot_mods();
        unregister_mods(MOD_LSFT);
    }
}
