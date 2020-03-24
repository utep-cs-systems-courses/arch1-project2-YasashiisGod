#include <msp430.h>
#include "led.h" 
#include "libTimer.h"
#include "buzzer.h"
//#include "buttons.h"

int main(void)
{
  configureClocks();

  led_init();
  
  buzzer_init();

  enableWDTInterrupts();

  or_sr(0x18);
}
