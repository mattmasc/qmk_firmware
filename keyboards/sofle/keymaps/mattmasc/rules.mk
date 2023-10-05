SRC += definitions/keycodes.c
SRC += features/achordion.c
SRC += features/select_word.c
SRC += features/mouse_turbo_click.c
SRC += features/layer_lock.c
SRC += features/sentence_case.c
SRC += features/tapdance.c
SRC += features/casemodes.c
SRC += features/macros.c
SRC += features/shortcuts.c
SRC += features/magic_key.c

INTROSPECTION_KEYMAP_C = features/combos.c

SPLIT_KEYBOARD = yes
CONVERT_TO=elite_pi
# Bootloader selection
BOOTLOADER = rp2040

LTO_ENABLE = yes

CONSOLE_ENABLE = no

OLED_ENABLE = yes

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

SWAP_HANDS_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
AUTOCORRECT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
REPEAT_KEY_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
# VIA_ENABLE = yes
