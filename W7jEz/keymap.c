#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  DRAG_SCROLL,
  TOGAMING,
};

enum moonlander_layers {
    KOY,
    SYMBOLS,  //1
    MOVEMENT, //2
    MODS,       //3
    GAMING,   //4
    NAVIGATOR,//5
};


#undef KC_HASH
#undef KC_AT
#undef KC_DQUO
#undef KC_EXLM
#undef KC_LBRC
#undef KC_LPRN
#undef KC_LCBR
#undef KC_SLASH
#undef KC_EQUAL

#define DE_UE KC_LBRC

#define KC_HASH TOGAMING
#define KC_AT TD(DANCE_CMD)
#define KC_DQUO TD(DANCE_QUTS)
#define KC_EXLM TD(DANCE_QUE)
#define KC_LBRC TD(DANCE_BRC)
#define KC_LPRN TD(DANCE_PRN)
#define KC_LCBR TD(DANCE_CBR)
#define KC_SLASH TD(DANCE_SLASH)
#define KC_EQUAL TD(DANCE_EQ)


enum tap_dance_codes {
  DANCE_CMD,
  DANCE_QUTS,
  DANCE_QUE,
  DANCE_BRC,
  DANCE_PRN,
  DANCE_CBR,
  DANCE_SLASH,
  DANCE_EQ,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KOY] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, 
    KC_BSPC,        KC_K,           KC_DOT,         KC_O,           KC_COMMA,       DE_Y,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_G,           KC_C,           KC_L,           DE_SS,          DE_Z,           
    KC_TAB,         MT(MOD_LGUI, KC_H),MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_E),MEH_T(KC_I),    ALL_T(KC_U),    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, ALL_T(KC_D),    MEH_T(KC_T),    MT(MOD_RCTL, KC_R),MT(MOD_RALT, KC_N),MT(MOD_RGUI, KC_S),KC_F,           
    KC_RABK,        KC_X,           KC_Q,           DE_AE,          DE_UE,          DE_OE,                                          KC_B,           KC_P,           KC_W,           KC_M,           KC_J,           KC_LABK,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HASH,                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       MO(1),          KC_TRANSPARENT,                 KC_TRANSPARENT, MO(2),          MT(MOD_LSFT, KC_ENTER)
  ),
  [SYMBOLS] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LCTL(KC_BSPC),  DE_AT,          DE_ACUT,        KC_DQUO,        KC_EXLM,        DE_HASH,        KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_PLUS,        KC_7,           KC_8,           KC_9,           DE_LESS,        KC_TRANSPARENT, 
    LCTL(KC_TAB),   DE_PIPE,        KC_LBRC,        KC_LPRN,        KC_LCBR,        DE_AMPR,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, DE_MINS,        KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT, 
    LCTL(KC_DELETE),DE_DLR,         DE_CIRC,        DE_EURO,        DE_PERC,        DE_TILD,                                        KC_SLASH,       KC_1,           KC_2,           KC_3,           CW_TOGG,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 TOGGLE_LAYER_COLOR,KC_TRANSPARENT, RGB_SPI,        RGB_SPD,        RGB_SAI,        RGB_SAD,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, MO(3),          LSFT(KC_ENTER)
  ),
  [MOVEMENT] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_SYSTEM_SLEEP,KC_SYSTEM_WAKE, KC_SYSTEM_POWER,QK_BOOT,        
    LCTL(KC_W),     KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_LEFT,  KC_TRANSPARENT,                                 KC_TRANSPARENT, DE_LCBR,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_ESCAPE,      KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, DE_RCBR,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ESCAPE,      
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_LEFT_CTRL,   KC_LEFT_SHIFT,                                  KC_G,           KC_WWW_BACK,    KC_WWW_REFRESH, KC_WWW_FORWARD, CW_TOGG,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SLD,                                                                                                        RGB_MODE_FORWARD,KC_TRANSPARENT, RGB_VAI,        RGB_VAD,        RGB_HUI,        RGB_HUD,        
    CW_TOGG,        MO(3),          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MODS] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, IT_RABK,        KC_TRANSPARENT, IT_LABK,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_MEH),   OSM(MOD_HYPR),  CW_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [GAMING] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_V,           KC_G,           KC_C,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NAVIGATOR] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_BTN1,     DRAG_SCROLL,    KC_MS_BTN2,     KC_MS_WH_RIGHT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', '*', '*', 'R', 'R', 'R', 'R', 'R',
                 '*', '*', '*', '*', '*', '*'
);




extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

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
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
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
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;
void pointing_device_init_user(void) {
  set_auto_mouse_enable(true);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
  // Treat all keys as mouse keys when in the automouse layer so that any key set resets the timeout without leaving the layer.
  if (!layer_state_is(AUTO_MOUSE_TARGET_LAYER)){
    // When depressing a mouse key with a LT key at the same time, the mouse key tracker is not decremented.
    // This is a workaround to fix that
    if (IS_MOUSE_KEYCODE(keycode) && !record->event.pressed) {
      return true;
    }
    return false;
  }
  else {
    return true;
  }
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case DRAG_SCROLL:
      if (record->event.pressed) {
        set_scrolling = true;
      } else {
        set_scrolling = false;
      }
      return false;

    case TOGAMING:
       if (record->event.pressed) {
         if (layer_state_is(GAMING)) {
           layer_off(GAMING);
           autoshift_enable();
           // combo_enable();
         } else {
           layer_off(MOVEMENT);
           layer_off(SYMBOLS);
           layer_off(MODS);
           layer_on(GAMING);
           autoshift_disable();
           // combo_disable();
         }
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

static tap dance_state[8];

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

void on_dance_quotes(tap_dance_state_t *state, void *user_data);
void dance_quotes_finished(tap_dance_state_t *state, void *user_data);
void dance_quotes_reset(tap_dance_state_t *state, void *user_data);

void on_dance_quotes(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_2));
    }
}

void dance_quotes_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: register_code16(LSFT(DE_HASH)); break;
        case DOUBLE_TAP: tap_code16(LSFT(KC_2)); tap_code16(LSFT(KC_2)); tap_code16(KC_LEFT); break;
        case DOUBLE_HOLD: tap_code16(LSFT(DE_HASH)); tap_code16(LSFT(DE_HASH)); tap_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_2)); register_code16(LSFT(KC_2));
    }
}

void dance_quotes_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(DE_HASH)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case DOUBLE_HOLD: unregister_code16(LSFT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
    }
    dance_state[1].step = 0;
}

void on_dance_que_excl(tap_dance_state_t *state, void *user_data);
void dance_que_excl_finished(tap_dance_state_t *state, void *user_data);
void dance_que_excl_reset(tap_dance_state_t *state, void *user_data);

void on_dance_que_excl(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_1));
        tap_code16(LSFT(KC_1));
        tap_code16(LSFT(KC_1));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_1));
    }
}

void dance_que_excl_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_1)); break;
        case SINGLE_HOLD: register_code16(LSFT(DE_SS)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_1)); register_code16(LSFT(KC_1)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_1)); register_code16(LSFT(KC_1));
    }
}

void dance_que_excl_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_1)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(DE_SS)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_1)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_1)); break;
    }
    dance_state[2].step = 0;
}

void on_dance_brc(tap_dance_state_t *state, void *user_data);
void dance_brc_finished(tap_dance_state_t *state, void *user_data);
void dance_brc_reset(tap_dance_state_t *state, void *user_data);

void on_dance_brc(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LBRC);
        tap_code16(DE_LBRC);
        tap_code16(DE_LBRC);
    }
    if(state->count > 3) {
        tap_code16(DE_LBRC);
    }
}

void dance_brc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(DE_LBRC); break;
        case SINGLE_HOLD: register_code16(DE_RBRC); break;
        case DOUBLE_HOLD: tap_code16(DE_LBRC); tap_code16(DE_RBRC); break;
        case DOUBLE_TAP: tap_code16(DE_LBRC); tap_code16(DE_RBRC); tap_code16(KC_LEFT); break;
    }
}

void dance_brc_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(DE_LBRC); break;
        case SINGLE_HOLD: unregister_code16(DE_RBRC); break;
        case DOUBLE_TAP: unregister_code16(DE_LBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LBRC); break;
    }
    dance_state[3].step = 0;
}

void on_dance_prn(tap_dance_state_t *state, void *user_data);
void dance_prn_finished(tap_dance_state_t *state, void *user_data);
void dance_prn_reset(tap_dance_state_t *state, void *user_data);

void on_dance_prn(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LPRN);
        tap_code16(DE_LPRN);
        tap_code16(DE_LPRN);
    }
    if(state->count > 3) {
        tap_code16(DE_LPRN);
    }
}

void dance_prn_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(DE_LPRN); break;
        case SINGLE_HOLD: register_code16(DE_RPRN); break;
        case DOUBLE_HOLD: tap_code16(DE_LPRN); tap_code16(DE_RPRN); break;
        case DOUBLE_TAP: tap_code16(DE_LPRN); tap_code16(DE_RPRN); tap_code16(KC_LEFT); break;
    }
}

void dance_prn_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(DE_LPRN); break;
        case SINGLE_HOLD: unregister_code16(DE_RPRN); break;
        case DOUBLE_TAP: unregister_code16(DE_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LPRN); break;
    }
    dance_state[4].step = 0;
}

void on_dance_cbr(tap_dance_state_t *state, void *user_data);
void dance_cbr_finished(tap_dance_state_t *state, void *user_data);
void dance_cbr_reset(tap_dance_state_t *state, void *user_data);

void on_dance_cbr(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
        tap_code16(DE_LCBR);
    }
    if(state->count > 3) {
        tap_code16(DE_LCBR);
    }
}

void dance_cbr_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(DE_LCBR); break;
        case SINGLE_HOLD: register_code16(DE_RCBR); break;
        case DOUBLE_HOLD: tap_code16(DE_LCBR); tap_code16(DE_RCBR); break;
        case DOUBLE_TAP: tap_code16(DE_LCBR); tap_code16(DE_RCBR); tap_code16(KC_LEFT); break;
    }
}

void dance_cbr_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(DE_LCBR); break;
        case SINGLE_HOLD: unregister_code16(DE_RCBR); break;
        case DOUBLE_TAP: unregister_code16(DE_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_LCBR); break;
    }
    dance_state[5].step = 0;
}

void on_dance_eq(tap_dance_state_t *state, void *user_data);
void dance_eq_finished(tap_dance_state_t *state, void *user_data);
void dance_eq_reset(tap_dance_state_t *state, void *user_data);

void on_dance_eq(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_7));
        tap_code16(LSFT(KC_7));
        tap_code16(LSFT(KC_7));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_7));
    }
}

void dance_eq_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_0); break;
        case SINGLE_HOLD: register_code16(DE_EQL); break;
        case DOUBLE_TAP: register_code16(KC_0); register_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_0); register_code16(KC_0);
    }
}

void dance_eq_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_0); break;
        case SINGLE_HOLD: unregister_code16(DE_EQL); break;
        case DOUBLE_TAP: unregister_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
    }
    dance_state[6].step = 0;
}

void on_dance_slash(tap_dance_state_t *state, void *user_data);
void dance_slash_finished(tap_dance_state_t *state, void *user_data);
void dance_slash_reset(tap_dance_state_t *state, void *user_data);

void on_dance_slash(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if(state->count > 3) {
        tap_code16(KC_0);
    }
}

void dance_slash_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_7)); break;
        case SINGLE_HOLD: register_code16(RALT(DE_SS)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_7)); register_code16(LSFT(KC_7)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_7)); register_code16(LSFT(KC_7));
    }
}

void dance_slash_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_7)); break;
        case SINGLE_HOLD: unregister_code16(RALT(DE_SS)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_7)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_7)); break;
    }
    dance_state[7].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_QUTS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_quotes, dance_quotes_finished, dance_quotes_reset),
        [DANCE_QUE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_que_excl, dance_que_excl_finished, dance_que_excl_reset),
        [DANCE_BRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_brc, dance_brc_finished, dance_brc_reset),
        [DANCE_PRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_prn, dance_prn_finished, dance_prn_reset),
        [DANCE_CBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_cbr, dance_cbr_finished, dance_cbr_reset),
        [DANCE_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_slash, dance_slash_finished, dance_slash_reset),
        [DANCE_EQ] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_eq, dance_eq_finished, dance_eq_reset),
};



bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_ENTER):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}


bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DE_ACUT:
        case DE_PLUS:
        case DE_MINS:
        case DE_LESS:
            return true;
    }
    return false;
}

#undef KC_HASH
#undef KC_AT
#undef KC_DQUO
#undef KC_EXLM
#undef KC_LBRC
#undef KC_LPRN
#undef KC_LCBR
#undef KC_SLASH
#undef KC_EQUAL


