// Copyright 2022 mjohns
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <keymap_swedish.h>

enum layers { BASE, NAV, SYMBOLS };

#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_CAP LCTL_T(KC_CAPS)
#define ALT_BSP LALT_T(KC_BSPC)
#define LT_SCLN LT(NAV, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                                         KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    SE_ARNG,
        CTL_CAP, KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                                         KC_H, KC_J,    KC_K,    KC_L,   SE_ODIA, SE_ADIA
        KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,                                         KC_N, KC_M,    KC_COMM, KC_DOT, SE_QUOT, KC_RSFT,
                                         KC_LBRC, KC_RBRC,                                                     KC_LEFT, KC_DOWN,
                                                 KC_BSPC, CTL_ESC,                       KC_PGDN, KC_ENT
    ),
    [NAV] = LAYOUT(
        _______, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                         KC_PPLS, KC_P1,   KC_P2,  KC_P3,   KC_PSLS, _______,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,                                           KC_PAST, KC_PCMM, KC_P0,  KC_PDOT, KC_PENT, _______,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,                                           KC_PAST, KC_PCMM, KC_P0,  KC_PDOT, KC_PENT, _______,
                KC_F7,   KC_F8,                                                                 KC_F9,   KC_F10,
                                                              KC_BTN2, _______,     KC_END,  _______
    ),
    [SYMBOLS] = LAYOUT(
                _______, _______, _______, _______, _______, _______,                                           SE_AMPR, SE_EQL, SE_LBRC, SE_RBRC, SE_TILD, KC_F12,
                SE_TILD, KC_EXLM, SE_DQUO, KC_HASH, SE_DLR, KC_PERC,                                            SE_PLUS, SE_LCBR, SE_LPRN, SE_RPRN, SE_RCBR, SE_QUES,
                _______, SE_PIPE, SE_AT, SE_LABK, SE_RABK, SE_PIPE,                                             SE_MINS, SE_UNDS, SE_SLSH, SE_BSLS, SE_CIRC, SE_ASTR,
                                          KC_F7,   KC_F8,                                                                 KC_F9,   KC_F10,
                                                              KC_BTN2, _______,     KC_END,  _______
    )
    // clang-format on
};
