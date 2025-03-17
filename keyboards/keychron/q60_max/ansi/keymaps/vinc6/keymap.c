/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#define CW_LCTL CTL_T(KC_NO)
#define INPUT_S LT(0,KC_NO)

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    FN,
    L3,
    L4,
};

enum my_keycodes {
    SCRSHOT = SAFE_RANGE,
    WEBDICT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_60(
        KC_ESC,       KC_1,KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSLS, KC_GRV,
        LAG_T(KC_TAB),KC_Q,KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,            KC_BSPC,
        CW_LCTL,      KC_A,KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                      KC_ENT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, MO(MAC_FN),
                           KC_LOPTN, KC_LCMMD,                           KC_SPC,                             KC_RCMMD, KC_ROPTN),

    [MAC_FN] = LAYOUT_ansi_60(
        _______, KC_BRID,  KC_BRIU,  KC_MCTRL,KC_LNPAD,RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,   SCRSHOT, INPUT_S,
        KC_CAPS, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,    _______,            KC_DEL,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,                     _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, BAT_LVL, NK_TOGG, _______, KC_END,  KC_PGDN, KC_DOWN,             _______, _______,
                           _______,  _______,                            WEBDICT,                            _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_60(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,            KC_DEL,
        KC_LCTL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                      KC_ENT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, MO(FN),
                           KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT,  KC_RWIN),

    [FN] = LAYOUT_ansi_60(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    KC_INS,  KC_DEL,
        KC_CAPS, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,    _______,            KC_BSPC,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,                     _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, BAT_LVL, NK_TOGG, _______, KC_END,  KC_PGDN, KC_DOWN,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______),

    [L3] = LAYOUT_ansi_60(
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______),

    [L4] = LAYOUT_ansi_60(
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
                           _______,  _______,                            _______,                            _______,  _______),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    switch (keycode) {
        // take a screenshot on mac
        case SCRSHOT:
            if (record->event.pressed) {
                tap_code16(SCMD(KC_4));
            } else {
                tap_code(KC_SPC);
                tap_code(KC_BTN1);
            }
            break;

        case INPUT_S:
            if (record->tap.count && record->event.pressed) {
                // tap select next source in input menu
                tap_code16(LCA(KC_SPC));
            } else if (record->event.pressed) {
                // hold select the previous input source
                tap_code16_delay(LCTL(KC_SPC),1000);
            }
            break;

        case CW_LCTL:
            if (record->tap.count && record->event.pressed) {
                caps_word_toggle();
                return false;
            }
            break;

        case WEBDICT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("ct") SS_DELAY(80) "https://jisho.org/search/" SS_LCMD("v") SS_DELAY(800) "\n");
            }
            break;
    }
    return true;
}
