# makfile configuration
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: simon catch_red find_frequency fur_elise

clean:
	rm -f *.o

simon: simon.h simon.c ../game_utils/led.h ../game_utils/buzzer.h
	${CC} ${CFLAGS} -c -I./ -I../game_utils  simon.c
