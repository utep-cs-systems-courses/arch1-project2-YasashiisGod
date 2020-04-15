#include <msp430.h>
#include "concert.h"
#include "stateMachines.h"
#include "button.h"

void __interrupt_vec(PORT2_VECTOR)Port_2(){
  if (P2IFG & BUTTONS) {
    P2IFG &= ~BUTTONS;
    next_state();
  }
}
