/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#include QMK_KEYBOARD_H

#define TGL_CG MAGIC_TOGGLE_CTL_GUI
#define RAI_ENT LT(2, KC_ENT)
#define LWR_TAB LT(1, KC_TAB)
#define ADJ_TAB LT(3, KC_TAB)
#define ESC_ALT MT(MOD_LALT, KC_ESC)
#define QUT_ALT MT(MOD_RALT,KC_QUOT)
#define DEL_ALT MT(MOD_RALT, KC_DEL)
#define ADJ_ZER LT(3, KC_0) //for number pad
#define GUI_DOT MT(MOD_LGUI, KC_DOT) // for number pad
#define SHF_NTR MT(MOD_RSFT, KC_ENT)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define PASTEM G(S(KC_V)) //paste and match
#define CUT G(KC_X)
#define WMGR_L HYPR(KC_LEFT) // Snap left in Magnet on Mac
#define WMGR_C HYPR(KC_ENT) //Snap back to original size & position on magnet
#define WMGR_R HYPR(KC_RIGHT) //Snap right on magnet

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ESC_ALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, QUT_ALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SHF_NTR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(1),         KC_SPC,      RAI_ENT, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_reviung41(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,  KC_EQL,                       KC_DLR,    KC_7,    KC_8,    KC_9, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_AMPR,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_MINS, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_CIRC, KC_BSLS, KC_LBRC, KC_RBRC, KC_TILD,                      KC_PERC,    KC_1,    KC_2,    KC_3, KC_HASH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,       KC_SPC,    ADJ_ZER, GUI_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_reviung41(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,  KC_UP, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT,XXXXXXX, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, G(KC_Z),    CUT,     COPY, PASTEM, PASTE,                         XXXXXXX, WMGR_L,  WMGR_C,  WMGR_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  MO(3),        KC_SPC,     _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RAI_ENT:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RAI_ENT:
            return TAPPING_TERM - 25;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

