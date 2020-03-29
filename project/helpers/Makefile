CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: led buzzer wdt_interrupt_handler state_machines

led: led.c led.h
	${CC} ${CFLAGS} -c led.c

buzzer: buzzer.c buzzer.h ../../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../../demos/timerLib buzzer.c
	
wdt_interrupt_handler: wdt_interrupt_handler.c ../function/concert.h
	${CC} ${CFLAGS} -c -I../function -I../helpers wdt_interrupt_handler.c

state_machines: led.h state_machines.h state_machines.c
	${CC} ${CFLAGS} -c -I../function -I state_machines.c

clean:
	rm -f *.o
