#
COMMON_OBJECTS	=
CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I ../demos/h -I function 
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#
CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: blinky_buzzy_toy.elf

#
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o buzzer.o concert.o wdInterruptHandler.o ../demos/lib/libTimer.a stateMachines.o led.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf *~

blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h helpers/led.h helpers/buzzer.h
	${CC} ${CFLAGS} -c -I../demos/timerLib -Ihelpers blinky_buzzy_toy.c

stateMachines.o: helpers/led.h helpers/stateMachines.h helpers/stateMachines.c 
	${CC} ${CFLAGS} -c -Ifunction -Ihelpers helpers/stateMachines.c

wdInterruptHandler.o: helpers/wdInterruptHandler.c function/concert.h
	${CC} ${CFLAGS} -c -Ifunction helpers/wdInterruptHandler.c

concert.o: function/concert.h function/concert.c helpers/buzzer.h helpers/led.h 
	${CC} ${CFLAGS} -c -I./ -Ihelpers function/concert.c

led.o: helpers/led.c helpers/led.h 
	${CC} ${CFLAGS} -c -Ihelpers helpers/led.c

buzzer.o: helpers/buzzer.c helpers/buzzer.h ../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../demos/timerLib helpers/buzzer.c
