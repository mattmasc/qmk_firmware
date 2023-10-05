#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define ENCODER_DIRECTION_FLIP

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 180

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 0

// Enables handling for per key `TAPPING_TERM` settings
#define TAPPING_TERM_PER_KEY

// Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the `TAPPING_TERM`
// See [Permissive Hold](tap_hold.md#permissive-hold) for details
#define PERMISSIVE_HOLD

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

#define DYNAMIC_KEYMAP_LAYER_COUNT 11

#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.
#define SENTENCE_CASE_TIMEOUT 3000  // Reset state after 3 seconds.
