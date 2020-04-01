#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static short tone (unsigned char note_num);

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}


static short tone (unsigned char note_num)
{
  //Note 4G
  if (note_num == 1)
    {
      return 7329;
    }
  //Note 4Gb
  if (note_num == 2)
    {
      return 370;
    }
  //Note 4D#
  if (note_num == 3)
    {
      return 311;
    }
  //Note 3A
  if (note_num == 4)
    {
      return 220;
    }
  //Note 3Ab
  if (note_num == 5)
    {
      return 207;
    }
  // Note 4E
  if (note_num == 6)
    {
      return 329;
    }
  //Note 4Ab
  if (note_num == 7)
    {
      return 415;
    }
  //Note C8
  if (note_num == 8)
    {
      return 523;
    }
  return 1;
}

void tone_player(unsigned char i)
{
  buzzer_set_period(tone(i));
}


