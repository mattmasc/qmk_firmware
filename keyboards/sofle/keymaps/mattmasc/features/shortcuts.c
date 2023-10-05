#include QMK_KEYBOARD_H

#include "shortcuts.h"

process_record_result_t process_shortcuts(uint16_t keycode, keyrecord_t *record) {
    if (!is_shift_macro_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    if (record != NULL && !record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    // CTL and GUI swapped so CTL=CMD, GUI=CTL and ALT=Option
    bool onMac = on_mac();

    switch (keycode) {
        case S_PRVWD:
            if (onMac) {
                SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case S_NXTWD:
            if (onMac) {
                SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case S_HOME:
            if (onMac) {
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
            } else {
                SEND_STRING(SS_TAP(X_HOME));
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case S_END:
            if (onMac) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
            } else {
                SEND_STRING(SS_TAP(X_END));
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case S_COPY:
            SEND_STRING(SS_LCTL("c"));
            return PROCESS_RECORD_RETURN_FALSE;

        case S_PASTE:
            SEND_STRING(SS_LCTL("v"));
            return PROCESS_RECORD_RETURN_FALSE;

        case S_CUT:
            SEND_STRING(SS_LCTL("x"));
            return PROCESS_RECORD_RETURN_FALSE;

        case S_UNDO:
            SEND_STRING(SS_LCTL("z"));
            return PROCESS_RECORD_RETURN_FALSE;

        case S_REDO:
            if (onMac) {
                SEND_STRING(SS_LCTL(SS_LSFT("z")));
            } else {
                SEND_STRING(SS_LCTL("y"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case S_SELC:
            SEND_STRING(SS_LCTL("a"));
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}
