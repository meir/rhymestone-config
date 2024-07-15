/* Copyright 2020 marksard
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

#pragma once

#define OLED_FONT_H "keyboards/marksard/rhymestone/common/glcdfont.c"

#define I2C_DRIVER I2CD0

#define SEQUENCER_STEPS 60
#define SEQUENCER_TRACKS 6

#define SPLIT_KEYBOARD_MIRROR
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE

#define BONGO_ENABLE

#define OLED_TIMEOUT 0

#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_portals

#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL

#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#undef RGB_MATRIX_HUE_STEP
#undef RGB_MATRIX_SAT_STEP
#undef RGB_MATRIX_VAL_STEP
#undef RGB_MATRIX_SPD_STEP

#define RGB_MATRIX_SPLIT { 20, 20 }
// #define RGBLIGHT_LED_MAP { 10, 11, 12, 13, 0, 9, 18, 19, 14, 1, 8, 17, 16, 15, 2, 7, 6, 5, 4, 3, 30, 31, 32, 33, 20, 29, 38, 39, 34, 21, 28, 37, 36, 35, 22, 27, 26, 25, 24, 23 }

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#define RGB_MATRIX_HUE_STEP 5
#define RGB_MATRIX_SAT_STEP 5
#define RGB_MATRIX_VAL_STEP 5
#define RGB_MATRIX_SPD_STEP 5


#define MK_C_OFFSET_0 1
#define MK_C_INTERVAL_0 512

#define MK_C_OFFSET_1 4
#define MK_C_INTERVAL_1 16

#define MK_C_OFFSET_2 64
#define MK_C_INTERVAL_2 1
