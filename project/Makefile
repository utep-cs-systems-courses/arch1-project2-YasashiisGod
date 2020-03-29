#
COMMON_OBJECTS	=
CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I ../demos/h -I function 
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#
CC		= msp430-elf-gcc

all: 
	(cd ../demos/timerLib && make install)
	(cd helpers && make)
	(cd function && make)
	
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o helpers/buzzer.o function/concert.o helpers/wdInterruptHandler.o ../demos/lib/libTimer.a helpers/stateMachines.o helpers/led.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	(cd function && make clean)
	(cd helpers && make clean)
	rm -f *.o *.elf *~ *#
	
blinky_buzzy_toy.o: ../demos/timerLib/libTimer.h helpers/led.h helpers/buzzer.h
	${CC} ${CFLAGS} -c -I../demos/timerLib -Ihelpers blinky_buzzy_toy.c
