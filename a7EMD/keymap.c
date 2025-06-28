#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_131_255_255,
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

#define DUAL_FUNC_7 LT(2, KC_R)
#define DUAL_FUNC_8 LT(14, KC_F23)
#define DUAL_FUNC_9 LT(3, KC_L)
#define DUAL_FUNC_10 LT(2, KC_K)
#define DUAL_FUNC_11 LT(1, KC_F)
#define DUAL_FUNC_12 LT(13, KC_F10)
#define DUAL_FUNC_13 LT(2, KC_V)
#define DUAL_FUNC_14 LT(11, KC_F3)
#define DUAL_FUNC_15 LT(7, KC_F22)
#define DUAL_FUNC_16 LT(14, KC_N)
#define DUAL_FUNC_17 LT(3, KC_R)
#define DUAL_FUNC_18 LT(11, KC_S)
#define DUAL_FUNC_19 LT(10, KC_F3)
#define DUAL_FUNC_20 LT(3, KC_E)
#define DUAL_FUNC_21 LT(12, KC_F4)
#define DUAL_FUNC_22 LT(14, KC_W)
#define DUAL_FUNC_23 LT(10, KC_W)
#define DUAL_FUNC_24 LT(2, KC_5)
#define DUAL_FUNC_25 LT(1, KC_P)
#define DUAL_FUNC_26 LT(4, KC_U)
#define DUAL_FUNC_27 LT(12, KC_F21)
#define DUAL_FUNC_28 LT(3, KC_F12)
#define DUAL_FUNC_29 LT(7, KC_5)
#define DUAL_FUNC_30 LT(12, KC_A)
#define DUAL_FUNC_31 LT(12, KC_F14)
#define DUAL_FUNC_32 LT(10, KC_F5)
#define DUAL_FUNC_33 LT(9, KC_F14)
#define DUAL_FUNC_34 LT(13, KC_B)
#define DUAL_FUNC_35 LT(8, KC_D)
#define DUAL_FUNC_36 LT(13, KC_8)
#define DUAL_FUNC_37 LT(9, KC_F12)
#define DUAL_FUNC_38 LT(8, KC_F24)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [KOY] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_BSPC,        KC_K,           KC_DOT,         KC_O,           KC_COMMA,       DE_Y,                                           KC_V,           KC_G,           KC_C,           KC_L,           DE_SS,          DE_Z,           
    KC_TAB,         KC_H,           KC_A,           KC_E,           KC_I,           KC_U,                                           KC_D,           KC_T,           KC_R,           KC_N,           KC_S,           KC_F,           
    KC_LEFT_CTRL,   KC_X,           KC_Q,           DE_AE,          DE_UE,          DE_OE,                                          KC_B,           KC_P,           KC_W,           KC_M,           KC_J,           TD(DANCE_CMD),    
                                                                    KC_SPACE,       MO(1),                                          MO(2),          KC_ENTER
  ),
  [SYMBOLS] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    LCTL(KC_BSPC),  DE_AT,          DE_ACUT,        TD(DANCE_QUTS), TD(DANCE_QUE),  DE_HASH,                                        DE_PLUS,        KC_7,           KC_8,           KC_9,           DUAL_FUNC_4,    KC_TRANSPARENT, 
    LCTL(KC_TAB),   DE_PIPE,        TD(DANCE_BRC),  TD(DANCE_PRN),  TD(DANCE_CBR),  DE_AMPR,                                        DE_MINS,        KC_4,           KC_5,           KC_6,           DUAL_FUNC_5,    KC_TRANSPARENT, 
    KC_LEFT_ALT,    DE_DLR,         DE_CIRC,        DE_EURO,        DE_PERC,        DE_TILD,                                        DUAL_FUNC_6,    KC_1,           KC_2,           KC_3,           DE_CIRC,        KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 TO_WM,          KC_TRANSPARENT
  ),
  [MOVEMENT] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,    RGB_VAD,        RGB_VAI,                                        RGB_HUI,        RGB_HUD,        RGB_SAI,        RGB_SAD,        HSV_131_255_255,QK_BOOT,        
    LCTL(KC_W),     KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MS_WH_LEFT,                                  DE_LCBR,        KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,                                 DE_RCBR,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_ESCAPE,      
    KC_LEFT_GUI,    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_MS_BTN4,   KC_MS_BTN5,                                     KC_G,           KC_WWW_BACK,    LCTL(KC_TAB),   KC_WWW_FORWARD, CW_TOGG,        KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, TO_WM,                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [WM] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_BSPC,        DUAL_FUNC_7,    DUAL_FUNC_8,    DUAL_FUNC_9,    DUAL_FUNC_10,   DUAL_FUNC_11,                                   DUAL_FUNC_22,   DUAL_FUNC_23,   DUAL_FUNC_24,   DUAL_FUNC_25,   DUAL_FUNC_26,   DUAL_FUNC_27,   
    KC_TAB,         DUAL_FUNC_12,   DUAL_FUNC_13,   DUAL_FUNC_14,   DUAL_FUNC_15,   DUAL_FUNC_16,                                   DUAL_FUNC_28,   DUAL_FUNC_29,   DUAL_FUNC_30,   DUAL_FUNC_31,   DUAL_FUNC_32,   DUAL_FUNC_33,   
    KC_LEFT_CTRL,   DUAL_FUNC_17,   DUAL_FUNC_18,   DUAL_FUNC_19,   DUAL_FUNC_20,   DUAL_FUNC_21,                                   DUAL_FUNC_34,   DUAL_FUNC_35,   DUAL_FUNC_36,   DUAL_FUNC_37,   DUAL_FUNC_38,   KC_TRANSPARENT, 
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
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_K);
        } else {
          unregister_code16(KC_K);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_K));
        } else {
          unregister_code16(LSFT(KC_K));
        }  
      }  
      return false;
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DOT);
        } else {
          unregister_code16(KC_DOT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_DOT));
        } else {
          unregister_code16(LSFT(KC_DOT));
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_O);
        } else {
          unregister_code16(KC_O);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_O));
        } else {
          unregister_code16(LSFT(KC_O));
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COMMA);
        } else {
          unregister_code16(KC_COMMA);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_COMMA));
        } else {
          unregister_code16(LSFT(KC_COMMA));
        }  
      }  
      return false;
    case DUAL_FUNC_11:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_Y);
        } else {
          unregister_code16(DE_Y);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(DE_Y));
        } else {
          unregister_code16(LSFT(DE_Y));
        }  
      }  
      return false;
    case DUAL_FUNC_12:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_H);
        } else {
          unregister_code16(KC_H);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_H));
        } else {
          unregister_code16(LSFT(KC_H));
        }  
      }  
      return false;
    case DUAL_FUNC_13:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_A);
        } else {
          unregister_code16(KC_A);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_A));
        } else {
          unregister_code16(LSFT(KC_A));
        }  
      }  
      return false;
    case DUAL_FUNC_14:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_E);
        } else {
          unregister_code16(KC_E);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_E));
        } else {
          unregister_code16(LSFT(KC_E));
        }  
      }  
      return false;
    case DUAL_FUNC_15:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_I);
        } else {
          unregister_code16(KC_I);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_I));
        } else {
          unregister_code16(LSFT(KC_I));
        }  
      }  
      return false;
    case DUAL_FUNC_16:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_U);
        } else {
          unregister_code16(KC_U);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_U));
        } else {
          unregister_code16(LSFT(KC_U));
        }  
      }  
      return false;
    case DUAL_FUNC_17:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_X);
        } else {
          unregister_code16(KC_X);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_X));
        } else {
          unregister_code16(LSFT(KC_X));
        }  
      }  
      return false;
    case DUAL_FUNC_18:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_Q);
        } else {
          unregister_code16(KC_Q);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_Q));
        } else {
          unregister_code16(LSFT(KC_Q));
        }  
      }  
      return false;
    case DUAL_FUNC_19:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_AE);
        } else {
          unregister_code16(DE_AE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(DE_AE));
        } else {
          unregister_code16(LSFT(DE_AE));
        }  
      }  
      return false;
    case DUAL_FUNC_20:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_UE);
        } else {
          unregister_code16(DE_UE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(DE_UE));
        } else {
          unregister_code16(LSFT(DE_UE));
        }  
      }  
      return false;
    case DUAL_FUNC_21:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_OE);
        } else {
          unregister_code16(DE_OE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(DE_OE));
        } else {
          unregister_code16(LSFT(DE_OE));
        }  
      }  
      return false;
    case DUAL_FUNC_22:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_V);
        } else {
          unregister_code16(KC_V);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_V));
        } else {
          unregister_code16(LSFT(KC_V));
        }  
      }  
      return false;
    case DUAL_FUNC_23:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_G);
        } else {
          unregister_code16(KC_G);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_G));
        } else {
          unregister_code16(LSFT(KC_G));
        }  
      }  
      return false;
    case DUAL_FUNC_24:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_C);
        } else {
          unregister_code16(KC_C);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_C));
        } else {
          unregister_code16(LSFT(KC_C));
        }  
      }  
      return false;
    case DUAL_FUNC_25:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_L);
        } else {
          unregister_code16(KC_L);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_L));
        } else {
          unregister_code16(LSFT(KC_L));
        }  
      }  
      return false;
    case DUAL_FUNC_26:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_SS);
        } else {
          unregister_code16(DE_SS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(DE_SS));
        } else {
          unregister_code16(LSFT(DE_SS));
        }  
      }  
      return false;
    case DUAL_FUNC_27:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(DE_Z);
        } else {
          unregister_code16(DE_Z);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(DE_Z));
        } else {
          unregister_code16(LSFT(DE_Z));
        }  
      }  
      return false;
    case DUAL_FUNC_28:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_D);
        } else {
          unregister_code16(KC_D);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_D));
        } else {
          unregister_code16(LSFT(KC_D));
        }  
      }  
      return false;
    case DUAL_FUNC_29:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_T);
        } else {
          unregister_code16(KC_T);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_T));
        } else {
          unregister_code16(LSFT(KC_T));
        }  
      }  
      return false;
    case DUAL_FUNC_30:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_R);
        } else {
          unregister_code16(KC_R);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_R));
        } else {
          unregister_code16(LSFT(KC_R));
        }  
      }  
      return false;
    case DUAL_FUNC_31:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_N);
        } else {
          unregister_code16(KC_N);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_N));
        } else {
          unregister_code16(LSFT(KC_N));
        }  
      }  
      return false;
    case DUAL_FUNC_32:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_S);
        } else {
          unregister_code16(KC_S);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_S));
        } else {
          unregister_code16(LSFT(KC_S));
        }  
      }  
      return false;
    case DUAL_FUNC_33:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_F);
        } else {
          unregister_code16(KC_F);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_F));
        } else {
          unregister_code16(LSFT(KC_F));
        }  
      }  
      return false;
    case DUAL_FUNC_34:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_B);
        } else {
          unregister_code16(KC_B);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_B));
        } else {
          unregister_code16(LSFT(KC_B));
        }  
      }  
      return false;
    case DUAL_FUNC_35:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_P);
        } else {
          unregister_code16(KC_P);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_P));
        } else {
          unregister_code16(LSFT(KC_P));
        }  
      }  
      return false;
    case DUAL_FUNC_36:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_W);
        } else {
          unregister_code16(KC_W);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_W));
        } else {
          unregister_code16(LSFT(KC_W));
        }  
      }  
      return false;
    case DUAL_FUNC_37:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_M);
        } else {
          unregister_code16(KC_M);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_M));
        } else {
          unregister_code16(LSFT(KC_M));
        }  
      }  
      return false;
    case DUAL_FUNC_38:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_J);
        } else {
          unregister_code16(KC_J);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_J));
        } else {
          unregister_code16(LSFT(KC_J));
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_131_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(131,255,255);
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

void on_dance_cmd(tap_dance_state_t *state, void *user_data);
void dance_cmd_finished(tap_dance_state_t *state, void *user_data);
void dance_cmd_reset(tap_dance_state_t *state, void *user_data);

void on_dance_cmd(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_DQOT);
        tap_code16(DE_DQOT);
        tap_code16(DE_DQOT);
    }
    if(state->count > 3) {
        tap_code16(DE_DQOT);
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
        [DANCE_CMD] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_cmd, dance_cmd_finished, dance_cmd_reset),
        [DANCE_QUTS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_quotes, dance_quotes_finished, dance_quotes_reset),
        [DANCE_QUE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_que_excl, dance_que_excl_finished, dance_que_excl_reset),
        [DANCE_BRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_brc, dance_brc_finished, dance_brc_reset),
        [DANCE_PRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_prn, dance_prn_finished, dance_prn_reset),
        [DANCE_CBR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_cbr, dance_cbr_finished, dance_cbr_reset),
};
