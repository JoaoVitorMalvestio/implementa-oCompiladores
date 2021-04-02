build: a.out

test: 
	python3 validateSamples.py 

a.out: clean tiger.tab.o lex.yy.o errormsg.o util.o
	cc -g tiger.tab.o lex.yy.o errormsg.o util.o table.c symbol.c absyn.c prabsyn.c

lextest: lex.yy.o errormsg.o util.o
	cc -g -o lextest lex.yy.o errormsg.o util.o

lex.yy.o: lex.yy.c tiger.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

tiger.tab.o: tiger.tab.c
	cc -g -c tiger.tab.c

tiger.tab.c: tiger.y
	bison -d -t -v tiger.y

parsetest.o: parsetest.c errormsg.h util.h
	cc -g -c parsetest.c

tiger.tab.h: tiger.tab.c
	echo "tiger.tab.h was created at the same time as tiger.tab.c"

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.c: tiger.l
	lex tiger.l

util.o: util.c util.h
	cc -g -c util.c

clean: 
	rm -f a.out util.o lex.yy.o lex.yy.c errormsg.o lextest
	rm -f a.out util.o parsetest.o lex.yy.o errormsg.o tiger.tab.c tiger.tab.h tiger.tab.o