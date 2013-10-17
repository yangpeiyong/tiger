a.out: parsetest.o y.tab.o lex.yy.o errormsg.o util.o parse.o symbol.o table.o absyn.o prabsyn.o env.o types.o semant.o
	cc -g parsetest.o y.tab.o lex.yy.o errormsg.o util.o parse.o symbol.o table.o absyn.o prabsyn.o env.o types.o semant.o

parsetest.o: parsetest.c parse.h prabsyn.h
	cc -g -c parsetest.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: tiger.y
	yacc -dv tiger.y

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

lex.yy.c: tiger.l
	lex tiger.l

util.o: util.c util.h
	cc -g -c util.c

parse.o: parse.c parse.h absyn.h errormsg.h util.h
	cc -g -c parse.c

symbol.o: symbol.c symbol.h util.h table.h
	cc -g -c symbol.c

table.o: table.c table.h util.h
	cc -g -c table.c

absyn.o: absyn.c util.h symbol.h absyn.h
	cc -g -c absyn.c

prabsyn.o: prabsyn.c prabsyn.h symbol.h util.h absyn.h
	cc -g -c prabsyn.c

env.o: env.c env.h util.h symbol.h
	cc -g -c env.c

types.o: types.c util.h symbol.h types.h
	cc -g -c types.c

semant.o: semant.c semant.h env.h absyn.h types.h table.h
	cc -g -c semant.c

clean: 
	rm -f a.out parsetest.o y.tab.o lex.yy.o errormsg.o util.o parse.o symbol.o table.o absyn.o prabsyn.o env.o types.o semant.o
