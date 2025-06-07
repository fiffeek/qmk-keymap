#include "config.h"
#include "keycodes.h"
#include "modifiers.h"
#include QMK_KEYBOARD_H
#include "../../../../../features/achordion.h"
#include "voyager.h"
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

#define HOME_A MT(MOD_LGUI, KC_A)
#define HOME_R MT(MOD_LALT, KC_R)
#define HOME_S MT(MOD_LCTL, KC_S)
#define HOME_T MT(MOD_LSFT, KC_T)

#define HOME_N MT(MOD_RSFT, KC_N)
#define HOME_E MT(MOD_RCTL, KC_E)
#define HOME_I MT(MOD_LALT, KC_I)
#define HOME_O MT(MOD_RGUI, KC_O)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    TG(5),          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,
    CW_TOGG,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_UNDS,        KC_SCLN,
    KC_ESCAPE,      HOME_A,         HOME_R,         HOME_S,         HOME_T,         KC_G,                                           KC_M,           HOME_N,         HOME_E,         HOME_I,         HOME_O,         KC_QUOTE,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
                                                    LT(1,KC_SPACE), LT(2,KC_TAB),                                   LT(4,KC_ENTER), LT(3,KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_QUOTE,       KC_LABK,        KC_RABK,        KC_DQUO,        KC_GRAVE,                                       KC_AMPR,        KC_GRAVE,       KC_LBRC,        KC_RBRC,        KC_PERC,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_HASH,                                        KC_PIPE,        KC_COLN,        KC_LPRN,        KC_RPRN,        KC_QUES,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_CIRC,        KC_SLASH,       KC_ASTR,        KC_BSLS,        KC_UNDS,                                        KC_TILD,        KC_DLR,         KC_LCBR,        KC_RCBR,        KC_AT,          KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LALT(KC_1),     LALT(KC_2),     LALT(KC_3),     LALT(KC_4),     LALT(KC_5),                                     KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LCTL(LSFT(KC_PSCR)), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_NO,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     LGUI(KC_4),     LGUI(KC_5),                                     RGUI(KC_6),     RGUI(KC_7),     RGUI(KC_8),     RGUI(KC_9),     RGUI(KC_0),     KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_UP,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    TG(5), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_Q, KC_W, KC_W, KC_E,                                 KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_UP,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_CTRL, KC_A, KC_S, KC_D, KC_F,                                 KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_Z, KC_X, KC_C, KC_V,                                 KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_TRANSPARENT,
                                                    KC_LEFT_SHIFT, KC_TAB,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_SPACE):
            return TAPPING_TERM - 50;
        case LT(2, KC_TAB):
            return TAPPING_TERM - 50;
        case LT(4, KC_ENTER):
            return TAPPING_TERM - 50;
        case LT(3, KC_BSPC):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {245, 195, 249}, {0, 0, 0}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {5, 105, 255}, {5, 105, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {0, 0, 0}, {5, 105, 255}, {5, 105, 255}},

    [1] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {0, 0, 0}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {0, 0, 0}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {0, 0, 0}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {0, 0, 0}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {43, 85, 255}, {0, 0, 0}, {43, 85, 255}, {43, 85, 255}},

    [2] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {118, 235, 221}, {118, 235, 221}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {118, 235, 221}, {118, 235, 221}},

    [3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {128, 222, 183}, {128, 222, 183}, {128, 222, 183}, {128, 222, 183}, {128, 222, 183}, {0, 0, 0}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {0, 0, 0}, {0, 0, 0}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {128, 222, 183}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {5, 56, 255}, {5, 56, 255}, {5, 56, 255}, {5, 56, 255}, {5, 56, 255}, {0, 0, 0}, {5, 56, 255}, {5, 56, 255}, {5, 56, 255}, {5, 56, 255}, {5, 56, 255}, {0, 0, 0}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {118, 235, 221}, {0, 0, 0}, {128, 222, 183}, {118, 235, 221}},

    [4] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {21, 204, 255}, {21, 204, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {245, 255, 255}, {0, 0, 0}, {21, 204, 255}, {0, 0, 0}, {0, 0, 0}, {21, 204, 255}, {0, 0, 0}, {0, 0, 0}, {21, 204, 255}, {21, 204, 255}, {21, 204, 255}, {21, 204, 255}, {0, 0, 0}, {0, 0, 0}, {21, 204, 255}, {21, 204, 255}, {21, 204, 255}, {21, 204, 255}, {0, 0, 0}, {21, 204, 255}, {21, 204, 255}},

    [5] = {{245, 100, 100}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {245, 195, 249}, {0, 0, 0}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {5, 105, 255}, {5, 105, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {5, 105, 255}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {245, 195, 249}, {0, 0, 0}, {5, 105, 255}, {5, 105, 255}},
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

void housekeeping_task_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Also allow same-hand holds when the other key is in the rows outside the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboards are split.
    uint8_t row = other_record->event.key.row % (MATRIX_ROWS / 2);
    if (!(1 <= row && row <= 3)) {
        return true;
    }
    // Same but this includes the thumb key clusters.
    row = tap_hold_record->event.key.row % (MATRIX_ROWS / 2);
    if (!(1 <= row && row <= 3)) {
        return true;
    }

    switch (tap_hold_keycode) {
        // Allow for Shift + Q
        case HOME_T:
            if (other_keycode == KC_Q) {
                return true;
            }
            break;
        // WIN + Shift for i3
        case HOME_A:
            if (other_keycode == HOME_T) {
                return true;
            }
            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        default:
            return 800; // Use a timeout of 800 ms.
    }
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    // Disable streak detection on LT keys.
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return 0;
    }

    // Exceptions so that certain hotkeys don't get blocked as streaks.
    switch (tap_hold_keycode) {
        // CTRL + ...
        case HOME_S:
        case HOME_E:
            if (next_keycode == KC_C || next_keycode == KC_V || next_keycode == KC_W || next_keycode == KC_A || next_keycode == HOME_N) {
                return 0;
            }
            break;
    }

    // Otherwise, tap_hold_keycode is a mod-tap key.
    const uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if ((mod & MOD_LSFT) != 0) {
        return 100; // A short streak timeout for Shift mod-tap keys.
    } else {
        return 220; // A longer timeout otherwise.
    }
}
