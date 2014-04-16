.PHONY: clean

all: parser

#parser.tab.c parser.tab.h:	parser.y
#	bison -d parser.y

#lex.yy.c: scanner.l parser.tab.h
#	flex scanner.l

oxout.y oxout.l: parser.y scanner.l
	ox parser.y scanner.l

oxout.tab.c oxout.tab.h: oxout.y
	bison -d oxout.y

lex.yy.c: oxout.l
	lex oxout.l

parser: lex.yy.c oxout.tab.c oxout.tab.h
	gcc oxout.tab.c lex.yy.c -lfl -o parser

clean:
	rm oxout.tab.c oxout.y oxout.l oxout.tab.h lex.yy.c