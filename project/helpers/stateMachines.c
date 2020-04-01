#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "concert.h"

char game_num = 1;

void game_num_switcher (){
  if ((P2IN & BUTTONS) == (~BTN2 & BUTTONS)){
    game_num = 2;
  }
  if ((P2IN & BUTTONS) == (~BTN1 & BUTTONS)){
    game_num = 1;
  } 
}
