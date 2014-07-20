all: parser.o scanner.o 
	gcc -o parser scanner.o parser.o -lfl

scanner.c: scanner.l
	flex -t --yylineno scanner.l > scanner.c

scanner.o: scanner.c
	gcc -c scanner.c

parser.c oxout.tab.h: parser.y
	bison -d -t -v parser.y
	mv parser.tab.c parser.c

parser.o: parser.c
	gcc -c parser.c

clean:
	rm -f scanner.c parser *.o *.output *.tab.h parser.c