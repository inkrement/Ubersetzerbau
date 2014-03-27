
all:
	flex scanner.l
	gcc lex.yy.c -lfl -o scanner



test: all
	./scanner < test.txt

clean:
	rm lex.yy.c