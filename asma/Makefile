all:
	gcc -c asma.s -o asma.o

c_prog:
	gcc -O -S asma.c -o asma_einfach.s

upload:
	scp ./* u0929002@g0.complang.tuwien.ac.at:abgabe/asma

clean:
	rm asma.o