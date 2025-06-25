#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

enum voyager_layers {

    KOY,
    SYMBOLS,  //1
    MOVEMENT, //2
    WM,       //3
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_CMD,
  DANCE_QUTS,
  DANCE_QUE,
  DANCE_BRC,
  DANCE_PRN,
  DANCE_CBR,
};

#define DUAL_FUNC_4 LT(4, KC_F2)
#define DUAL_FUNC_5 LT(12, KC_Q)
#define DUAL_FUNC_6 LT(14, KC_F16)

#define TO_WM    LM(WM, MOD_LALT | MOD_LCTL | MOD_LGUI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KOY] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_BSPC,        KC_K,           KC_DOT,         KC_O,           KC_COMMA,       DE_Y,                                           KC_V,           KC_G,           KC_C,           KC_L,           DE_SS,          DE_Z,           
    KC_TAB,         KC_H,           KC_A,           KC_E,           KC_I,           KC_U,                                           KC_D,           KC_T,           KC_R,           KC_N,           KC_S,           KC_F,           
    TD(DANCE_0),    KC_X,           KC_Q,           DE_AE,          DE_UE,          DE_OE,                                          KC_B,           KC_P,           KC_W,           KC_M,           KC_J,           TD(DANCE_CMD),    
                                                    KC_SPACE,       MO(1),                                          MO(2),          KC_ENTER
  ),
  [SYMBOLS] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                     LCTL(KC_BSPC),          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    LCTL(KC_BSPC),   DE_AT,          DE_ACUT,        TD(DANCE_QUTS), TD(DANCE_QUE),  DE_HASH,                                   LCTL(KC_TAB),        KC_7,           KC_8,           KC_9,           DUAL_FUNC_4,    KC_TRANSPARENT, 
    LCTL(KC_TAB),   DE_PIPE,        TD(DANCE_BRC),  TD(DANCE_PRN),  TD(DANCE_CBR),  DE_AMPR,                                        DE_MINS,        KC_4,           KC_5,           KC_6,           DUAL_FUNC_5,    KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_DLR,         DE_CIRC,        DE_EURO,        DE_PERC,        DE_TILD,                                        DUAL_FUNC_6,    KC_1,           KC_2,           KC_3,           DE_CIRC,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TO_WM,          KC_TRANSPARENT
  ),
  [MOVEMENT] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    LCTL(KC_W),     KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_LEFT,                                  DE_LCBR,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,                                 DE_RCBR,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ESCAPE,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_G,           KC_WWW_BACK,    LCTL(KC_TAB),   KC_WWW_FORWARD, CW_TOGG,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO_WM,                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [WM] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPC,        KC_K,           KC_DOT,         KC_O,           KC_COMMA,       DE_Y,                                           KC_V,           KC_G,           KC_C,           KC_L,           DE_SS,          DE_Z,           
    KC_TAB,         KC_H,           KC_A,           KC_E,           KC_I,           KC_U,                                           KC_D,           KC_T,           KC_R,           KC_N,           KC_S,           KC_F,           
    KC_LEFT_CTRL,   KC_X,           KC_Q,           DE_AE,          DE_UE,          DE_OE,                                          KC_B,           KC_P,           KC_W,           KC_M,           KC_J,           KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { KC_T, KC_R, KC_H, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_T, KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_T, KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_SPACE, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_E, KC_I, KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_E, KC_T, KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_I, KC_T, KC_R, KC_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LCTL(KC_X)),
    COMBO(combo1, LCTL(KC_C)),
    COMBO(combo2, LCTL(KC_V)),
    COMBO(combo3, OSM(MOD_LSFT)),
    COMBO(combo4, CW_TOGG),
    COMBO(combo5, LCTL(LSFT(KC_C))),
    COMBO(combo6, LCTL(LSFT(KC_V))),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // case DUAL_FUNC_0:
    //   if (record->tap.count > 0) {
    //     if (record->event.pressed) {
    //       register_code16(DE_EXLM);
    //     } else {
    //       unregister_code16(DE_EXLM);
    //     }
    //   } else {
    //     if (record->event.pressed) {
    //       register_code16(DE_QST);
    //     } else {
    //       unregister_code16(DE_QST);
    //     }  
    //   }  
    //   return false;
    // case DUAL_FUNC_1:
    //   if (record->tap.count > 0) {
    //     if (record->event.pressed) {
    //       register_code16(DE_LBRC);
    //     } else {
    //       unregister_code16(DE_LBRC);
    //     }
    //   } else {
    //     if (record->event.pressed) {
    //       register_code16(DE_RBRC);
    //     } else {
    //       unregister_code16(DE_RBRC);
    //     }  
    //   }  
    //   return false;
    // case DUAL_FUNC_2:
    //   if (record->tap.count > 0) {
    //     if (record->event.pressed) {
    //       register_code16(DE_LPRN);
    //     } else {
    //       unregister_code16(DE_LPRN);
    //     }
    //   } else {
    //     if (record->event.pressed) {
    //       register_code16(DE_RPRN);
    //     } else {
    //       unregister_code16(DE_RPRN);
    //     }  
    //   }  
    //   return false;
    // case DUAL_FUNC_3:
    //   if (record->tap.count > 0) {
    //     if (record->event.pressed) {
    //       register_code16(DE_LCBR);
    //     } else {
    //       unregister_code16(DE_LCBR);
    //     }
    //   } else {
    //     if (record->event.pressed) {
    //       register_code16(DE_RCBR);
    //     } else {
    //       unregister_code16(DE_RCBR);
    //     }  
    //   }  
    //   return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_LESS);
        } else {
          unregister_code16(DE_LESS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(DE_MORE);
        } else {
          unregister_code16(DE_MORE);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_0);
        } else {
          unregister_code16(KC_0);
        }
      } else {
        if (record->event.pressed) {
          register_code16(DE_EQL);
        } else {
          unregister_code16(DE_EQL);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_SLSH);
        } else {
          unregister_code16(DE_SLSH);
        }
      } else {
        if (record->event.pressed) {
          register_code16(DE_BSLS);
        } else {
          unregister_code16(DE_BSLS);
        }  
      }  
      return false;
    case RGB_SLD:
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

static tap dance_state[9];

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


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_ALT); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
    }
    dance_state[0].step = 0;
}

void on_dance_cmd(tap_dance_state_t *state, void *user_data);
void dance_cmd_finished(tap_dance_state_t *state, void *user_data);
void dance_cmd_reset(tap_dance_state_t *state, void *user_data);

void on_dance_cmd(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
        tap_code16(LCTL(KC_A));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_A));
    }
}

void dance_cmd_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_A)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_B)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_C)); break;
        case DOUBLE_HOLD: register_code16(LCTL(KC_D)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_A)); register_code16(LCTL(KC_A));
    }
}

void dance_cmd_reset(tap_dance_state_t *state, void *user_data) {
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

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_cmd, dance_cmd_finished, dance_cmd_reset),
        [DANCE_QUTS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_quotes, dance_quotes_finished, dance_quotes_reset),
        [DANCE_QUE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_que_excl, dance_que_excl_finished, dance_que_excl_reset),
        [DANCE_BRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_brc, dance_brc_finished, dance_brc_reset),
        [DANCE_PRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_prn, dance_prn_finished, dance_prn_reset),
        [DANCE_CBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_cbr, dance_cbr_finished, dance_cbr_reset),
};
