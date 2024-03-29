LANG=diy
EXT=diy # file extension: .$(EXT)
LIB=lib # compiler library directory
UTIL=util # compiler library: lib$(LIB).a
RUN=run # runtime directory
EXS=exs # examples directory
CC=gcc
CFLAGS=-g -DYYDEBUG


$(LANG): $(LANG).y $(LANG).l $(LANG).brg
	make -C $(LIB)
	byacc -dv $(LANG).y
	flex -l $(LANG).l
	pburg  $(LANG).brg
	$(LINK.c) -o $(LANG) $(ARCH) -I$(LIB) lex.yy.c y.tab.c yyselect.c -L$(LIB) -l$(UTIL)

examples:: $(LANG)
	make -C $(EXS)

clean::
	make -C $(LIB) clean
	make -C $(RUN) clean
	make -C $(EXS) clean
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output yyselect.c *.asm *~
