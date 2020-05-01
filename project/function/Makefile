# makfile configuration
COMMON_OBJECTS 	=

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I ../demos/h -I function

LDFLAGS 	= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS 		= msp430-elf-as

all: concert.o

blinky_buzzy_toy.elf:${COMMON_OBJECTS} concert.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

clean:
	rm -f *.o

concert.o: concert.h concert.c ../helpers/led.h ../helpers/buzzer.h
	${CC} ${CFLAGS} -c -I./ -I../helpers  concert.c
