#include "msp430.h"
#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "concert.h"
#include "libTimer.h"


char button_state, button_state_altered;
char button0, button1, button2, button3, button4;

extern void toggle();

void reset_state()
{
  red_on = 0;
  green_on = 0;
  led_change();
}

static char button_update_interrupt_sense()
{
  char p2val = P2IN; //update button interrupt to detect changes from current buttons
  P1IES |= (p2val & BUTTONS);  // if switch up, sense down
  P1IES &= (p2val | ~BUTTONS); // if switch down, sense up
  return p2val;
}


static char button_choice()
{
  char p2val = button_update_interrupt_sense();
  char buttonState = 0;
  
  if(p2val & BTN1 && p2val & BTN2 && p2val & BTN3 && p2val & BTN4)
  {
    buttonState = 0;
    return 0;
  }
  else if (!(p2val & BTN1))
  {
    buttonState = 1;
    return 1;
  }
  else if (!(p2val & BTN2))
  {
    buttonState = 2;
    return 2;
  }
  else if (!(p2val & BTN3))
  {
    buttonState = 3;
    return 3;
  }
  else if (!(p2val & BTN4))
  {
    buttonState = 4;
    return 4;
  }
  else return 0;
}   
void next_state() {
  char buttonState = button_choice();

  switch (buttonState)
  {
  case 0:
    buzzer_set_period(0);
    button_state = 0;
    break;
    //button 1 play found sound 
  case 1:
    toggle();
    button_state = 1;
    break;
  case 2:
    //found_sound();
    reset_state();
    button_state = 1;
    break;
  case 3:
    //found_sound();
    buzzer_set_period(200);
    red_on = 1;
    //reset_state();
    button_state = 1;
    break;
  case 4:
    buzzer_set_period(0);
    reset_state();
    button_state = 0;
    break;
    
  }

  if(button_state)
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
