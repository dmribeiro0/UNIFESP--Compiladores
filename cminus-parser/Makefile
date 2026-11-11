all: exec

parser.tab.c parser.tab.h: parser.y
	bison -d -v -g parser.y

lex.yy.c: scanner.l parser.tab.h globals.h
	flex scanner.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

exec: lex.yy.o parser.tab.c main.c globals.h
	g++ -o exec lex.yy.o parser.tab.c main.c -ly -lfl

clean:
	rm -f exec lex.yy.c lex.yy.o parser.tab.c parser.tab.h parser.output parser.gv

.PHONY: all clean
