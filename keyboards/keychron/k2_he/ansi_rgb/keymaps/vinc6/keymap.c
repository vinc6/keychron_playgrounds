/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"
// #include "keymap_japanese.h"

#define CMDBSPC LT(0,KC_DEL)
#define INPUT_S LT(0,KC_NO)
#define LCTL_CW CTL_T(KC_NO)

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

enum my_keycodes {
    SCRSHOT = SAFE_RANGE,
    PPXT_AI,
    WEBDICT,
    APPDICT,
    MSPAINT,
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_84(
            KC_ESC,         KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD,     RGB_VAD, RGB_VAI, KC_MPRV,      KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,    KC_VOLU, SCRSHOT, CMDBSPC, INPUT_S,
            KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,         KC_5,    KC_6,    KC_7,         KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,  KC_BSPC,          KC_PGUP,
            SCMD_T(KC_TAB), KC_Q,     KC_W,     KC_E,     KC_R,         KC_T,    KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC, KC_BSLS,          KC_PGDN,
            LCTL_CW,        KC_A,     KC_S,     KC_D,     LSFT_T(KC_F), KC_G,    KC_H,    RSFT_T(KC_J), KC_K,    KC_L,    KC_SCLN,  KC_QUOT,             KC_ENT,           KC_HOME,
            KC_LSFT,                  KC_Z,     KC_X,     KC_C,         KC_V,    KC_B,    KC_N,         KC_M,    KC_COMM, KC_DOT,   KC_SLSH,             KC_RSFT, KC_UP,   KC_END,
            MO(MAC_FN),     KC_LOPTN, KC_LCMMD,                                  KC_SPC,                                  KC_RCMMD, MO(MAC_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_84(
            _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,    _______,    PPXT_AI,
            KC_CAPS,    BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                WEBDICT,
            RGB_TOG,    RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                APPDICT,
            _______,    RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                _______,
            _______,              _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  KC_BTN1,  KC_BTN2,  _______,            _______,    KC_MS_UP,   _______,
            _______,    _______,  _______,                                _______,                                _______,  _______,  _______,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT),

    [WIN_BASE] = LAYOUT_ansi_84(
            KC_ESC,         KC_F1,    KC_F2,    KC_F3,    KC_F4,        KC_F5,   KC_F6,   KC_F7,        KC_F8,   KC_F9,   KC_F10,   KC_F11,     KC_F12,  MSPAINT, KC_DEL,  KC_INS,
            KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,         KC_5,    KC_6,    KC_7,         KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,  KC_BSPC,          KC_PGUP,
            KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,         KC_T,    KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC, KC_BSLS,          KC_PGDN,
            LCTL_CW,        KC_A,     KC_S,     KC_D,     LSFT_T(KC_F), KC_G,    KC_H,    RSFT_T(KC_J), KC_K,    KC_L,    KC_SCLN,  KC_QUOT,             KC_ENT,           KC_HOME,
            KC_LSFT,                  KC_Z,     KC_X,     KC_C,         KC_V,    KC_B,    KC_N,         KC_M,    KC_COMM, KC_DOT,   KC_SLSH,             KC_RSFT, KC_UP,   KC_END,
            MO(WIN_FN),     KC_LGUI,  KC_LALT,                                   KC_SPC,                                  KC_RALT,  MO(WIN_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_84(
            _______,    KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_PSCR,    _______,    _______,
            A(KC_CAPS), BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,
            RGB_TOG,    RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,
            _______,    RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                _______,
            _______,              _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  KC_BTN1,  KC_BTN2,  _______,            _______,    KC_MS_UP,   _______,
            _______,    _______,  _______,                                KC_APP,                                 _______,  _______,  _______,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT)
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    switch (keycode) {

        // Take a screenshot on Mac
        case SCRSHOT:
            if (record->event.pressed) {
                tap_code16(SCMD(KC_4));
            } else {
                tap_code(KC_SPC);
                tap_code(KC_BTN1);
            }
            break;

        // intercept hold function to send Command-Backspace
        case CMDBSPC:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(LCMD(KC_BSPC));
            }
            break;

        case INPUT_S:
            if (record->tap.count && record->event.pressed) {
                tap_code16(LCA(KC_SPC));                // tap select next source in input menu
            } else if (record->event.pressed) {
                tap_code16_delay(LCTL(KC_SPC),1000);    // hold select the previous input source
            }
            break;

        case LCTL_CW:
            if (record->tap.count && record->event.pressed) {
                caps_word_toggle(); // toggle Caps Word on tap
                return false;       // return false to ignore further processing of key
            }
            break;

        case PPXT_AI:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("ct") SS_DELAY(80) "https://www.perplexity.ai" SS_DELAY(800) "\n" SS_DELAY(2400) SS_LCMD("v") SS_DELAY(400) "\n");
            }
            break;

        case WEBDICT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("ct") SS_DELAY(80) "https://www.weblio.jp/content/" SS_LCMD("v") SS_DELAY(800) "\n");
            }
            break;

        case APPDICT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("c ") SS_DELAY(80) "dictionary" SS_DELAY(800) "\n" SS_DELAY(800) SS_LCMD("v"));
            }
            break;

        case MSPAINT:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_PSCR);
            } else {
                unregister_code(KC_PSCR);
                unregister_code(KC_LALT);
                SEND_STRING(SS_LGUI("r") SS_DELAY(80) "mspaint\n" SS_DELAY(800) SS_LCTL("v"));
            }
            break;
    }
    return true;
}

/*
// Shift + Caps lock, equivalent to Eisu key
const key_override_t shift_caps_override = 
    ko_make_basic(
        MOD_MASK_SHIFT, // modifiers
        CTL_T(CW_TOGG), // key
        S(KC_CAPS));    // replacement

// Alt + Caps lock, equivalent to Shift + Hiragana key
const key_override_t alt_caps_override =
    ko_make_basic(
        MOD_MASK_ALT,
        CTL_T(CW_TOGG),
        A(KC_CAPS));

// Ctrl + Caps lock, equivalent to Hiragana key
const key_override_t gui_caps_override =
    ko_make_basic(
        MOD_MASK_GUI,
        CTL_T(CW_TOGG),
        C(KC_CAPS));

const key_override_t **key_overrides = (const key_override_t *[]) {
    &shift_caps_override,
    &alt_caps_override,
    &gui_caps_override,
    NULL
};
*/
