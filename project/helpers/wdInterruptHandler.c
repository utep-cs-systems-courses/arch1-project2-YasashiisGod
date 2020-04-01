#include <msp430.h>
#include "concert.h"
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  switch (game_num){
  case 1:
    found_sound();
    break;
  case 2:
    everything_off();
    break;
  }
}
      


