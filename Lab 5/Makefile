.DEFAULT=all
.PHONY=all
all: c_comp.y c_comp.l
	bison -vd c_comp.y
	lex c_comp.l
	gcc c_comp.tab.c lex.yy.c

clean:
	rm -f c_comp.tab.c c_comp.tab.h lex.yy.c
