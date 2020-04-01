CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: led.o buzzer.o wdInterruptHandler.o stateMachines.o button.o

clean:
	rm -f *.o

led.o: led.c led.h
	${CC} ${CFLAGS} -c led.c

buzzer.o: buzzer.c buzzer.h ../../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../../demos/timerLib buzzer.c

wdInterruptHandler.o: wdInterruptHandler.c stateMachines.h led.h ../function/concert.h 
	${CC} ${CFLAGS} -c -I../function wdInterruptHandler.c

stateMachines.o: led.h stateMachines.h stateMachines.c button.h ../function/concert.h
	${CC} ${CFLAGS} -c -I../function stateMachines.c

button.o: button.c button.h
	${CC} ${CFLAGS} -c button.c
