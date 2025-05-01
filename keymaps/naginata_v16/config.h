/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// 日本語キーボードの設定
#define KEYBOARD_JAPANESE
#define JP_KEYBOARD_MODE

// 薙刀式の設定
#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS, UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE
#define UNICODE_KEY_WINCOMPOSE KC_RALT

// タップキーの遅延設定
#define TAP_CODE_DELAY 10
