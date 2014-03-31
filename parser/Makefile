.PHONY: clean

all: parser

parser.tab.c parser.tab.h:	parser.y
	bison -d parser.y

lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

parser: lex.yy.c parser.tab.c parser.tab.h
	gcc parser.tab.c lex.yy.c -lfl -o parser

clean:
	rm parser parser.tab.c lex.yy.c parser.tab.h