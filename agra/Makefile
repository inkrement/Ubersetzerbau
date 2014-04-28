.PHONY: clean

ag: scanner.o parser.o symbol_table.o
	gcc -o ag symbol_table.o scanner.o parser.o -lfl

scanner.c: oxout.l
	flex -oscanner.c oxout.l

scanner.o: scanner.c parser.h symbol_table.h
	gcc -c -ansi -pedantic scanner.c -D_GNU_SOURCE

symbol_table.o: symbol_table.c symbol_table.h
	gcc -c -ansi -pedantic -Wall symbol_table.c -D_GNU_SOURCE

parser.o: parser.c symbol_table.h
	gcc -c -ansi -pedantic parser.c

parser.c parser.h: oxout.y
	yacc -d oxout.y -o parser.c

oxout.y oxout.l: parser.y scanner.l
	ox parser.y scanner.l

clean:
	rm -f ag *.o scanner.c parser.h parser.c oxout.y oxout.l

