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
    _QWERTY,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define ADJUST   MO(_ADJUST)

#define GUI_SPC  MT(MOD_LGUI, KC_SPACE)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 *      ,-------------------------------------------.                                              ,-------------------------------------------.
 *      |  Tab   |   Q  |   W  |   E  |   R  |   T  |                                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 *      |--------+------+------+------+------+------|                                              |------+------+------+------+------+--------|
 *      |   Esc  |   A  |   S  |   D  |   F  |   G  |                                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 *      |--------+------+------+------+------+------+-------------.                  ,-------------+------+------+------+------+------+--------|
 *      | f16    |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|                  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 *      `----------------------+------+------+------+------+------|                  |------+------+------+------+------+----------------------'
 *                             |Adjust| LGUI | LAlt/| Space| Nav  |                  | Sym  | Space| AltGr| RGUI | Menu |
 *                             |      |      | Enter|      |      |                  |      |      |      |      |      |
 *                             `----------------------------------'                  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                         KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_F14 ,
     KC_ESC  , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                         KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_ENT ,
     KC_F16  , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LOPT,KC_F13 ,      KC_RGUI, KC_RCTL, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_QUOT, KC_F15,
                                ADJUST , KC_LGUI, KC_BSPC, KC_LSFT, SYM   ,      NAV    , GUI_SPC ,KC_DEL, KC_RSFT, KC_CAPS
    ),


/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_F14,
     KC_ESC  , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , KC_ENT,
     KC_F16  , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LOPT,KC_F13,     KC_RGUI, KC_RCTL,  KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_QUOT, KC_F15,
                                ADJUST , KC_LGUI, KC_BSPC, KC_LSFT, SYM  ,     NAV    , GUI_SPC ,KC_DEL, KC_RSFT, KC_CAPS
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______  , KC_F9  , KC_F10 , KC_F11 , KC_F12,                                     KC_F16, KC_UNDO, KC_UP,   KC_BSPC,  KC_PGUP, _______,
      _______, _______  , KC_F5  , KC_F6  , KC_F7  , KC_F8,                                      KC_F17, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, _______,
      _______, _______  , KC_F1  , KC_F2  , KC_F3  , KC_F4, _______, _______, _______, _______,  KC_F18, KC_CUT, KC_COPY, KC_PSTE, KC_PGDN, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  &   |  \   |  {   |  }   |  $   |                              |   =  |  7   |  8   |  9   |  +   |   '    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  _   |  /   |  (   |  )   |  !   |                              |   ?  |  4   |  5   |  6   |  -   |   *    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   #  |  :   |  [   |  ]   |  "   |      |      |  |      |      |   @  |  1   |  2   |  3   |  %   |   ^    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |   0  |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV , KC_AMPR, KC_BSLS, KC_LCBR, KC_RCBR, KC_DLR ,                                       KC_EQL ,  KC_7  ,  KC_8 , KC_9 , KC_PLUS, KC_QUOT,
     KC_TILD , KC_UNDS, KC_SLSH, KC_LPRN, KC_RPRN, KC_EXLM,                                       KC_QUES,  KC_4  ,  KC_5 , KC_6 , KC_MINS, KC_ASTR,
     KC_PIPE , KC_HASH, KC_COLN, KC_LBRC, KC_RBRC, KC_DQUO, _______, _______,   _______, _______, KC_AT  ,  KC_1  ,  KC_2 , KC_3 , KC_PERC, KC_CIRC,
                                 _______, _______, _______, _______, _______,   _______,   KC_0 , _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |QWERTY|COLEMA|  |QWERTY|COLEMA|      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______ , _______, _______,                                      _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______ , _______, _______,                                      RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,COLEMAK,  QWERTY,    _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, KC_VOLD, KC_VOLU,_______, _______,    KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT
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
