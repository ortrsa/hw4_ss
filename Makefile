FLAG= -Wall -g

all: frequency

frequency: main.o frequency.o
	gcc $(FLAG) -o frequency main.o frequency.o

main.o: main.c frequency.h
	gcc $(FLAG) -c main.c

frequency.o: frequency.c frequency.h
	gcc $(FLAG) -c frequency.c

.PHONY: clean all

clean:
	rm -f *.o isort frequency
