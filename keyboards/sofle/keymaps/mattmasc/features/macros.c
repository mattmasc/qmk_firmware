#include QMK_KEYBOARD_H

#include "macros.h"

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {
    if (!is_shift_macro_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    if (record != NULL && !record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    switch (keycode) {
        // `
        case M_BTIC:
            tap_code(KC_GRV);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

        // "
        case M_DQUO:
            tap_code16(KC_DQUO);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

        // '
        case M_SQUO:
            tap_code(KC_QUOT);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

        // ^
        case M_CIRC:
            tap_code16(KC_CIRC);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

        // ~
        case M_TILD:
            tap_code16(KC_TILD);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

        // ../
        case M_DDS:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            tap_code16(KC_SLSH);
            return PROCESS_RECORD_RETURN_FALSE;

        // END { ENTER }
        case M_CUR:
            SEND_STRING(SS_TAP(X_END) "{}" SS_DELAY(50) SS_TAP(X_LEFT) SS_TAP(X_ENT));
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}
