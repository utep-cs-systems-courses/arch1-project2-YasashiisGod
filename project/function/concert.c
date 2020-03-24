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
  short sound_notes[] = {1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static char conductor = 0;
  static int n = 0;
  static int nothing = 0;
 
  if (++n < 200){
    // set_light(conductor, ((n == 1)? 1:0));
    nothing++;
    red_toggle_on();
  }
  else {
    if (sound_notes[conductor] != 0){
      green_toggle_on();
    }
    tone_player(sound_notes[conductor]);
  }
 
  if (++n > 255){
    if (++conductor> 20){
      conductor = 0;
    }
    n = 0;
  }
} 
