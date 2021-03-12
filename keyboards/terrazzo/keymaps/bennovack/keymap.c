/* Copyright 2020 ademey "MsMustard"
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

/* Ortho layout with 1 2u spacebar
 * make terrazzo:othro_mit
 */
#include QMK_KEYBOARD_H

enum layers {
	  _QWERTY,
	  _RAISE,
	  _LOWER,
	  _NAV,
	  _FN
};

#define OPTESC OPT_T(KC_ESC)
#define SHFTENT RSFT_T(KC_ENT)
#define SHFTUND RSFT_T(KC_UNDS)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_ortho_mit(
	  	  KC_MPLY, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,       KC_I,     KC_O,    KC_P,    KC_BSPC,
	      KC_MNXT,   OPTESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,       KC_K,     KC_L,    KC_SCLN, KC_QUOT,
	      XXXXXXX,  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,       KC_COMM,  KC_DOT,  KC_SLSH, SHFTENT,
	      KC_F15,           KC_LCTL,  KC_LALT, KC_LGUI, MO(_LOWER),   KC_SPC,     MO(_RAISE), KC_RGUI, MO(_FN), KC_DEL
    ),

    [_RAISE] = LAYOUT_ortho_mit(
         _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, A(KC_LEFT), KC_UP, A(KC_RIGHT), KC_PGUP, _______,
	      TZ_NXT, _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,_______,
	      TZ_OFF, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HYPR(KC_LEFT), HYPR(KC_ENT), HYPR(KC_RIGHT),  _______, _______,
	      _______,          _______, _______, _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_LOWER] = LAYOUT_ortho_mit(
           _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
	      _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_MINS,
	      _______, _______, XXXXXXX, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX, KC_EQL, KC_PLUS, KC_DOT, KC_TILDE, KC_UNDS,
	      _______,          _______, _______, _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_ortho_mit(
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_HOME, KC_UP,   KC_END,   KC_PGUP, _______,
	      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,_______,
	      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,
	      _______,          _______, _______, _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_FN] = LAYOUT_ortho_mit(
	  	  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
	  	  _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  _______, _______,
	  	  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, CG_TOGG,
	  	  _______,          RESET,   _______, _______, _______,     _______,      _______, _______, _______, _______
    )
};


void encoder_update_user(uint8_t index, bool clockwise) {
    terrazzo_scroll_pixel(clockwise);
    switch(get_highest_layer(layer_state)) {
        case _NAV:
            /* Page up/down when on nav layer */
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
            break;
        default:

            switch (index) {
                case 0:
                    clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
                    break;
                case 1:
                    //sonos shortcuts
                    clockwise ? tap_code16(G(KC_F18)) : tap_code16(G(KC_F19));
                    break;
                case 2:
                    clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);

                    break;
            }
    }
}
