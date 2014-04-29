all: parser.o scanner.o symbol_table.o
	gcc -ansi -pedantic -o ag scanner.o parser.o symbol_table.o -lfl

oxout.y oxout.l: parser.y scanner.l
	ox parser.y scanner.l

scanner.c: oxout.l
	flex -t oxout.l > scanner.c

scanner.o: scanner.c
	gcc -c scanner.c

symbol_table.o: symbol_table.c symbol_table.h
	gcc -c -ansi -pedantic -Wall symbol_table.c -D_GNU_SOURCE

parser.c oxout.tab.h: oxout.y
	bison -vd oxout.y
	mv oxout.tab.c parser.c

parser.o: parser.c
	gcc -c -ansi -pedantic parser.c

clean:
	rm -f scanner.c ag *.o *.output *.tab.h parser.c oxout.*



