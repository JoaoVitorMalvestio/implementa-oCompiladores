%{
#include <string.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

int charPos=1;
#define ADJ (EM_tokPos=charPos, charPos+=yyleng)

int yywrap(void)
{
 charPos=1;
 return 1;
}


void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}
/* Lex Definitions */
digits	[0-9]+
%%
if 	 	{ADJ; return IF;}
[a-z][a-z0-9]* 	{
			ADJ; yylval.sval=String(yytext);
			return ID;
		}
({digits}"."[0-9]*)|([0-9]*"."{digits}) {
			ADJ;
			yylval.fval=atof(yytext);
			return REAL;
		}
" "	 	{adjust(); continue;}
\n	 	{adjust(); EM_newline(); continue;}
","	 	{adjust(); return COMMA;}
for      	{adjust(); return FOR;}
[0-9]+	 	{adjust(); yylval.ival=atoi(yytext); return INT;}
.	 	{adjust(); EM_error(EM_tokPos,"illegal token");}

%%
