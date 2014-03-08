##
## Makefile <prototype>
##

CC=gcc-4.4

all:
	$(CC) -c asma.s -o asma.o

c_prog:
	$(CC) -O -S asma.c -o asma_einfach.s

upload:
	scp ./* u0929002@g0.complang.tuwien.ac.at:abgabe/asma

#build for mac OSX with gcc 4.4
mac:
	$(CC) -c asma.s
	$(CC) -c test.c
	$(CC) asma.o test.o -o test

clean:
	rm asma.o test.o test