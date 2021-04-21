build: a.out

test: 
	python3 validateSamples.py 

a.out: clean tiger.tab.o lex.yy.o errormsg.o absyn.o prabsyn.o symbol.o table.o util.o types.o parse.o semant.o env.o
	cc -g tiger.tab.o lex.yy.o errormsg.o absyn.o prabsyn.o symbol.o table.o util.o types.o parse.o semant.o env.o

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

symbol.o: symbol.c symbol.h util.h table.h
	cc -g -c symbol.c

table.o: table.c table.h util.h
	cc -g -c table.c

types.o: types.c types.h
	cc -g -c types.c

env.o: env.c env.h
	cc -g -c env.c

semant.o: semant.c semant.h
	cc -g -c semant.c

parse.o : parse.c parse.h util.h symbol.h errormsg.h absyn.h
	cc -g -c parse.c

clean: 
	rm -f a.out lex.yy.c tiger.tab.c tiger.tab.h tiger.output absyn.h.gch
	rm -f a.out *.o