#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "concert.h"
#include "libTimer.h"


char button_state, button_state_altered;

static char button_update_interrupt_sense()
{
  char p2val = P2IN; //update button interrupt to detect changes from current buttons
  P1IES |= (p2val & BUTTONS);  // if switch up, sense down
  P1IES &= (p2val | ~BUTTONS); // if switch down, sense up
  return p2val;
}

void next_state() {
  char p2val = button_update_interrupt_sense();

  if (p2val & BTN1 && p2val & BTN2 && p2val & BTN3 && p2val & BTN4)
  {
    buzzer_set_period(0);
    button_state = 0;
  }
  else if (!(p2val & BTN1))
  {
    found_sound();
    button_state = 1;
  }
  else if (!(p2val & BTN3))
  {
    buzzer_set_period(0);
    button_state = 0;
  }

  if (button_state)
  {
    button_state_altered = 1;
    led_change();

  }
  else
  {
    button_state_altered = 1;
    led_change();
    dim_led();
  }
}
void dim_led()
{
  unsigned int j;

  for (j = 1; j < 1200; j++)
  {
    P1OUT |= LED_RED;
    delay(j);
    P1OUT &= ~LED_RED;
    delay(1200 - j);
  }
  for (j = 1200; j > 1; j--)
  {
    P1OUT |= LED_RED;
    delay(j);
    P1OUT &= ~LED_RED;
    delay(1200 - j);
  }
  button_state_altered = 0;
}

void delay (unsigned int n)
{
  unsigned int i;
  for (i = n; i > 0; i--)
  {
    __delay_cycles(1);
  }
}
