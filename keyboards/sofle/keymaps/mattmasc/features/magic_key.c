#include QMK_KEYBOARD_H

#include "magic_key.h"

static void process_comp1(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A: SEND_STRING(/*a*/"tion"); set_last_keycode(KC_N); break;
        case KC_B: SEND_STRING(/*b*/"efore"); set_last_keycode(KC_E); break;
        case KC_C: SEND_STRING(/*c*/"iao"); set_last_keycode(KC_O); break;
        case KC_E: SEND_STRING(/*e*/"nto"); set_last_keycode(KC_O); break;
        case KC_I: SEND_STRING(/*i*/"tion"); set_last_keycode(KC_N); break;
        case KC_S: SEND_STRING(/*s*/"sion"); set_last_keycode(KC_N); break;
        case KC_T: SEND_STRING(/*t*/"heir"); set_last_keycode(KC_R); break;
        case KC_W: SEND_STRING(/*w*/"hich"); set_last_keycode(KC_H); break;
        case KC_COMM: SEND_STRING(/*,*/" and"); set_last_keycode(KC_D); break;
        case KC_HASH: SEND_STRING(/*#*/"include"); set_last_keycode(KC_E); break;
        case KC_DOT: tap_code(KC_SPC); add_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT)); set_last_keycode(KC_SPC); break;
        default: break;
    }
}

static void process_comp2(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A: SEND_STRING(/*a*/"bout"); set_last_keycode(KC_T); break;
        case KC_B: SEND_STRING(/*b*/"ecause"); set_last_keycode(KC_E); break;
        case KC_C: SEND_STRING(/*c*/"ont"); set_last_keycode(KC_T); break;
        case KC_E: SEND_STRING(/*e*/"llo"); set_last_keycode(KC_O); break;
        case KC_I: SEND_STRING(/*i*/"nter"); set_last_keycode(KC_R); break;
        case KC_S: SEND_STRING(/*s*/"tate"); set_last_keycode(KC_E); break;
        case KC_T: SEND_STRING(/*t*/"here"); set_last_keycode(KC_E); break;
        case KC_W: SEND_STRING(/*w*/"ould"); set_last_keycode(KC_D); break;
        case KC_COMM: SEND_STRING(/*,*/" but"); set_last_keycode(KC_T); break;
        case KC_DOT: SEND_STRING(/*.*/"./"); set_last_keycode(KC_SLSH); break;
        default: break;
    }
}

process_record_result_t process_magic_key(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && record->tap.count && !record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    uint16_t tap_kc = extract_tapping_keycode(get_last_keycode());
    uint8_t mods = get_last_mods();

    switch (keycode) {
        case ALT_LMGC:
            process_comp1(tap_kc, mods);
            return PROCESS_RECORD_RETURN_FALSE;

        case ALT_RMGC:
            process_comp2(tap_kc, mods);
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}
