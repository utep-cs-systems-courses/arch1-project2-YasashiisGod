#include <msp430.h>
#include "button.h"

void button_update_interrupt_sense()
{
  P2IES |= (P2IN & BUTTONS);
  P2IES &= (P2IN | ~BUTTONS);
}

void button_init()
{
  P2OUT |= BUTTONS;
  P2REN |= BUTTONS;
  P2IE = BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;

  button_update_interrupt_sense();
}
