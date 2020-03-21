#
COMMON_OBJECTS	=
CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I ../demos/h -I game 
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#
CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: blinky_buzzy_toy.elf

#
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o buzzer.o ../demos/lib/libTimer.a 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf *~

blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h game_helpers/led.h game_helpers/buzzer.h
	${CC} ${CFLAGS} -c -I../demos/timerLib -Igame_helpers blinky_buzzy_toy.c

buzzer.o: game_helpers/buzzer.c game_helpers/buzzer.h ../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../demos/timerLib game_helpers/buzzer.c
