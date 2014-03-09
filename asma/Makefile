##
## Makefile <prototype>
##

.PHONY: clean

#CC=gcc-4.4

all: clean
	$(CC) -c asma.s -o asma.o

upload:
	scp ./* u0929002@g0.complang.tuwien.ac.at:abgabe/asma

test: clean
	$(CC) -c asma.s -o asma.o
	$(CC) -c test.c -o test.o
	$(CC) asma.o test.o -o test
	./test

c: clean
	$(CC) -c asma.c -o asma_c.o
	$(CC) -c test.c -o test.o
	$(CC) asma_c.o test.o -o test_c
	./test_c

compare: clean c test

clean:
	rm -f *.o
	rm -f test test_c