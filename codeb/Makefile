.PHONY: upload test clean

all: codeb

codeb: parser.o scanner.o symbol_table.o struct_table.o assembler.o tree.o code.o
	gcc -g -ansi -pedantic scanner.o parser.o symbol_table.o assembler.o struct_table.o tree.o code.o -lfl -o codeb

oxout.y oxout.l: parser.y scanner.l
	ox parser.y scanner.l

scanner.c: oxout.l
	flex -t oxout.l > scanner.c

scanner.o: scanner.c
	gcc -g -c scanner.c 

symbol_table.o: symbol_table.c symbol_table.h
	gcc -g -c -ansi -pedantic -Wall symbol_table.c -D_GNU_SOURCE

assembler.o: assembler.c assembler.h
	gcc -g -c -ansi -pedantic -Wall assembler.c -D_GNU_SOURCE

struct_table.o: symbol_table.o
	gcc -g -c -ansi -pedantic -Wall symbol_table.o struct_table.c -D_GNU_SOURCE

parser.c oxout.tab.h: oxout.y
	bison -vd oxout.y
	mv oxout.tab.c parser.c

parser.o: parser.c
	gcc -g -c -ansi -pedantic parser.c

tree.o: tree.c tree.h
	gcc -g -c -ansi -pedantic -D_GNU_SOURCE -Wall tree.c

code.o: code.c tree.h
	gcc -g -c -ansi code.c

code.c: code.bfe
	bfe < code.bfe | iburg > code.c

clean:
	rm -f scanner.c codeb *.o *.output *.tab.h parser.c oxout.* code.c core

upload: clean
	scp * u0929002@g0.complang.tuwien.ac.at:/home/ublu14/u0929002/abgabe/codeb

test:
	/usr/ftp/pub/ubvl/test/codeb/test