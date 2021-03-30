%{
#include <stdio.h>
#include "util.h"
#include "errormsg.h"

int yylex(void);

void printTest(string field)
{
  printf("Eu sou %s\n", field);
}

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}
%}

%locations

%union {
	int pos;
	int ival;
	string sval;
}

%error-verbose
%token <sval> ID STRING
%token <ival> INT

%token COMMA COLON SEMICOLON LPAREN RPAREN LBRACK RBRACK 
%token LBRACE RBRACE DOT PLUS MINUS TIMES DIVIDE EQ NEQ LT LE GT GE
%token AND OR ASSIGN ARRAY IF THEN ELSE WHILE FOR TO LET IN END OF 
%token BREAK NIL FUNCTION VAR TYPE DO NULLCOALESCE

%type <void> program
%type <void> root
%type <void> exp
%type <void> let

%start program

%%

program: root{};

root: /* empty */ {}
      |exp {}
      ;

exp:    INT {printTest("INT");}
      | STRING {printTest("STRING");}
      | NIL {printTest("NIL");}
      | lvalue {printTest("LVALUE");}
      | lvalue ASSIGN exp {printTest("LVALUE ASSIGN");}
      | lparen explist rparen {printTest("LPAREN EXPLIST RPAREN");}
      | cond {printTest("COND");}
      | let {printTest("LET");}
      | exp OR exp {printTest("OR");}
      | exp AND exp {printTest("AND");}
      | exp LT exp {printTest("LT");}
      | exp GT exp {printTest("GT");}
      | exp LE exp {printTest("LE");}
      | exp GE exp {printTest("GE");}
      | exp PLUS exp {printTest("PLUS");}
      | exp MINUS exp {printTest("MINUS");}
      | exp TIMES exp {printTest("TIMES");}
      | exp DIVIDE exp {printTest("DIVIDE");}
      | exp NULLCOALESCE exp {printTest("NULLCOALESCE");}
      | MINUS exp %prec UMINUS {printTest("MINUS UMINUS");}
      | exp EQ exp {printTest("EQ");}
      | exp NEQ exp {printTest("NEQ");}
      | id lparen arglist rparen {printTest("FUNCTION LPAREN RPAREN");}
      | id LBRACK exp RBRACK OF exp {printTest("LBRACK RBRACK OF");}
      | id LBRACE reclist RBRACE {printTest("LBRACE RBRACE");}
      | BREAK {printTest("BREAK");}
      ;

reclist:    /* empty */ {}
      | id EQ exp	{printTest("RECLIST");}
      | id EQ exp	COMMA reclist {printTest("RECLIST COMMA");}

let:  LET decs IN explist END {printTest("EXPRESSION LET");}
      ;

arglist:    /* empty */ {printTest("ARGLIST SEM PARAMETROS");}
      | nonarglist {printTest("ARGLIST");}
      ;

nonarglist: exp {printTest("NONARGLIST");}
      | exp COMMA nonarglist {printTest("NONARGLIST COMMA");}
      ;

decs: /* empty */ {}
      | dec decs {printTest("EXPRESSION DEC DECS");}
      ;

dec:  tydec {printTest("DEC TYPE");}
      | vardec {printTest("DEC VARDEC");}
      | fundec {printTest("DE FUNDEC");}
      ;

lvalue:     id %prec LOW {printTest("LOW");}
      | id LBRACK exp RBRACK {printTest("ID LBRACK RBRACK");}
      | lvalue LBRACK exp RBRACK {printTest("LVALUE LBRACK RBRACK");}
      | lvalue DOT id {printTest("LVALUE DOT");}
      ;

explist:    /* empty */ {printTest("EXPLIST VAZIO");}
      | exp	{printTest("EXPLIST");}
      | exp SEMICOLON explist {printTest("EXPLIST SEMICOLON");}
      ;

cond: IF exp THEN exp ELSE exp {printTest("IF THEN ELSE");}
      | IF exp THEN exp	{printTest("IF THEN");}
      | WHILE exp DO exp {printTest("WHILE DO");}
      | FOR id ASSIGN exp TO exp DO exp {printTest("FOR ASSIGN TO DO");}
      ;

tydec:      TYPE id EQ ty {printTest("TYDEC");}
      ;

ty:   id {}
      | LBRACE tyfields RBRACE {printTest("LBRACE RBRACE");}
      | ARRAY OF id {printTest("ARRAY OF");}
      ;

tyfields:   /* empty */	{}
      | tyfield {printTest("TYFIELDS");}
      | tyfield COMMA tyfields {printTest("TYFIELDS COMMA");}
      ;

tyfield:    id COLON id {printTest("TYFIELD");}
      ;

vardec: VAR id ASSIGN exp {printTest("VARDEC");}
      | VAR id COLON id ASSIGN exp {printTest("VARDEC COLON");}
      ;

id:   ID {printTest("ID");}
      ;

fundec: FUNCTION id lparen tyfields rparen EQ exp {printTest("FUNDEC");}
      | FUNCTION id lparen tyfields rparen COLON id EQ exp	{printTest("FUNDEC COLON");}
      ;

lparen: LPAREN {printTest("LPAREN");}
      ;

rparen: RPAREN {printTest("RPAREN");}
      ;

%%

extern int yyparse(void);

void parse(string fname) 
{EM_reset(fname);
 if (yyparse() == 0) /* parsing worked */
   fprintf(stderr,"Parsing successful!\n");
 else fprintf(stderr,"Parsing failed\n");
}

int main(int argc, char **argv) {
 if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}
 parse(argv[1]);
 return 0;
}