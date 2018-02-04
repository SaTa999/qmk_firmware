/* Copyright 2017 Wunder
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
#include "xd75.h"
#include "keymap_jis2us.h"
#include "action_pseudo_lut.h"

// Layer shorthand
#define _QW 1
#define _FN 2
#define _MS 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | NUM LK | HOME   | PG UP  | 6      | 7      | 8      | 9      | 0      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | PR SCR | END    | PG DN  | Y      | U      | I      | O      | P      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | -      | =      | \      | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | [      | `      | ]      | N      | M      | ,      | .      | /      | '      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | HANKAKU| LALT   | LWIN   | FN     | MHEN   | SPACE  | SPACE  | FN     | SPACE  | SPACE  | HENKAN | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_QW] = {
        /* QWERTY */
        {KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NLCK, KC_HOME, KC_PGUP, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS},
        {KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_QUOT, KC_END, KC_PGDN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS},
        {KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_MINS, KC_EQL, KC_BSLS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_TRNS},
        {KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_GRV, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    },

    /* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | P1     | P2     | P3     | P4     | P5     |        |        |        | P6     | P7     | P8     | P9     | P0     | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | LEFT   | DOWN   | UP     | RIGHT  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RESET  | C+A+DEL|        | FN     |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_FN] = {
        /* FUNCTION */
        {KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11},
        {KC_TRNS, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_TRNS, KC_TRNS, KC_TRNS, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_F12},
        {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS},
        {KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
        {RESET, LCA(KC_DEL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    },

    /* MODSHIFT
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | NUM LK | HOME   | PG UP  | 6      | 7      | 8      | 9      | 0      | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | '      | END    | PG DN  | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | -      | +      | \      | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | [      | `      | ]      | N      | M      | ,      | .      | /      | BSPC   |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | HANKAKU| LALT   | LWIN   | FN     | MHEN   | SPACE  | SPACE  | FN     | SPACE  | SPACE  | HENKAN | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_MS] = {
        /* MODSHIFT */
        {KC_ESC, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_PSCR},
        {KC_TAB, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_DEL},
        {KC_LCTL, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_ENT},
        {OSM(MOD_LSFT), KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_FN0, KC_BSPC},
        {KC_GRV, KC_LALT, KC_LGUI, MO(_FN), KC_MHEN, KC_SPC, LT(_FN, KC_SPC), OSL(_FN), LT(_FN, KC_SPC), KC_SPC, KC_HENK, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT},
    }};

/*
 * user defined action function
 */
enum function_id
{
    PSEUDO_US_FUNCTION,
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{

    switch (id)
    {
    case PSEUDO_US_FUNCTION:
        action_pseudo_lut(record, _QW, keymap_jis2us);
        break;
    }
}

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(PSEUDO_US_FUNCTION),
};
