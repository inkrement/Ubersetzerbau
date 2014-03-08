##
## Makefile <prototype>
##

.PHONY: clean

#CC=gcc-4.4

all: clean
	$(CC) -c asmb.s -o asmb.o

upload:
	scp ./* u0929002@g0.complang.tuwien.ac.at:abgabe/asma

c: clean
	$(CC) -c asmb.c -o asmb.o
	$(CC) -c test.c -o test.o
	$(CC) asmb.o test.o -o test
	./test

test: clean
	$(CC) -c asmb.s -o asmb.o
	$(CC) -c test.c -o test.o
	$(CC) asmb.o test.o -o test
	./test

clean:
	rm -f *.o
	rm -f test