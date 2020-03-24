#include "concert.h"
#include "buzzer.h"

void found_sound()
{
  short sound_notes[] = {1,2,1,0,1,3,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static char conductor = 0;
  static int count = 0;
  static int n = 0;

  if (++count < 100){
    n++;
  }
  else {
    tone_player(sound_notes[conductor]);
  }

  if (++count > 127){
    if (++conductor> 20){
      conductor = 0;
    }
    count = 0;
  }
} 
