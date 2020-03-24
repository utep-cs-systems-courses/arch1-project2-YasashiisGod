#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;
  led_change();
}
void led_change()
{
  char ledFlags = redVal[red_on] | greenVal[green_on];

  P1OUT &= (0xff^LEDS) | ledFlags;

  P1OUT |= ledFlags;
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

