#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, 
    KC_BSPC,        KC_K,           KC_DOT,         KC_O,           KC_COMMA,       DE_Y,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_G,           KC_C,           KC_L,           DE_SS,          DE_Z,           
    KC_TAB,         KC_H,           KC_A,           KC_E,           KC_I,           KC_U,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_D,           KC_T,           KC_R,           KC_N,           KC_S,           KC_F,           
    KC_LEFT_CTRL,   KC_X,           KC_Q,           DE_AE,          DE_UE,          DE_OE,                                          KC_B,           KC_P,           KC_W,           KC_M,           KC_J,           TD(DANCE_0),    
    KC_LEFT_ALT,    KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(4),                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       MO(1),          KC_TRANSPARENT,                 KC_TRANSPARENT, MO(2),          KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LCTL(KC_BSPC),  DE_AT,          DE_ACUT,        TD(DANCE_1),    TD(DANCE_2),    DE_HASH,        KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_PLUS,        KC_7,           KC_8,           KC_9,           DE_LESS,        KC_TRANSPARENT, 
    LCTL(KC_TAB),   DE_PIPE,        TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    DE_AMPR,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, DE_MINS,        KC_4,           KC_5,           KC_6,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_DLR,         DE_RING,        DE_EURO,        DE_PERC,        DE_TILD,                                        TD(DANCE_6),    KC_1,           KC_2,           KC_3,           CW_TOGG,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TOGGLE_LAYER_COLOR,KC_TRANSPARENT, RGB_SPI,        RGB_SPD,        RGB_SAI,        RGB_SAD,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, MO(3),          KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_SYSTEM_SLEEP,KC_SYSTEM_WAKE, KC_SYSTEM_POWER,QK_BOOT,        
    LCTL(KC_W),     KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_LEFT,  KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_LCBR,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, DE_RCBR,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ESCAPE,      
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_MS_BTN4,     KC_MS_BTN5,                                     KC_G,           KC_WWW_BACK,    KC_WWW_REFRESH, KC_WWW_FORWARD, CW_TOGG,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SLD,                                                                                                        RGB_MODE_FORWARD,KC_TRANSPARENT, RGB_VAI,        RGB_VAD,        RGB_HUI,        RGB_HUD,        
    KC_LEFT_SHIFT,  MO(3),          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPC,        KC_K,           KC_DOT,         KC_O,           KC_COMMA,       DE_Y,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_G,           KC_C,           KC_L,           DE_SS,          DE_Z,           
    KC_TAB,         KC_H,           KC_A,           KC_E,           KC_I,           KC_U,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_D,           KC_T,           KC_R,           KC_N,           KC_S,           KC_F,           
    KC_LEFT_CTRL,   KC_X,           KC_Q,           DE_AE,          DE_UE,          DE_OE,                                          KC_B,           KC_P,           KC_W,           KC_M,           KC_J,           KC_TRANSPARENT, 
    KC_LEFT_ALT,    KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MT(MOD_LCTL, KC_TAB),KC_TRANSPARENT, KC_TRANSPARENT, KC_V,           KC_G,           KC_C,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { KC_T, KC_R, KC_H, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_T, KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_T, KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_SPACE, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_R, KC_T, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_T, KC_R, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_T, KC_R, KC_N, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LCTL(KC_X)),
    COMBO(combo1, LCTL(KC_C)),
    COMBO(combo2, LCTL(KC_V)),
    COMBO(combo3, KC_LEFT_SHIFT),
    COMBO(combo4, CW_TOGG),
    COMBO(combo5, LCTL(LSFT(KC_C))),
    COMBO(combo6, LCTL(LSFT(KC_V))),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[7];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_A));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_B)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_C)); break;
        case DOUBLE_HOLD: register_code16(LCTL(KC_D)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_A)); register_code16(LCTL(KC_A));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_B)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case DOUBLE_HOLD: unregister_code16(LCTL(KC_D)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_A)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_2));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_2)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_2)); break;
        case DOUBLE_HOLD: register_code16(LSFT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_2)); register_code16(LSFT(KC_2));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_2)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case DOUBLE_HOLD: unregister_code16(LSFT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_1));
        tap_code16(LSFT(KC_1));
        tap_code16(LSFT(KC_1));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_1));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_1)); break;
        case SINGLE_HOLD: register_code16(LSFT(DE_SS)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_1)); register_code16(LSFT(KC_1)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_1)); register_code16(LSFT(KC_1));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_1)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(DE_SS)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_1)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_1)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LBRC);
        tap_code16(DE_LBRC);
        tap_code16(DE_LBRC);
    }
    if(state->count > 3) {
        tap_code16(DE_LBRC);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(DE_LBRC); break;
        case SINGLE_HOLD: register_code16(DE_RBRC); break;
        case DOUBLE_TAP: register_code16(DE_LBRC); register_code16(DE_LBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_LBRC); register_code16(DE_LBRC);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(DE_LBRC); break;
        case SINGLE_HOLD: unregister_code16(DE_RBRC); break;
        case DOUBLE_TAP: unregister_code16(DE_LBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LBRC); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LPRN);
        tap_code16(DE_LPRN);
        tap_code16(DE_LPRN);
    }
    if(state->count > 3) {
        tap_code16(DE_LPRN);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(DE_LPRN); break;
        case SINGLE_HOLD: register_code16(DE_RPRN); break;
        case DOUBLE_TAP: register_code16(DE_LPRN); register_code16(DE_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_LPRN); register_code16(DE_LPRN);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(DE_LPRN); break;
        case SINGLE_HOLD: unregister_code16(DE_RPRN); break;
        case DOUBLE_TAP: unregister_code16(DE_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LPRN); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
    }
    if(state->count > 3) {
        tap_code16(DE_LCBR);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(DE_LCBR); break;
        case SINGLE_HOLD: register_code16(DE_RCBR); break;
        case DOUBLE_TAP: register_code16(DE_LCBR); register_code16(DE_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_LCBR); register_code16(DE_LCBR);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(DE_LCBR); break;
        case SINGLE_HOLD: unregister_code16(DE_RCBR); break;
        case DOUBLE_TAP: unregister_code16(DE_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LCBR); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_7));
        tap_code16(LSFT(KC_7));
        tap_code16(LSFT(KC_7));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_7));
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_7)); break;
        case SINGLE_HOLD: register_code16(RALT(DE_SS)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_7)); register_code16(LSFT(KC_7)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_7)); register_code16(LSFT(KC_7));
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_7)); break;
        case SINGLE_HOLD: unregister_code16(RALT(DE_SS)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_7)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_7)); break;
    }
    dance_state[6].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
};
