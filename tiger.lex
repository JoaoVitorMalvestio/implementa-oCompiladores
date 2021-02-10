%{
#include <string.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

int commentDepth = 0;

int charPos=1;
#define ADJ (EM_tokPos=charPos, charPos+=yyleng)

int yywrap(void)
{
 charPos=1;
 return 1;
}

%}
/* Lex Definitions */
%x COMMENT STR
%%
" "	 								{ADJ; continue;}
[ \t]	{ADJ; continue;}
(\n|\r\n)  {ADJ; EM_newline(); continue;}
"*"   {ADJ; return TIMES;}
"/"   {ADJ; return DIVIDE;}
"/*"  {ADJ; BEGIN(COMMENT); commentDepth++;}
<COMMENT>{
	"/*" {ADJ; commentDepth++;}
	"*/" {ADJ; if (--commentDepth == 0) BEGIN(INITIAL);}
	[^\n] {ADJ;}
        (\n|\r\n)	{ADJ; /*EM_newline();*/}
}
"array"    {ADJ; return ARRAY;}
"break"    {ADJ; return BREAK;}
"do"	   {ADJ; return DO;}
"end"      {ADJ; return END;}
"else"     {ADJ; return ELSE;}
"for"  	   {ADJ; return FOR;}
"function" {ADJ; return FUNCTION;}
"if"	   {ADJ; return IF;}
"in"       {ADJ; return IN;}
"let"	   {ADJ; return LET;}
"nil"	   {ADJ; return NIL;}
"of"	   {ADJ; return OF;}
"then"     {ADJ; return THEN;}
"to"	   {ADJ; return TO;}
"type"     {ADJ; return TYPE;}
"while"    {ADJ; return WHILE;}
"var"      {ADJ; return VAR;}
"+"        {ADJ; return PLUS;}
"-"        {ADJ; return MINUS;}
"&"	       {ADJ; return AND;}
"|"	       {ADJ; return OR;}
","	       {ADJ; return COMMA;}
"."        {ADJ; return DOT;}
":"	       {ADJ; return COLON;}
";"	       {ADJ; return SEMICOLON;}
"("	       {ADJ; return LPAREN;}
")"        {ADJ; return RPAREN;}
"["        {ADJ; return LBRACK;}
"]"        {ADJ; return RBRACK;}
"{"        {ADJ; return LBRACE;}
"}"        {ADJ; return RBRACE;}
"="        {ADJ; return EQ;}
"<>"       {ADJ; return NEQ;}
"<"        {ADJ; return LT;}
"<="       {ADJ; return LE;}
">"        {ADJ; return GT;}
">="       {ADJ; return GE;}
":="       {ADJ; return ASSIGN;}

\"[^\"]*\"	{ADJ; yylval.sval=String(yytext); return STRING;}
[a-zA-Z][a-zA-Z0-9_]* 	{ADJ; yylval.sval=String(yytext); return ID;}
[0-9]+	 							{ADJ; yylval.ival=atoi(yytext); return INT;}
([0-9]+"."[0-9]*)|([0-9]*"."[0-9]+) {ADJ; yylval.ival=atof(yytext); return REAL;}
.	 								{ADJ; EM_error(EM_tokPos,"illegal token");}

%%
