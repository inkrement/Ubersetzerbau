##
## Makefile <prototype>
##

.PHONY: clean

CC=gcc-4.4

all: clean
	$(CC) -c asma.s -o asma.o

upload:
	scp ./* u0929002@g0.complang.tuwien.ac.at:abgabe/asma

#build for mac OSX with gcc 4.4
test: clean
	$(CC) -c asma.s -o asma.o
	$(CC) -c test.c -o test.o
	$(CC) asma.o test.o -o test
	./test

clean:
	rm *.o
	rm -f test