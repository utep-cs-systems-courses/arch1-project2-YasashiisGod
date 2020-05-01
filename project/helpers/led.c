#include <msp430.h>
#include "stateMachines.h"
#include "button.h"
#include "led.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
unsigned char dim_on = 0;


static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;
  button_state_altered = 1;
  led_change();
}
void led_change()
{
  if (button_state_altered | dim_on | led_changed){
  
    char ledFlags = greenVal[green_on] | redVal[red_on];

    //ledFlags |= button_state ? LED_GREEN : 0;
    //ledFlags |= button_state ? 0 : LED_RED;
    
    P1OUT &= (0xff ^ LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  button_state_altered = 0;
  led_changed = 0;
  dim_on = 0;
}

void green_toggle_on()
{
  green_on = 1;
  red_on = 0;
  led_change();
}

void red_toggle_on()
{
  red_on = 1;
  green_on = 0;
  led_change();
}

void green_toggle_off()
{
  green_on = 0;
  led_change();
}

void red_toggle_off()
{
  red_on = 0;
  led_change();
}

void both_off()
{
  red_on = 0;
  green_on = 0;
  led_change();
}

