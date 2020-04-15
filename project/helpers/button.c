#include <msp430.h>
#include "button.h"

void button_init()
{
  P2OUT |= BUTTONS;  // pull-ups for buttons
  P2REN |= BUTTONS;  // resisters for buttons
  P2IE = BUTTONS;    // interrupts for buttons
  P2DIR &= ~BUTTONS; // set button bit for input
  
}
