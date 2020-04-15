#ifndef buzzer_included
#define buzzer_included

void buzzer_init();

void buzzer_set_period(short cycles);

//void sound_key(unsigned char note_num); // for playing certain notes

void tone_player(unsigned char note_num);

//static short tone (unsigned char note_num);

#endif


