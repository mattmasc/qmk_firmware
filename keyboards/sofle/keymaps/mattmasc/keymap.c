#include QMK_KEYBOARD_H

// All custom keycodes and aliases can be found in precondition_keymap.h
#include "definitions/layers.h"
#include "definitions/keycodes.h"

#include "features/oled.c"
#include "features/combos.h"
#include "features/tapdance.h"
#include "features/achordion.h"
#include "features/select_word.h"
#include "features/mouse_turbo_click.h"
#include "features/layer_lock.h"
#include "features/sentence_case.h"
#include "features/casemodes.h"
#include "features/macros.h"
#include "features/shortcuts.h"
#include "features/magic_key.h"

bool game_chat_set;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Swap |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Swap |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   '  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Esc  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | RAlt |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RAlt |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR |LShift|  Tab | Bspc | /  Del  /       \Enter \  | Space|Repeat|RShift| RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWRT] = LAYOUT(
  TD(SWBT_TD),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD(SWBT_TD),
  KC_GRV,     KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_QUOT,    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ESC,
  ALT_LMGC,    KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ALT_RMGC,
    KC_LCTL,KC_LSFT,LT(_SYM,KC_TAB),LT(_NAV,KC_BSPC),LT(_MOUSE,KC_DEL),     LT(_FUN,KC_ENT),LT(_NUM,KC_SPC),M_REP, KC_RSFT, KC_RCTL
),

/*
 * SNRT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Swap |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Swap |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   X  |   P  |   L  |   M  |   K  |                    |   ,  |   W  |   O  |   U  |   Q  |  -   |
 * |------+------+------+---(--+KC_CAPS+-----|                    |------+CW_TOGG+--)--+------+------+------|
 * |   '  |   S  |   N  |   R  |   T  |   G  |-------.    ,-------|   Y  |   C  |   A  |   E  |   I  |  Esc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | RAlt |   Z  |   B  |   H  |   D  |   V  |-------|    |-------|   .  |   F  |   /  |   ;  |   J  | RAlt |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR |LShift|  Tab | Bspc | /  Del  /       \Enter \  | Space|Repeat|RShift| RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SNRT] = LAYOUT(
  TD(SWBT_TD),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    TD(SWBT_TD),
  KC_GRV,     KC_X,   KC_P,    KC_L,    KC_M,    KC_K,                            KC_COMM,KC_W,    KC_O,    KC_U,    KC_Q,    KC_MINS,
  KC_QUOT,   HOME_S, HOME_N,  HOME_R,  HOME_T,   KC_G,                            KC_Y,  HOME_C,  HOME_A,  HOME_E,  HOME_I,   KC_ESC,
  ALT_LMGC,    KC_Z,   KC_B,    KC_H,    KC_D,    KC_V, KC_MUTE,          _______, KC_DOT, KC_F,  KC_SLSH, KC_SCLN,   KC_J,    ALT_RMGC,
   KC_LCTL,KC_LSFT,LT(_SYM,KC_TAB),LT(_NAV,KC_BSPC),LT(_MOUSE,KC_DEL),  LT(_FUN,KC_ENT),LT(_NUM,KC_SPC),M_REP,KC_RSFT,KC_RCTL
),

/*
 * GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  =   |   1  |   2  |   3  |   4  |                    |  5   |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ;  |   Q  |   W  |   E  |   R  |                    |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTR |LShift|   A  |   S  |   D  |   F  |-------.    ,-------|   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |KC_CAPS|  .  |   Z  |   X  |   C  |   V  |-------|    |-------|   B  |   N  |   M  |   ,  |   .  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LAlt |   T  |  ,   |Space | /   G   /       \Enter \  |Space | Bspc | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GAME] = LAYOUT(
  TD(GAME_TD),KC_EQL, KC_1,    KC_2,    KC_3,    KC_4,                     KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TAB,    KC_SCLN, KC_Q,    KC_W,    KC_E,    KC_R,                     KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_LCTL,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                     KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_CAPS,   KC_DOT,  KC_Z,    KC_X,    KC_C,    KC_V, KC_MUTE,   _______, KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
         KC_LALT,  LT(_FUN,KC_T),   KC_MINS, KC_SPC,  KC_G,               M_GCHAT, LT(_NAV,KC_SPC), LT(_NUM,KC_BSPC), KC_RALT, KC_RGUI
),

/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |QK_BOOT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  TD(SWBT_TD),TD(BOOT_TD),TD(GAME_TD),TD(SNRT_TD),TD(QWRT_TD),_______,           M_LLOCK,_______,_______,_______,_______,TD(SWBT_TD),
  _______, KC_LEFT,  KC_DOWN, KC_UP,  KC_RGHT,  _______,                         M_SELWORD, S_PASTE, S_COPY, S_CUT, _______, _______,
  _______,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                         KC_SPC, KC_LEFT,  KC_DOWN, KC_UP,  KC_RGHT, _______,
  _______, _______, _______, _______, TD(OPP_TD), _______,  _______,   _______,  KC_TAB, S_HOME,  KC_PGDN, KC_PGUP, S_END, _______,
        _______, _______, _______, TD(OFF_TD), _______,                    KC_ENT,LT(_NUM,KC_BSPC),KC_DEL, _______, _______
),

/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QK_BOOT|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUM] = LAYOUT(
  TD(SWBT_TD), _______, _______, _______, _______, M_LLOCK,          _______, TD(QWRT_TD), TD(SNRT_TD), TD(GAME_TD), TD(BOOT_TD),  TD(SWBT_TD),
  _______, KC_ASTR, KC_6, KC_5, KC_4, KC_BSLS,                       _______, _______, _______, _______, _______, _______,
  _______, KC_PLUS, KC_3, KC_2, KC_1, KC_MINS,                       _______, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,
  _______, KC_LPRN, KC_9, KC_8, KC_7, KC_RPRN, _______,       _______, _______, TD(OPP_TD), _______, _______, _______, _______,
             _______, _______, KC_DOT,LT(_NAV,KC_0),KC_EQL,       _______, TD(OFF_TD), _______, _______, _______
),

/* MOUSE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |QK_BOOT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MOUSE] = LAYOUT(
TD(SWBT_TD),TD(BOOT_TD),TD(GAME_TD),TD(SNRT_TD),TD(QWRT_TD),_______,       M_LLOCK, _______, _______, _______, _______, TD(SWBT_TD),
_______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
_______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
_______, _______, _______, _______, TD(OPP_TD), _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
             _______, _______, _______, TD(OFF_TD), _______,           LT(_FUN,KC_BTN2), KC_BTN1, KC_BTN3, _______, _______
),
/* FUN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QK_BOOT| F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FUN] = LAYOUT(
  TD(SWBT_TD), _______, _______, _______, _______, M_LLOCK,            _______, TD(QWRT_TD), TD(SNRT_TD), TD(GAME_TD), TD(BOOT_TD),  TD(SWBT_TD),
  _______, KC_F12, KC_F7, KC_F8, KC_F9, _______,                       _______, _______, _______, _______, _______, _______,
  _______, KC_F11, KC_F4, KC_F5, KC_F6, KC_APP,                        _______, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,
  _______, KC_F10, KC_F1, KC_F2, KC_F3, KC_ENT, _______,      _______, _______, TD(OPP_TD), _______, _______, _______, _______,
    _______, _______,KC_PAUS,KC_PSCR,LT(_MOUSE,KC_SCRL),           _______, TD(OFF_TD), _______, _______, _______
),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Swap |      |      |      |      |      |                    |      |      |      |      |      | Swap |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ?  |   [  |   ]  |   $  |   &  |                    |   "  |   _  |   <  |   >  |   #  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   (  |   )  |   :  |   |  |-------.    ,-------|   '  |   =  |   +  |   -  |   !  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   ;  |   {  |   }  |   @  |   ~  |-------|    |-------|   `  |   /  |   *  |   \  |   ^  |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            |      |      |      |Repeat| / Space /      \ Space \  |Repeat|      |      |      |
 *            |      |      |      |      |/       /        \       \ |      |      |      |      |
 *            `-----------------------------------'          '-------''---------------------------'
 */
[_SYM] = LAYOUT(
  TD(SWBT_TD), _______, _______, _______, _______, M_LLOCK,                   M_LLOCK, _______, _______, _______, _______, TD(SWBT_TD),
  _______,     KC_QUES, KC_LBRC, KC_RBRC, KC_DLR, KC_AMPR,                   M_DQUO, KC_UNDS, KC_LABK, KC_RABK, KC_HASH, _______,
  _______,     HOME_PE, HOME_LP, HOME_RP, HOME_CO, KC_PIPE,                   M_SQUO, HOME_EQ, HOME_PL, HOME_MI, HOME_EX, _______,
  _______,      KC_SCLN, KC_LCBR, KC_RCBR, KC_AT,    M_TILD, _______, _______, M_BTIC, KC_SLSH, KC_ASTR, KC_BSLS, M_CIRC, _______,
                  _______, _______, _______, QK_REP, KC_SPC,               KC_SPC, QK_REP, _______, _______, _______
),
/* BUTTON
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |QK_BOOT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / Enter /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_BUTTON] = LAYOUT(
  TD(SWBT_TD), TD(BOOT_TD), TD(GAME_TD), TD(SNRT_TD), TD(QWRT_TD), _______,   _______, TD(QWRT_TD), TD(SNRT_TD), TD(GAME_TD), TD(BOOT_TD),  TD(SWBT_TD),
  KC_ESC, S_UNDO,  S_CUT, S_COPY, S_PASTE, S_REDO,                            S_REDO, S_PASTE, S_COPY, S_CUT, S_UNDO, KC_ESC,
  KC_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_ENT,                         KC_ENT, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TAB,
  _______, _______, _______, _______, _______, KC_SPC, _______,      _______, KC_SPC, _______, _______, _______, _______, _______,
               KC_DEL, KC_BSPC, KC_BTN3, KC_BTN1, KC_BTN2,              KC_BTN2, KC_BTN1, KC_BTN3, KC_BSPC, KC_DEL
),
/* MACRO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |QWERTY| SNRT |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MACRO] = LAYOUT(
  TD(SWBT_TD), XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(SWBT_TD),
  XXXXXXX,  XXXXXXX, DM_REC1,  DM_PLY1,   XXXXXXX,  XXXXXXX,                    XXXXXXX, XXXXXXX, DM_PLY2, DM_REC2, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, KC_CAPS,  CM_WORD,  CM_CAMEL,  M_TURBO,                   CM_XCASE, CM_SNAKE, CM_KEBAB, CM_SLASH, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
/* MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |QWERTY| SNRT |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MEDIA] = LAYOUT(
  TD(SWBT_TD), QK_BOOT, TG(_GAME), M_QWRT, M_SNRT, CG_TOGG,                  XXXXXXX, AC_TOGG, SC_TOGG, XXXXXXX, XXXXXXX, TD(SWBT_TD),
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MYCM, KC_CALC, KC_MAIL, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSEL, XXXXXXX,
              _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______
)
};

// only runs when when the layer is changed, good for updating LED's and clearing sticky state
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    combo_enable(); // by default, enable combos.

    switch (layer) {
        case _QWRT:
        case _SNRT:
        case _NAV:
        case _NUM:
        case _MOUSE:
        case _FUN:
        case _SYM:
        case _BUTTON:
        case _MACRO:
        case _MEDIA:
            break;
        case _GAME:
            combo_disable(); // Disable combos in game
        default:
            clear_mods();
            set_last_keycode(KC_TRNS);  // Forget last key and mod
            set_last_mods(get_mods());
            break;
    }
    state = update_tri_layer_state(state, _NAV, _NUM, _MACRO);
    state = update_tri_layer_state(state, _MOUSE, _FUN, _MEDIA);
    return state;
};

void matrix_scan_user(void) {
    achordion_task();
    sentence_case_task();
    layer_lock_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    switch (other_keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            other_keycode &= 0xff;  // Get base keycode.
    }

    // Allow same-hand holds with layer keys.
    switch (tap_hold_keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case ALT_LMGC:
        case ALT_RMGC:
            return true;
    }

    // Allow same-hand holds with non-alpha keys.
    if (other_keycode > KC_Z) { return true; }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case M_REP:
        case ALT_LMGC:
        case ALT_RMGC:
            return false;  // Ignore keys.
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_case_modes(keycode, record)) { return false; }
    if (!process_sentence_case(keycode, record)) { return false; }

    // Process shortcuts
    switch (process_shortcuts(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE: return true;
        case PROCESS_RECORD_RETURN_FALSE: return false;
        default: break;
    };

    // Process macros
    switch (process_macros(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE: return true;
        case PROCESS_RECORD_RETURN_FALSE: return false;
        default: break;
    };

    // Process magic keys
    switch (process_magic_key(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE: return true;
        case PROCESS_RECORD_RETURN_FALSE: return false;
        default: break;
    };

    if (!process_layer_lock(keycode, record, M_LLOCK)) { return false; }
    if (!process_select_word(keycode, record, M_SELWORD)) { return false; }
    if (!process_mouse_turbo_click(keycode, record, M_TURBO)) { return false; }

    switch (keycode) {
        case M_QWRT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWRT);
            }
            break;
        case M_SNRT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SNRT);
            }
            break;
        case M_REP:
            if (record->tap.count) {
                if (record->event.pressed) {
                    register_mods(get_last_mods());
                    register_code16(get_last_keycode());
                } else {
                    unregister_code16(get_last_keycode());
                    unregister_mods(get_last_mods());
                }
            } else if (record->event.pressed) {
                layer_on(_SYM);
            } else {
                layer_off(_SYM);
            }
            return false; // Return false to ignore further processing of key
        case KC_ESC:                                       // Cancels chat mode in most games
            if (game_chat_set && record->event.pressed) {  // Checks if M_GCHAT was pressed in-game
                tap_code16(KC_ESC);
                game_chat_set = false;
                layer_invert(_GAME);                     // Switches back to GAMING layer after chatting
            }
            break; // Let QMK handle the rest
        case KC_ENT:
            if (game_chat_set && record->event.pressed) {  // Checks if M_GCHAT was pressed in-game
                tap_code16(KC_ENT);
                game_chat_set = false;
                layer_invert(_GAME);                     // Switches back to GAMING layer after chatting
            }
            break; // Let QMK handle the rest
        // M_GCHAT: A key that taps enter to enable chat in-game, and temporarily toggles typing layer
        // When done chatting, pressing enter or esc will automatically swap back to game layer
        case M_GCHAT:
            if (record->event.pressed) {
                tap_code16(KC_ENT);
                layer_invert(_GAME);
                game_chat_set = true;
            }
            break;
        case HOME_PE:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PERC);
                return false;
            }
            break;
        case HOME_LP:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case HOME_RP:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case HOME_CO:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
                return false;
            }
            break;
        case HOME_EQ:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                return false;
            }
            break;
        case HOME_PL:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PLUS);
                return false;
            }
            break;
        case HOME_MI:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS);
                return false;
            }
            break;
        case HOME_EX:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EXLM);
                return false;
            }
            break;
        case SC_TOGG:
            if (record->event.pressed) {
                sentence_case_toggle();
            }
            break;
        case CM_WORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            break;
        case CM_CAMEL:
            if (record->event.pressed) {
                enable_xcase_with(KC_LSFT);
            }
            break;
        case CM_SLASH:
            if (record->event.pressed) {
                enable_xcase_with(KC_SLSH);
            }
            break;
        case CM_SNAKE:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            break;
        case CM_KEBAB:
            if (record->event.pressed) {
                enable_xcase_with(KC_MINS);
            }
            break;
        case CM_XCASE:
            if (record->event.pressed) {
                enable_xcase();
            }
            break;
    }
    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWRT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_SNRT] =   { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [_GAME] =   { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [_NAV] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(S_UNDO, S_REDO) },
    [_NUM] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [_MOUSE] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [_FUN] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [_SYM] =  { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
    [_BUTTON] = { ENCODER_CCW_CW(S_UNDO, S_REDO),   ENCODER_CCW_CW(S_UNDO, S_REDO) },
    [_MEDIA] = { ENCODER_CCW_CW(_______, _______),   ENCODER_CCW_CW(_______, _______) },
};
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_T):
        case LCTL_T(KC_C):
            return TAPPING_TERM + 0;
        case LSFT_T(KC_R):
        case LSFT_T(KC_A):
            return TAPPING_TERM + 20;
        case LALT_T(KC_N):
        case LALT_T(KC_E):
            return TAPPING_TERM + 40;
        case LGUI_T(KC_S):
        case LGUI_T(KC_I):
            return TAPPING_TERM + 60;
        default:
            return TAPPING_TERM;
    }
}
