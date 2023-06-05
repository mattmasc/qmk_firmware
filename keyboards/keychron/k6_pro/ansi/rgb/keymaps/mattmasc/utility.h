#include QMK_KEYBOARD_H

inline uint8_t get_tap_kc(uint16_t dual_role_key) {
    // Used to extract the basic tapping keycode from a dual-role key.
    // Example: get_tap_kc(MT(MOD_RSFT, KC_E)) == KC_E
    return dual_role_key & 0xFF;
}
