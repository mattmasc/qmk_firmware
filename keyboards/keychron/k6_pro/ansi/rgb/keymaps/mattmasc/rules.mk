VIA_ENABLE = yes
OPT_DEFS += -DDYNAMIC_KEYMAP_LAYER_COUNT=12
LTO_ENABLE = yes
CAPS_WORD_ENABLE = yes
AUTOCORRECT_ENABLE = yes
MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
REPEAT_KEY_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes

VPATH += keyboards/gboards

SRC += tapdance.c \
	   features/achordion.c \
       features/select_word.c \
       features/mouse_turbo_click.c
