#include <msp430.h>
#include "concert.h"
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  if (game_num == 1)
    {
      found_sound();
    }
  
  else
    {
      printf("Hello\n");
    }
}


