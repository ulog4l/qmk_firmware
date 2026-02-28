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
    _SYMBOLS,
    _FUNCTION,
    _NAV,
};

enum{
    TD_F13,
};

tap_dance_action_t tap_dance_actions[] = {

    [TD_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F13, KC_ENT),
};



const uint16_t PROGMEM ae_combo[]  = {LGUI_T(KC_R), KC_F, COMBO_END};
const uint16_t PROGMEM oe_combo[]  = {LT(_SYMBOLS, KC_T), KC_F, COMBO_END};
const uint16_t PROGMEM ue_combo[]  = {LT(_NAV, KC_N), KC_U, COMBO_END};
const uint16_t PROGMEM ss_combo[]  = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_G, LT(_SYMBOLS, KC_T),     COMBO_END};
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
/*
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
*/


const key_override_t close_window_override = ko_make_basic(MOD_MASK_GUI, LT(_NUMBERS,KC_BSPC), LGUI(KC_C));
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_DOT);
const key_override_t gui_left_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT, LGUI(KC_LEFT));
const key_override_t gui_right_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT, LGUI(KC_RIGHT));
const key_override_t gui_down_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, LGUI(KC_DOWN));
const key_override_t gui_up_override = ko_make_basic(MOD_MASK_SHIFT, KC_UP, LGUI(KC_UP));

//TODO:
//shift + dir = super + direction
//shift + , = .
//double tap for enter?, double tap for term?
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&close_window_override,
    &dot_override,
    &gui_left_override,
    &gui_right_override,
    &gui_down_override,
    &gui_up_override
};

void leader_start_user(void){

}
void leader_end_user(void){
    if(leader_sequence_five_keys(KC_2, KC_4, KC_7, KC_3, KC_6)){
        SEND_STRING("BLOOP");
    }else if(leader_sequence_three_keys(KC_0, KC_0, KC_0)){
        tap_code16(KC_SYSTEM_SLEEP);
    }else if(leader_sequence_three_keys(KC_1, KC_1, KC_1)){
        tap_code16(KC_SYSTEM_WAKE);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_2111(

                   LT(_FUNCTION,KC_W),    KC_F,                  KC_P,                  KC_B,    KC_J,    KC_L,               KC_U,    LGUI_T(KC_Y),
        LSFT_T(KC_A),            LGUI_T(KC_R),    LT(_NUMBERS, KC_S),    LT(_SYMBOLS, KC_T),    KC_G,    KC_M,    LT(_NAV, KC_N),    KC_E,    KC_I, LSFT_T(KC_O),
        OSM(MOD_LSFT),   LCTL_T(KC_X),    KC_C,                  KC_D,                  KC_V,    KC_K,    KC_H,              KC_COMM, KC_Z,        OSM(MOD_RALT),
                                    LT(_NUMBERS,KC_SPC), LT(_NAV,KC_BSPC), OSM(MOD_RSFT), TD(TD_F13)
    ),
    [_GAMING] = LAYOUT_2111(//gaming
                    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,        KC_LALT,     KC_ESC,
        KC_LCTL,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_TAB,      KC_TRNS,     KC_F1,     KC_ENT,
        KC_LSFT,    KC_Z,     KC_C,     KC_V,     KC_B,     KC_0,        KC_ENT,      KC_TRNS,     KC_F2,     DF(_BASE),
                                    LT(_NUMBERS, KC_BSPC),     KC_SPC,   MO(_BASE2), KC_F13//for push to talk?
    ), zzz.eneleilel
    [_BASE2] = LAYOUT_2111(

                   LT(_FUNCTION,KC_W),    KC_F,                  KC_P,                  KC_B,    KC_J,    KC_L,               KC_U,    LGUI_T(KC_Y),
        LSFT_T(KC_A),            LGUI_T(KC_R),    LT(_NUMBERS, KC_S),    LT(_SYMBOLS, KC_T),    KC_G,    KC_M,    LT(_NAV, KC_N),    KC_E,    KC_I, LSFT_T(KC_O),
        OSM(MOD_LSFT),   LCTL_T(KC_X),    KC_C,                  KC_D,                  KC_V,    KC_K,    KC_H,              KC_COMM, KC_Z,        OSM(MOD_RALT),
                                    LT(_NUMBERS,KC_SPC), LT(_NAV,KC_BSPC), OSM(MOD_RSFT), TD(TD_F13)
    ),
    [_NUMBERS] = LAYOUT_2111(//NUMBERS+SYMBOLS
                     KC_MINS,     KC_TILDE,     KC_LBRC,     KC_RBRC,     KC_TRNS,         KC_7,     KC_8,     KC_9,
        KC_ASTR,     KC_EQUAL,     KC_UNDS,     KC_SLSH,     KC_BSLS,     RALT(KC_5),         KC_4,     KC_5,     KC_6,     QK_LEAD,
        OSM(MOD_LSFT),    KC_COLON,    KC_GRV,     KC_LPRN,     KC_RPRN,     KC_0,           KC_1,     KC_2,     KC_3,     KC_TRNS,
                                             KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_ENT
    ),
    [_SYMBOLS] = LAYOUT_2111(//shifted symbols
                     KC_MINS,     KC_EQUAL,     KC_TRNS,     KC_TRNS,     KC_TRNS,         KC_AMPR,       KC_ASTR,    KC_SCLN,
        KC_ASTR,     KC_TILDE,     KC_UNDS,     KC_TRNS,     KC_TRNS,     KC_TRNS,         KC_DOLLAR,     KC_PERC,    KC_CIRC,     KC_TRNS,
        KC_PLUS,      KC_COLON,     KC_GRV,     KC_TRNS,     KC_TRNS,     KC_QUESTION,           KC_EXCLAIM,    KC_AT,      KC_HASH,     KC_TRNS,
                                             KC_TRNS,     KC_TRNS,  KC_TRNS,   KC_TRNS
    ),
    [_FUNCTION] = LAYOUT_2111(//Fkeys + {},<>
                     KC_TRNS,    KC_TRNS,     KC_LCBR,     KC_RCBR,     KC_F12,         KC_F7,     KC_F8,     KC_F9,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_LABK,    KC_RABK,     KC_F11,         KC_F4,     KC_F5,     KC_F6,     KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_F10,           KC_F1,     KC_F2,     KC_F3,     QK_BOOT,
                                             KC_TRNS,     KC_TRNS,  KC_TRNS,   KC_TRNS
    ),
    [_NAV] = LAYOUT_2111(//nav for thumb ff
    MT(MOD_LALT | MOD_LSFT, KC_ESC),     KC_UP,     KC_LALT,     KC_TRNS,       KC_TRNS,      KC_7,KC_8,KC_9,
                 KC_TAB,     KC_LEFT,    KC_DOWN,     KC_RIGHT, KC_TRNS,    KC_TRNS, KC_4, KC_5, KC_6,  QK_LEAD,
                 KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_DEL,  KC_INS,         KC_0,KC_1,KC_2,KC_3,     DF(_GAMING),
                                             KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_2111(
             '*', 'L', 'L', 'L',  'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', '*', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                       '*',  '*', '*', '*'
    );
