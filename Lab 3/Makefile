.DEFAULT=all
.PHONY=all
all: part2.y part2.l
	bison -vd part2.y
	lex part2.l
	gcc part2.tab.c lex.yy.c

clean:
	rm -f part2.tab.c part2.tab.h lex.yy.c
