# makfile configuration
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I function

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: concert

clean:
	rm -f *.o

function: function.h function.c ../helpers/led.h ../helpers/buzzer.h
	${CC} ${CFLAGS} -c -I./ -I../helpers  concert.c
