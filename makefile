build: a.out

test: 
	python3 validateSamples.py 

a.out: clean tiger.tab.o lex.yy.o errormsg.o absyn.o prabsyn.o symbol.o table.o util.o types.o parse.o semant.o env.o
	cc -g tiger.tab.o lex.yy.o errormsg.o absyn.o prabsyn.o symbol.o table.o util.o types.o parse.o semant.o env.o

lextest: lex.yy.o errormsg.o util.o
	cc -g -o lextest lex.yy.o errormsg.o util.o

lex.yy.o: lex.yy.c tiger.tab.h errormsg.h util.hpp
	cc -g -c lex.yy.c

tiger.tab.o: tiger.tab.c
	cc -g -c tiger.tab.c

tiger.tab.c: tiger.y
	bison -d -t -v tiger.y

parsetest.o: parsetest.c errormsg.h util.hpp
	cc -g -c parsetest.c

tiger.tab.h: tiger.tab.c
	echo "tiger.tab.h was created at the same time as tiger.tab.c"

errormsg.o: errormsg.cpp errormsg.hpp util.hpp
	g++ -g -c errormsg.cpp

lex.yy.c: tiger.l
	lex tiger.l

util.o: util.cpp util.hpp
	g++ -g -c util.cpp

symbol.o: symbol.c symbol.h util.hpp table.hpp
	cc -g -c symbol.c

table.o: table.cpp table.hpp util.hpp
	g++ -g -c table.cpp

types.o: types.cpp types.hpp
	cc -g -c types.cpp

env.o: env.cpp env.hpp
	cc -g -c env.cpp

semant.o: semant.c semant.h
	cc -g -c semant.c

parse.o : parse.cpp parse.hpp util.hpp symbol.h errormsg.h absyn.h
	cc -g -c parse.cpp

clean: 
	rm -f a.out lex.yy.c tiger.tab.c tiger.tab.h tiger.output absyn.h.gch
	rm -f a.out *.o