# Main make file
COMMON_OBJECTS	=
CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I ../demos/h -I function -I helpers
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#
CC		= msp430-elf-gcc

AS 		= msp430-elf-as 

all:
	(cd ../demos/timerLib; make install)
#(cd helpers; make blinky_buzzy_toy.elf)
#(cd function; make blinky_buzzy_toy.elf)
	make blinky_buzzy_toy.elf

blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o helpers/buzzer.o function/concert.o helpers/wdInterruptHandler.o ../demos/lib/libTimer.a helpers/stateMachines.o helpers/led.o helpers/button.o helpers/toggle.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	(cd function; make clean)
	(cd helpers; make clean)
	rm -f *.o *.elf *~ *#
