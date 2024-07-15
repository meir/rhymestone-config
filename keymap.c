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
#include QMK_KEYBOARD_H
#include "./common/oled_helper.h"

enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,

  MAC,
  WIN,

  RGB_C_P,
};

enum {
  T_CMM,
  T_PRN,
  T_CBR,
  T_MNS,
};

tap_dance_action_t tap_dance_actions[] = {
  [T_CMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
};

#define H_ZSF MT(MOD_LSFT, KC_Z)
#define H_SSF MT(MOD_LSFT, KC_SCLN)
#define H_TSF MT(MOD_LSFT, KC_TAB)

// Lower layer mod tap
#define KC_GRSF  RSFT_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x10(
  //,-------------------------------------------------.   ,-------------------------------------------------.
      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      KC_A,     KC_S,     KC_D,     KC_F,     KC_G,         KC_H,     KC_J,     KC_K,     KC_L,     H_SSF,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      H_ZSF,    KC_X,     KC_C,     KC_V,     KC_B,         KC_N,     KC_M,    TD(T_CMM), KC_UP,    KC_ENT,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      KC_LALT,  KC_LGUI,  KC_LCTL,  LOWER,    KC_SPC,       KC_BSPC,  RAISE,    KC_LEFT,  KC_DOWN,  KC_RIGHT
  //`-------------------------------------------------'   `-------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_ortho_4x10(
  //,-------------------------------------------------.   ,-------------------------------------------------.
      KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      KC_ESC,   KC_F1,    KC_F2,    KC_F3,    XXXXXXX,      KC_MINS,  KC_EQUAL, KC_LBRC,  KC_RBRC,  KC_QUOT,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      H_TSF,    KC_F4,    KC_F5,    KC_F6,    XXXXXXX,      KC_DEL,   XXXXXXX,  XXXXXXX,  KC_SLSH,  _______,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______
  //`-------------------------------------------------'   `-------------------------------------------------'
  ),

  [_RAISE] = LAYOUT_ortho_4x10(
  //,-------------------------------------------------.   ,-------------------------------------------------.
      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      KC_GRV,   KC_F7,    KC_F8,    KC_F9,    _______,      _______,  _______,  _______,  _______,  KC_BSLS,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      H_TSF,    KC_F10,   KC_F11,   KC_F12,   _______,      _______,  _______,  _______,  _______,  _______,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______
  //`-------------------------------------------------'   `-------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_ortho_4x10(
  //,-------------------------------------------------.   ,-------------------------------------------------.
      QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      KC_BTN4,  KC_BTN3,  KC_BTN5,  KC_WH_U,  XXXXXXX,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      RGB_TOG,  KC_ACL0,  KC_ACL1,  KC_ACL2,  RGB_C_P,      KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_D,  XXXXXXX,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  _______,
  //|---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------|
      _______,    MAC,      WIN,      _______,  _______,      _______,  _______,  _______,  _______,  _______
  //`-------------------------------------------------'   `-------------------------------------------------'
  ),
};

const uint8_t led_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_ortho_4x10(
    10,  11,  12,  13,   0,    20,  33,  32,  31,  30,
     9,  18,  19,  14,   1,    21,  34,  39,  38,  29,
     8,  17,  16,  15,   2,    22,  35,  36,  37,  28,
     7,   6,   5,   4,   3,    23,  24,  25,  26,  27
);

typedef union {
    uint32_t raw;
    struct {
        bool is_mac: 1;
    };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
}

#ifdef OLED_ENABLE
#include <stdio.h>
#include <string.h>

#ifdef BONGO_ENABLE
#include "bongo.h"
#endif

#define LAYER_DISPLAY_MAX 7
const char LAYER_DISPLAY_NAME [LAYER_DISPLAY_MAX][7] = {
  [_BASE]  =        "Base",
  [_LOWER] =        "Lower",
  [_RAISE] =        "Raise",
  [_ADJUST] =       "Adjust",
};

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {
  snprintf(
    layer_status_buf,
    sizeof(layer_status_buf) - 1,
    "OS:%s Layer:%s\n",
    user_config.is_mac ? "mac" : "win",
    LAYER_DISPLAY_NAME[biton32(layer_state)]
  );
}

static inline void render_keymap_status(void) {
  oled_write(layer_status_buf, false);
}

static char rgb_buf[24] = "RGB state ready.\n";

void update_led_status(void) {
    bool is_enabled = rgb_matrix_is_enabled();
    uint8_t mode = rgb_matrix_get_mode();
    uint8_t hue = rgb_matrix_get_hue();
    uint8_t sat = rgb_matrix_get_sat();
    uint8_t val = rgb_matrix_get_val();
    snprintf(rgb_buf,
        sizeof(rgb_buf) - 1,
        "%c:%2d hsv:%2d %2d %2d\n",
        is_enabled ? '*' : '.',
        mode,
        hue,
        sat,
        val
    );
}

void render_led_status(void) {
  oled_write(rgb_buf, false);
}

static inline void render_status(void) {
  update_led_status();
  render_led_status();
  render_keymap_status();
  RENDER_LOCK_STATUS();
  RENDER_KEY_STATUS();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    #ifdef BONGO_ENABLE
      draw_bongo(true);
    #else
      render_logo();
    #endif
  }
  return false;
}

#else

#define UPDATE_KEYMAP_STATUS()

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  bool result = false;
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }

      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }

      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      break;

    #ifdef RGBLIGHT_ENABLE
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
          }
        break;
    #endif
    case MAC:
        if (record->event.pressed) {
            user_config.is_mac = true;
            eeconfig_update_user(user_config.raw);
        }
        break;
    case WIN:
        if (record->event.pressed) {
            user_config.is_mac = false;
            eeconfig_update_user(user_config.raw);
        }
        break;
    case RGB_C_P:
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_portals);
        break;
    default:
      result = true;
      break;
  }

  update_keymap_status();
  return result;
}

uint8_t mod_config(uint8_t mod) {
    if(user_config.is_mac) {
        if ((mod & MOD_RALT) == MOD_LALT) {
            mod &= ~MOD_LALT;
            mod |= MOD_LCTL;
        } else if ((mod & MOD_RGUI) == MOD_LGUI) {
            mod &= ~MOD_LGUI;
            mod |= MOD_LALT;
        }else if ((mod & MOD_RCTL) == MOD_LCTL) {
            mod &= ~MOD_LCTL;
            mod |= MOD_LGUI;
        }
    }
    return mod;
}

uint16_t keycode_config(uint16_t keycode) {
    if(user_config.is_mac) {
        switch(keycode) {
            case KC_LALT:
                return KC_LCTL;
            case KC_LGUI:
                return KC_LALT;
            case KC_LCTL:
                return KC_LGUI;
        }
    }
    return keycode;
}

