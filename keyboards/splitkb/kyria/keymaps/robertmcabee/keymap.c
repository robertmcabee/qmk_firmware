/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _ADJUST
};


// Aliases for readability
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define ADJUST   MO(_ADJUST)

#define CMD_SPC  MT(MOD_LGUI, KC_SPACE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_F14,
     KC_ESC  , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , KC_QUOT,
     KC_F16  , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LOPT,KC_F13,     KC_RGUI, KC_RCTL,  KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_QUES, KC_F15,
                                ADJUST , KC_LGUI, KC_BSPC, KC_LSFT, SYM  ,     NAV    , CMD_SPC,KC_DEL, KC_ENT , KC_CAPS
    ),


    [_NAV] = LAYOUT(
      _______, _______  , KC_F9  , KC_F10 , KC_F11 , KC_F12,                                     RSG(KC_Z), KC_BSPC, KC_UP,   KC_DEL,  KC_PGUP, _______,
      _______, _______  , KC_F5  , KC_F6  , KC_F7  , KC_F8,                                      G(KC_Z), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
      _______, _______  , KC_F1  , KC_F2  , KC_F3  , KC_F4, _______, _______, _______, _______,  KC_F18, G(KC_X), G(KC_C), G(KC_V), _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [_SYM] = LAYOUT(
      KC_GRV , KC_AMPR, KC_BSLS, KC_LCBR, KC_RCBR, KC_DLR ,                                       KC_EQL ,  KC_7  ,  KC_8 , KC_9 , KC_PLUS, KC_QUOT,
     KC_TILD , KC_UNDS, KC_SLSH, KC_LPRN, KC_RPRN, KC_EXLM,                                       KC_QUES,  KC_4  ,  KC_5 , KC_6 , KC_MINS, KC_ASTR,
     KC_PIPE , KC_HASH, KC_COLN, KC_LBRC, KC_RBRC, KC_DQUO, _______, _______,   _______, _______, KC_AT  ,  KC_1  ,  KC_2 , KC_3 , KC_PERC, KC_CIRC,
                                 _______, _______, _______, _______, _______,   _______, _______ ,  KC_0 , _______, _______
    ),


    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______ , _______, _______,                                      _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______ , _______, _______,                                      RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,KC_VOLU, KC_BRIU,    KC_BRIU, KC_VOLU, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, KC_VOLD, KC_MPRV,KC_VOLD, KC_BRID,    KC_BRID, KC_VOLD, KC_MNXT, KC_MPLY, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
