// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    AE,
    OE,
    UE,
    SS,
    QUOT,
    Q,

};

enum layer_names {
    _BASE,
    _GAMING,
    _BASE2,

    _NUMBERS,
    _NAVN,
    _SYMBOLS,
    _FUNCTION,
    _GAMINGNUMBERS,
    _NAVT,
    _HELPER,
};



const uint16_t PROGMEM ae_combo[]  = {LGUI_T(KC_R), KC_F, COMBO_END};
const uint16_t PROGMEM oe_combo[]  = {LT(_SYMBOLS, KC_T), KC_F, COMBO_END};
const uint16_t PROGMEM ue_combo[]  = {LT(_NAVN, KC_N), KC_U, COMBO_END};
const uint16_t PROGMEM ss_combo[]  = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_G, LT(_SYMBOLS, KC_T), COMBO_END};
const uint16_t PROGMEM ctrl_combo[] = {LCTL_T(KC_X), KC_C, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM q_combo[] = {LT(_FUNCTION,KC_W), KC_F, COMBO_END};
const uint16_t PROGMEM dot_combo[] = {KC_COMM, KC_Z, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {KC_U, LGUI_T(KC_Y), COMBO_END};

combo_t key_combos[]={
    COMBO(ae_combo, RALT(KC_Q)),
    COMBO(oe_combo, RALT(KC_P)),
    COMBO(ue_combo, RALT(KC_Y)),
    COMBO(ss_combo, RALT(KC_S)),
    COMBO(quot_combo, KC_QUOT),
    COMBO(q_combo, KC_Q),
    COMBO(dot_combo, KC_DOT),
    COMBO(ent_combo, KC_ENT),
    COMBO(ctrl_combo, OSM(MOD_LCTL)),
    COMBO(alt_combo, OSM(MOD_LALT)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};

void process_combo_event(uint16_t combo_index, bool pressed){
    switch(combo_index){
        break;
        case QUOT:
        if(pressed){
            tap_code16(KC_QUOT);
        }
        break;
        case Q:
        if(pressed){
            tap_code16(KC_Q);
        }
        break;
    }
};


const key_override_t close_window_override = ko_make_basic(MOD_MASK_GUI, LT(5,KC_BSPC), LGUI(KC_C));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&close_window_override
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(

        MT(MOD_LALT | MOD_LSFT, KC_ESC),    LT(_FUNCTION,KC_W),  KC_F,    KC_P,               KC_B, UG_VALU,   KC_J,  KC_L,               KC_U,  LGUI_T(KC_Y), KC_SCLN,
        KC_A,                               LGUI_T(KC_R),        KC_S,    LT(_SYMBOLS, KC_T), KC_G,            KC_M,  LT(_NAVN, KC_N),    KC_E,    KC_I,       KC_O,
        OSM(MOD_LSFT),                      LCTL_T(KC_X),        KC_C,    KC_D,               KC_V,            KC_K,  KC_H,               KC_COMM, KC_Z,       KC_RSFT,
                            KC_LCTL,KC_LALT,        LT(_NAVT,KC_SPC), LT(_NUMBERS,KC_BSPC), KC_BSPC, OSM(MOD_LSFT),  UG_NEXT
    ),
    [_GAMING] = LAYOUT(//gaming
        KC_ESC,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_F5,       KC_Y,     KC_ESC,     KC_TRNS,KC_TRNS,
        KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,          KC_TAB,     KC_TRNS,     KC_F1,     KC_TRNS,
        KC_LSFT,    KC_Z,     KC_C,     KC_V,     KC_B,     KC_0,           KC_ENT,     KC_TRNS,     KC_F2,     DF(_BASE),
                                        KC_TRNS,    KC_BSPC,     KC_SPC,   MO(_BASE2), KC_BSPC,KC_TRNS,KC_TAB


),
    [_BASE2] = LAYOUT(

        MT(MOD_LALT | MOD_LSFT, KC_ESC),    LT(_FUNCTION,KC_W),    KC_F,    KC_P,    KC_B, UG_VALU,   KC_J,    KC_L,    KC_U,  LGUI_T(KC_Y), KC_SCLN,
        KC_A,    LGUI_T(KC_R),    LT(_NUMBERS, KC_S),    LT(4, KC_T),    KC_G,    KC_M,  LT(_NAVN, KC_N),    KC_E,    KC_I,     KC_O,
        OSM(MOD_LSFT),    LCTL_T(KC_X),    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_Z,   KC_RSFT,
                            KC_LCTL,KC_LALT,        LT(_NAVT,KC_SPC), LT(_NAVT,KC_BSPC), KC_BSPC, OSM(MOD_LSFT),  UG_NEXT
    ),
    [_NUMBERS] = LAYOUT(//NUMBERS+SYMBOLS
         KC_TRNS,            KC_MINS,     KC_TRNS,     KC_LBRC,     KC_RBRC,     KC_TRNS,   RALT(KC_5),        KC_7,     KC_8,     KC_9,KC_TRNS,
        KC_ASTR,     KC_PLUS,     KC_TRNS,     KC_SLSH,     KC_BSLS,     KC_TRNS,         KC_4,     KC_5,     KC_6,     KC_TRNS,
        KC_EQUAL,    KC_COLON,    KC_TRNS,     KC_LPRN,     KC_RPRN,     KC_0,           KC_1,     KC_2,     KC_3,     KC_TRNS,
                                      KC_TRNS,       KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,KC_ENT,KC_TRNS
    ),
    [_NAVN] = LAYOUT(//nav for N
         KC_TRNS,            KC_ESC,     KC_UP,     KC_LALT,     KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,    KC_TAB,     KC_LALT,KC_TRNS,
        KC_TAB,     KC_LEFT,    KC_DOWN,     KC_RIGHT,   KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_BSPC,     KC_KB_VOLUME_UP,     KC_TRNS,-
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_DEL,  KC_INS,     KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_KB_VOLUME_DOWN,     DF(_GAMING),
                                       KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_SYMBOLS] = LAYOUT(//shifted symbols
            KC_TRNS,         KC_MINS,     KC_EQUAL,     KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS,         KC_AMPR,       KC_ASTR,    KC_SCLN,KC_TRNS,
        KC_ASTR,     KC_TILDE,     KC_UNDS,     KC_TRNS,     KC_TRNS,     KC_TRNS,         KC_DOLLAR,     KC_PERC,    KC_CIRC,     KC_TRNS,
        KC_GRV,      KC_COLON,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_QUESTION,           KC_EXCLAIM,    KC_AT,      KC_HASH,     KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,   KC_TRNS
    ),
    [_FUNCTION] = LAYOUT(//Fkeys + {},<>
          KC_TRNS,           KC_TRNS,    KC_TRNS,     KC_LCBR,     KC_RCBR,    KC_TRNS,   KC_F12,         KC_F7,     KC_F8,     KC_F9,KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_LABK,     KC_RABK,     KC_F11,         KC_F4,     KC_F5,     KC_F6,     KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_RPRN,     KC_F10,           KC_F1,     KC_F2,     KC_F3,     QK_BOOT,
                                  KC_TRNS,KC_TRNS,KC_TRNS,           KC_TRNS,     KC_TRNS,  KC_TRNS,   KC_TRNS
    ),
    [_GAMINGNUMBERS] = LAYOUT(//leftside keypad
        KC_TRNS,           KC_9,     KC_8,     KC_7,        KC_SLSH,   KC_EQUAL,    KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,KC_TRNS,
        KC_EQUAL,  KC_6,     LT(_HELPER,KC_5),     KC_4,  KC_DOT,   KC_MINS,        KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,
        OSM(MOD_LSFT),   KC_3,     KC_2,     KC_1,  KC_0,   KC_TRNS,          KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,
                                     KC_TRNS,KC_TRNS,KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS
    ),


    [_NAVT] = LAYOUT(//nav for thumb ff
         KC_TRNS,              KC_ESC,     KC_UP,     KC_LALT,     KC_TRNS,     KC_TRNS,         KC_TRNS,      KC_7,     KC_8,     KC_9, KC_TRNS,
        KC_TAB,     KC_LEFT,    KC_DOWN,     KC_RIGHT,   KC_TRNS ,       KC_TRNS,         KC_4,     KC_5,     KC_6,     KC_TRNS,
        MT(MOD_LALT | MOD_LSFT, KC_ESC),   KC_TRNS,    KC_TRNS,     KC_DEL,  KC_INS,         KC_0,           KC_1,     KC_2,     KC_3,     QK_BOOT,
                                             KC_TRNS,    KC_TRNS,  KC_TRNS,  MO(_GAMINGNUMBERS), KC_ENT,  KC_TRNS,  KC_TRNS
    ),
    [_HELPER] = LAYOUT(//helper for leftkeypad
         KC_TRNS,             KC_MINUS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_ASTR,    KC_PLUS, KC_TRNS, KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_EQUAL,   KC_TRNS, KC_TRNS, KC_COMMA, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L',  '*', 'L', 'L', 'L', '*', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', '*', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                       '*',  '*', '*', '*', '*', '*', '*'
    );

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [2] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [3] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [4] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
	[5] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
	[6] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
	[7] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    //                  Encoder 1					Encoder 2
};
#endif

