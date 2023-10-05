#include QMK_KEYBOARD_H

#include "combos.h"

const uint16_t PROGMEM CAMEL[] = {KC_P, HOME_N, COMBO_END};
const uint16_t PROGMEM WORD[] = {KC_L, HOME_R, COMBO_END};
const uint16_t PROGMEM CAPS[] = {KC_M, HOME_T, COMBO_END};
const uint16_t PROGMEM SNAKE[] = {KC_W, HOME_C, COMBO_END};
const uint16_t PROGMEM KEBAB[] = {KC_O, HOME_A, COMBO_END};
const uint16_t PROGMEM SLASH[] = {KC_U, HOME_E, COMBO_END};

combo_t key_combos[] = {
    COMBO(CAMEL, CM_CAMEL),
    COMBO(WORD, CM_WORD),
    COMBO(CAPS, KC_CAPS),
    COMBO(SNAKE, CM_SNAKE),
    COMBO(KEBAB, CM_KEBAB),
    COMBO(SLASH, CM_SLASH),
};
