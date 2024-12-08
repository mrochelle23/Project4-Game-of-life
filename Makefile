all: conway.out

conway.out: conway.c board.c board.h
	gcc -Wall -o conway.out conway.c board.c

clean:
	rm -f conway.out
