#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _FN,
    _GAME
};

// Aliases
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FN       MO(_FN)
#define GAME     TG(_GAME)

#define CMD_SPC  MT(MOD_LGUI, KC_SPACE)
#define NAV_ENT  LT(_NAV, KC_ENT)
#define SYM_BKS  LT(_SYM, KC_BSPC)

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
//  * ,------------------------------------------.                              ,------------------------------------------.
//  * |   [   |  Q   |  W   |  F   |  P   |  B   |                              |  J   |  L   |  U   |  Y   | ; :  |  - _  |
//  * |-------+------+------+------+------+------|                              |------+------+------+------+------+-------|
//  * |       |  A   |  R   |  S   |  T   |  G   |                              |  M   |  N   |  E   |  I   |  O   |  ' "  |
//  * |-------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
//  * |   ]   |  Z   |  X   |  C   |  D   |  V   |      |      |  |      |      |  K   |  H   | , <  | . >  | / ?  |  \ |  |
//  * `---------------------+------+------+------+------+------|  |------+------+------+------+------+---------------------'
//  *                       |      |      |      |      |      |  |      |      |      |      |      |
//  *                       |      |      |      |      |      |  |      |      |      |      |      |
//  *                       `----------------------------------'  `----------------------------------'

    [_COLEMAK_DH] = LAYOUT( 
     KC_LBRC , KC_Q ,  KC_W ,  KC_F  ,  KC_P ,  KC_B ,                                        KC_J ,  KC_L   ,   KC_U ,   KC_Y , KC_SCLN, KC_MINS,
     KC_CAPS , KC_A ,  KC_R ,  KC_S  ,  KC_T ,  KC_G ,                                        KC_M ,  KC_N   ,   KC_E ,   KC_I ,   KC_O , KC_QUOT,
     KC_RBRC , KC_Z ,  KC_X ,  KC_C  ,  KC_D ,  KC_V , KC_LOPT, KC_F13,    KC_CAPS, KC_LCTL,  KC_K ,  KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_BSLS,
                             KC_LGUI ,KC_BSPC,  SYM  , KC_LSFT, FN    ,    KC_TAB , CMD_SPC,NAV_ENT, KC_DEL  ,  KC_ESC 
    ),
    

    [_NAV] = LAYOUT(
      _______, _______, _______,  KC_UP , _______, _______,                                       _______, _______, KC_PGUP, _______, _______, _______,
      _______, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,                                       _______, KC_HOME, KC_PGDN, KC_END , _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    ),


    [_SYM] = LAYOUT(
      KC_TILD, KC_AT  , KC_HASH, KC_EXLM, KC_PERC, KC_GRV ,                                       _______,  KC_7  ,  KC_8 , KC_9 , KC_COLN, KC_UNDS,
      _______, KC_AMPR, KC_PAST, KC_DLR , KC_LPRN, KC_RPRN,                                       _______,  KC_4  ,  KC_5 , KC_6 , KC_0   , KC_DQUO,
      _______, KC_EQL , KC_PLUS, KC_CIRC, KC_LCBR, KC_RCBR, _______, _______,   _______, _______, _______,  KC_1  ,  KC_2 , KC_3 , KC_QUES, KC_PIPE,
                                 _______, _______, _______, _______, _______,   _______, _______ ,  KC_0 , _______, _______
    ),


    [_FN] = LAYOUT(
      KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 ,                                        KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 ,
       KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,                                        KC_F7  ,  KC_F8 ,  KC_F9 ,  KC_F10,  KC_F11, KC_F12 ,
      _______, _______, _______, _______, _______, _______, GAME   , _______,    KC_BRIU, KC_VOLU, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    KC_BRID, KC_VOLD, KC_MPRV, KC_MNXT, KC_MPLY
    ),

    [_GAME] = LAYOUT(
     KC_LBRC, KC_Q ,  KC_W   ,  KC_UP ,   KC_P ,   KC_B ,                                            KC_J ,   KC_L ,   KC_U ,  KC_Y  , KC_SCLN,   GAME ,
     KC_TAB , KC_A ,  KC_LEFT, KC_DOWN,KC_RIGHT,   KC_G ,                                            KC_M ,   KC_1 ,   KC_2 ,  KC_3  ,   KC_4 , KC_QUOT,
     KC_RBRC, KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V ,   KC_ENT, KC_ESC ,    KC_ESC  , KC_LCTL ,  KC_K ,   KC_5 ,   KC_6 ,  KC_7  ,   KC_8 , KC_BSLS,
                                KC_BSLS, KC_LCTL, KC_SPACE,KC_LSFT, KC_LOPT,    KC_N    , KC_9    ,  KC_0 ,  KC_DEL, KC_ESC
    ),
};

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

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("       Kyria rev1.4\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYM\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("GAME\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif

#ifdef RAW_ENABLE
static void send_layer_via_hid(int layer) {
    uint8_t data[RAW_EPSIZE];
    data[0] = 1;
    data[1] = layer;
    raw_hid_send(data, sizeof(data));
    return;
}
#endif


#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM my_colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_TEAL} );
const rgblight_segment_t PROGMEM my_game_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_RED} );
const rgblight_segment_t PROGMEM my_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_MAGENTA} );
const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_GREEN} );
const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_BLUE} );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_colemak_layer,
    my_nav_layer,
    my_sym_layer,
    my_fn_layer,
    my_game_layer
);

void matrix_scan_keymap(void) {
    uint8_t mods = mod_config(get_mods());
    rgblight_set_layer_state(10, mods & MOD_MASK_SHIFT);
    rgblight_set_layer_state(11, mods & MOD_MASK_CTRL);
    rgblight_set_layer_state(12, mods & MOD_MASK_ALT);
    rgblight_set_layer_state(13, mods & MOD_MASK_GUI);
}
#endif

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_BLUE);
    // keyboard_post_init_rgb();
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = my_rgb_layers;
#else
    rgblight_sethsv_noeeprom(HSV_BLUE);
#endif
    /*debug_enable=true;*/
    /*debug_matrix=true;*/
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    for (int i = _COLEMAK_DH; i < X_PAST; i++) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
#  ifdef RAW_ENABLE
    send_layer_via_hid(state);
#  endif
#endif
    return state;
}

// #ifdef RGBLIGHT_LAYERS
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(9, led_state.caps_lock);
//     return true;
// }
// #endif

#ifdef RAW_ENABLE
void raw_hid_receive(uint8_t *data, uint8_t length) {
    // messages from host
    // add ability to set color
    raw_hid_send(data, length);
}
#endif