/* Copyright 2021 ai03
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
#include "keymap_japanese.h"
#include "naginata.h"

// 薙刀式のオン/オフに使うキーの定義
static uint16_t ng_on_keys[] = {KC_H, KC_J};  // HJで薙刀式オン
static uint16_t ng_off_keys[] = {KC_F, KC_G}; // FGで薙刀式オフ

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_7,    JP_8,    JP_9,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_4,    JP_5,    JP_6,    KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    JP_1,    JP_2,    JP_3,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LSFT, KC_LGUI, KC_LALT, KC_TAB,    KC_ESC,    KC_SPC,    KC_ENT,   KC_BSPC,   KC_DEL,  JP_0,    KC_LCTL, TO(1)
    ),  
    [1] = LAYOUT( /* FN */
        KC_LNG2, KC_LNG1, JP_CIRC, JP_YEN,  KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT,  KC_PGUP,
        KC_HOME, JP_LBRC, JP_RBRC, JP_AT,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_LEFT,       KC_DOWN,       KC_UP,       KC_RGHT,         KC_END,
        KC_PSCR, JP_COLN, JP_SCLN, JP_BSLS, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,     KC_PGDN,
        KC_LSFT, KC_LGUI, KC_LALT, KC_TAB,    TO(0),     KC_BTN2,   KC_BTN1,  KC_BSPC,         KC_DEL,        TO(2),       KC_LCTL,         TO(1)
    ),
    [2] = LAYOUT( /* etc. */
        QK_BOOT, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, NGSW_LNX, NGSW_MAC, NGSW_WIN, NG_SHOS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, NG_KOTI,  XXXXXXX,  NG_TAYO,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,    TO(0),      XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX, TO(2),   XXXXXXX, TO(1)
    ),
    [3] = LAYOUT( /* NAGI */
        NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    JP_7,    JP_8,    JP_9,    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,
        NG_A,    NG_S,    NG_D,    NG_F,    NG_G,    JP_4,    JP_5,    JP_6,    NG_H,    NG_J,    NG_K,    NG_L,    NG_SCLN,
        NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,    JP_1,    JP_2,    JP_3,    NG_N,    NG_M,    NG_COMM, NG_DOT,  NG_SLSH,
        KC_LSFT, KC_LGUI, KC_LALT, KC_TAB,    KC_ESC,   NG_SHFT,   NG_SHFT2,  KC_BSPC,   KC_DEL,  JP_0,    KC_LCTL, MO(1)
    )
};

void keyboard_post_init_user(void) {
    // 薙刀式の初期化
    set_naginata(3, ng_on_keys, ng_off_keys); // レイヤー3を薙刀式レイヤーとして使用
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // 薙刀式の処理
    if (!process_naginata(keycode, record)) {
        return false;
    }

  return true;
}
