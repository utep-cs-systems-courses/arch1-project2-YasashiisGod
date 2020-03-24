#include "concert.h"
#include "buzzer.h"
#include "led.h"

static void set_light(char conductor_position, char change_dimness);

static void set_light(char conductor_position, char change_dimness)
{
  static char dim_light = 0;

  dim_light = (change_dimness) ? dim_light^1 : dim_light;

  if (conductor_position % 2 == 0)
  {
    green_toggle_on();
  }
  else {
    red_toggle_on();
  }
  if (dim_light)
  {
    both_off();
  }
}

void found_sound()
{
  short sound_notes[] = {1,2,1,0,1,3,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static char conductor = 0;
  static int n = 0;

  if (++n < 100){
    set_light(conductor, ((n == 1)? 1:0));
  }
  else {
    tone_player(sound_notes[conductor]);
  }

  if (++n > 127){
    if (++conductor> 20){
      conductor = 0;
    }
    n = 0;
  }
} 
