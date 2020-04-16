.DEFAULT=all
.PHONY=all
all: relational_algebra.y relational_algebra.l
	bison -vd relational_algebra.y
	lex relational_algebra.l
	gcc relational_algebra.tab.c lex.yy.c

clean:
	rm -f relational_algebra.tab.c relational_algebra.tab.h lex.yy.c
