#ifndef led_included
#define led_included

#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;

void led_init();

void led_change();

void green_toggle_on();

void red_toggle_on();

void green_toggle_off();

void red_toggle_off();

void both_off();

#endif

