#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;


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
td_state_t cur_dance(tap_dance_state_t *state) {
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

tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, sentence_end_finished, NULL),
};
