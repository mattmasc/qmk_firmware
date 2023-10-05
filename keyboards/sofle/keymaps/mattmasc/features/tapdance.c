#include QMK_KEYBOARD_H

#include "tapdance.h"

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 */
td_state_t dance_state(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

bool is_shifted(void) {
    return get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT ||
           get_oneshot_locked_mods() & MOD_MASK_SHIFT;
}

static void sentence_end(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

void sentence_end_finished (tap_dance_state_t *state, void *user_data) {
    set_last_keycode(KC_DOT);
}

void td_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        reset_keyboard();
    }
}

void td_qwrt(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        set_single_persistent_default_layer(_QWRT);
    }
}

void td_snrt(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        set_single_persistent_default_layer(_SNRT);
    }
}

void td_game(tap_dance_state_t *state, void *user_data) {
    if (layer_state_is(_GAME) && state->count == 1) {
        tap_code16(KC_ESC);
    } else {
        layer_invert(_GAME);
    }
}

void td_opp(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        switch (get_highest_layer(layer_state)) {
            case _NAV:
            case _NUM:
                layer_invert(_NAV);
                layer_invert(_NUM);
                break;
            case _MOUSE:
            case _FUN:
                layer_invert(_MOUSE);
                layer_invert(_FUN);
                break;
            default: break;
        }
    }
}

void td_off(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        uint8_t current_layer = get_highest_layer(layer_state);
        switch (current_layer) {
            case _NAV:
            case _NUM:
            case _MOUSE:
            case _FUN:
            case _SYM:
                layer_invert(current_layer);
                break;
            default: break;
        }
    }
}

void td_swbt(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        swap_hands_toggle();
    } else {
        layer_invert(_BUTTON);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, sentence_end_finished, NULL),
    [BOOT_TD] = ACTION_TAP_DANCE_FN(td_boot),
    [QWRT_TD] = ACTION_TAP_DANCE_FN(td_qwrt),
    [SNRT_TD] = ACTION_TAP_DANCE_FN(td_snrt),
    [GAME_TD] = ACTION_TAP_DANCE_FN(td_game),
    [OPP_TD] = ACTION_TAP_DANCE_FN(td_opp),
    [SWBT_TD] = ACTION_TAP_DANCE_FN(td_swbt),
    [OFF_TD] = ACTION_TAP_DANCE_FN(td_off),
};
