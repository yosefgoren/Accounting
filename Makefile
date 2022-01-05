all:
	flex scanner.lex
	bison -d parser.ypp
	g++ -std=c++11 -o accounting -g3 *.c *.cpp

clean:
	rm -f lex.yy.c
	rm -f parser.tab.*pp
	rm -f accounting