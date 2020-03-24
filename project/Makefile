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
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o buzzer.o The_Game.o wdInterruptHandler.o ../demos/lib/libTimer.a stateMachines.o led.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf *~

blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h game_helpers/led.h game_helpers/buzzer.h
	${CC} ${CFLAGS} -c -I../demos/timerLib -Igame_helpers blinky_buzzy_toy.c

stateMachines.o: game_helpers/led.h game_helpers/stateMachines.h game_helpers/stateMachines.c 
	${CC} ${CFLAGS} -c -Igame -Igame_helpers game_helpers/stateMachines.c

wdInterruptHandler.o: game_helpers/wdInterruptHandler.c game/The_Game.h
	${CC} ${CFLAGS} -c -Igame game_helpers/wdInterruptHandler.c

The_Game.o: game/The_Game.h game/The_Game.c game_helpers/buzzer.h
	${CC} ${CFLAGS} -c -I./ -Igame_helpers game/The_Game.c

led.o: game_helpers/led.c game_helpers/led.h
	${CC} ${CFLAGS} -c -Igame_helpers game_helpers/led.c

buzzer.o: game_helpers/buzzer.c game_helpers/buzzer.h ../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../demos/timerLib game_helpers/buzzer.c
