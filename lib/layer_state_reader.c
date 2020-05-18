
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "fuhe.h"

#define L_MDVORAK 0
#define L_SMDVORAK 2
#define L_MSKYTOUCH 4
#define L_SMSKYTOUCH 8
#define L_MARK 16
#define L_NUM 32
#define L_FUNC 64
#define L_SFUNC 128

char layer_state_str[24];

const char *read_layer_state(void) {
  if ((layer_state / L_SFUNC) % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: S_Function");
  }else if ((layer_state / L_FUNC) % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Function");
  }else if ((layer_state / L_NUM) % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numpad");
  }else if ((layer_state / L_MARK) % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mark");
  }else if ((layer_state / L_SMSKYTOUCH) % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: S_Japanese");
  }else if ((layer_state / L_MSKYTOUCH) % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Japanese");
  }else if ((layer_state / L_SMDVORAK) % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: S_English");
  }else if (layer_state % 2 == 1){
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: English");
  }else if (layer_state == 0){
    snprintf(layer_state_str, sizeof(layer_state_str), "Base");
  }else{
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }
  return layer_state_str;
}
