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
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PSCR,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F2,        KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS, JP_AT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LSG(KC_RGHT), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        MO(1),   MO(2),   KC_LGUI, KC_LALT,   NG_MCR0,    KC_SPC,      KC_ENT,    KC_BSPC,    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT
    ),  
    [1] = LAYOUT( /* FN */
        KC_ESC,  KC_LNG2,    KC_LNG1, JP_CIRC, JP_YEN,  KC_P7,    KC_P8,    KC_P9,    S(JP_7), S(JP_LBRC), S(JP_RBRC), S(JP_8),     S(JP_9),
        KC_LCTL, XXXXXXX,    JP_LBRC, JP_RBRC, JP_BSLS, KC_P4,    KC_P5,    KC_P6,    S(JP_4), S(JP_5),    S(JP_6),    S(JP_CIRC),  S(JP_AT),
        KC_LSFT, LGUI(JP_1), JP_SCLN, JP_COLN, S(JP_3), KC_P1,    KC_P2,    KC_P3,    S(JP_1), S(JP_2),    S(JP_3),    KC_PGUP,     S(JP_BSLS),
        MO(1),   MO(2),      KC_LGUI, KC_LALT,   NG_MCR0,    KC_P0,     KC_MINS,   KC_BSPC,    KC_DEL,     KC_HOME,    KC_PGDN,     KC_END
    ),
    [2] = LAYOUT( /* etc. */
        QK_BOOT, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F7, KC_F8, KC_F9,   KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, NGSW_LNX, NGSW_MAC, NGSW_WIN, NG_SHOS,  KC_F4, KC_F5, KC_F6,   KC_F11, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, NG_KOTI,  XXXXXXX,  NG_TAYO,  XXXXXXX,  KC_F1, KC_F2, KC_F3,   KC_F10, XXXXXXX, XXXXXXX, KC_MS_WH_UP, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT
    ),
    [3] = LAYOUT( /* NAGI */
        KC_TAB,  NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    KC_PSCR,      NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,    KC_ESC,
        KC_LCTL, NG_A,    NG_S,    NG_D,    NG_F,    NG_G,    KC_F2,        NG_H,    NG_J,    NG_K,    NG_L,    NG_SCLN, JP_AT,
        KC_LSFT, NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,    LSG(KC_RGHT), NG_N,    NG_M,    NG_COMM, NG_DOT,  KC_UP,   NG_SLSH,
        MO(1),   MO(2),   KC_LGUI, KC_LALT,   XXXXXXX,    NG_SHFT,    NG_SHFT2,   KC_BSPC,    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT
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
