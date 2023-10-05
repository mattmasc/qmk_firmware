//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

#include "sentence_case.h"

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWRT:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _SNRT:
            oled_write_ln_P(PSTR("Snrt"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _SNRT:
        case _QWRT:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Func\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _BUTTON:
            oled_write_P(PSTR("Bttn\n"), false);
            break;
        case _MACRO:
            oled_write_P(PSTR("Macro"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    oled_write_P(keymap_config.autocorrect_enable ? PSTR("AC") : PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(is_sentence_case_on() ? PSTR("SC") : PSTR("  "), false);

    oled_write_P(swap_hands ? PSTR("SH") : PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P((led_usb_state.caps_lock) ? PSTR("CL") : PSTR("  "), false);

    oled_write_P(led_usb_state.num_lock ? PSTR("NL") : PSTR("  "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SL") : PSTR("  "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
