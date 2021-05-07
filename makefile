build: a.out

test: 
	python3 validateSamples.py 

a.out: clean tiger.tab.o lex.yy.o errormsg.o absyn.o prabsyn.o symbol.o table.o util.o types.o parse.o semant.o env.o
	g++ -g tiger.tab.o lex.yy.o errormsg.o absyn.o prabsyn.o symbol.o table.o util.o types.o parse.o semant.o env.o

lextest: lex.yy.o errormsg.o util.o
	g++ -g -o lextest lex.yy.o errormsg.o util.o

lex.yy.o: lex.yy.c tiger.tab.hpp errormsg.hpp util.hpp
	g++ -g -c lex.yy.c

tiger.tab.o: tiger.tab.c
	cc -g -c tiger.tab.c

tiger.tab.c: tiger.y
	bison -d -t -v tiger.y

parsetest.o: parsetest.cpp errormsg.hpp util.hpp
	g++ -g -c parsetest.cpp

tiger.tab.h: tiger.tab.c
	echo "tiger.tab.h was created at the same time as tiger.tab.c"

errormsg.o: errormsg.cpp errormsg.hpp util.hpp
	g++ -g -c errormsg.cpp

lex.yy.c: tiger.l
	lex tiger.l

util.o: util.cpp util.hpp
	g++ -g -c util.cpp

symbol.o: symbol.cpp symbol.h util.hpp table.hpp
	g++ -g -c symbol.cpp

table.o: table.cpp table.hpp util.hpp
	g++ -g -c table.cpp

types.o: types.cpp types.hpp
	g++ -g -c types.cpp

env.o: env.cpp env.hpp
	g++ -g -c env.cpp

semant.o: semant.cpp semant.hpp
	g++ -g -c semant.cpp

parse.o : parse.cpp parse.hpp util.hpp symbol.hpp errormsg.hpp absyn.hpp
	g++ -g -c parse.cpp

clean: 
	rm -f a.out lex.yy.c tiger.tab.c tiger.tab.h tiger.output
	rm -f a.out *.o *.gch