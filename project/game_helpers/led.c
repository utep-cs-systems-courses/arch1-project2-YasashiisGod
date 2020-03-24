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

void turn_on_green()
{
  green_on = 1;
  red_on = 0;
  led_change();
}

void turn_on_red()
{
  red_on = 1;
  green_on = 0;
  led_change();
}

void turn_off_green()
{
  green_on = 0;
  led_change();
}

void turn_off_red()
{
  red_on = 0;
  led_change();
}

void turn_off_red_green()
{
  red_on = 0;
  green_on = 0;
  led_change();
}

