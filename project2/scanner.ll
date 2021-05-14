%{ /* -*- C++ -*- */

#include "parser.hh"
#include "scanner.hh"
#include "driver.hh"

/*  Defines some macros to update locations */
#define STEP() do {driver.location_->step();} while (0)
#define COL(col) driver.location_->columns(col)
#define LINE(line) do {driver.location_->lines(line);} while (0)
#define YY_USER_ACTION COL(yyleng);

/* import the parser's token type into a local typedef */
typedef Tiger::Parser::token token;
typedef Tiger::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::TOK_EOF

int commentDepth = 0;

%}

/*** Flex Declarations and Options ***/

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug
/* enable c++ scanner class generation */
%option c++
/* we don’t need yywrap */
%option noyywrap
/* you should not expect to be able to use the program interactively */
%option never-interactive
/* provide the global variable yylineno */
%option yylineno
/* do not fabricate input text to be scanned */
%option nounput
/* the manual says "somewhat more optimized" */
%option batch
/* change the name of the scanner class. results in "TigerFlexLexer" */
%option prefix="Tiger"

/*
%option stack
*/

/* Abbreviations.  */

blank   [ \t]+
eol     [\n\r]+

%x COMMENT STR

%%

 /* The following paragraph suffices to track locations accurately. Each time
 yylex is invoked, the begin position is moved onto the end position. */
%{
  STEP();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/

" " {
  continue;
}

"*"   {
  return token::TIMES;
}

"/"   {
  return token::DIVIDE;
}

"/*"  {
  BEGIN(COMMENT); 
  commentDepth++;
}

<COMMENT>{
	"/*" { 
    commentDepth++;
    }

	"*/" {
    if (--commentDepth == 0) 
    BEGIN(INITIAL);
  }

	[^\n] {}
  (\n|\r\n)	{}
}

"array"    {
  return token::ARRAY;
}

"break"    {
  return token::BREAK;
}

"do"       {
  return token::DO;
}

"end"      {
  return token::END;
}

"else"     {
  return token::ELSE;
}

"for"         {
  return token::FOR;
}

"function" {
   return token::FUNCTION;
}

"if" {
   return token::IF;
  }

"in"       {
  return token::IN;
}

"let"       {
  return token::LET;
  }

"nil"       {
  return token::NIL;
  }

"of"       {
  return token::OF;
}

"then"     {
  return token::THEN;
}

"to"       {
  return token::TO;
}

"type"     {
  return token::TYPE;
}

"while"    {
  return token::WHILE;
}

"var"      {
  return token::VAR;
}

"+"        {
  return token::PLUS;
}

"-"        {
  return token::MINUS;
}

"&"           {
  return token::AND;
}

"|"           {
  return token::OR;
}

","           {
  return token::COMMA;
}

"."        {
  return token::DOT;
}

":"	       {
  return token::COLON;
}

";"	       { 
  return token::SEMICOLON;
  }

"("	       { 
  return token::LPAREN;
  }

")"        { 
  return token::RPAREN;
  }

"["        { 
  return token::LBRACK;
  }

"]"        { 
  return token::RBRACK;
  }

"{"        { 
  return token::LBRACE;
  }

"}"        { 
  return token::RBRACE;
  }

"="        { 
  return token::EQ;
  }

"<>"       { 
  return token::NEQ;
  }

"<"        { 
  return token::LT;
  }

"<="       { 
  return token::LE;
  }

">"        { 
  return token::GT; 
  }

">="       { 
  return token::GE; 
  }

":=" {
  return token::ASSIGN;
}

"??" { 
  return token::NULLCOALESCE; 
}

[0-9]+ {
     yylval->integerVal = atoi(yytext);
     return token::INTEGER;
 }

[0-9]+"."[0-9]* {
  yylval->doubleVal = atof(yytext);
  return token::DOUBLE;
}

\"[^\"]*\" {yylval->stringVal=new std::string(yytext, yyleng); return token::STRING;}

[A-Za-z][A-Za-z0-9_,.-]* {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IDENTIFIER;
}





{blank} { STEP(); }

{eol}  { LINE(yyleng); }

.             {
                std::cerr << *driver.location_ << " Unexpected token : "
                                              << *yytext << std::endl;
                driver.error_ = (driver.error_ == 127 ? 127
                                : driver.error_ + 1);
                STEP ();
              }

%%

/* CUSTOM C++ CODE */

namespace Tiger {

  Scanner::Scanner() : TigerFlexLexer() {}

  Scanner::~Scanner() {}

  void Scanner::set_debug(bool b) {
    yy_flex_debug = b;
  }
}

#ifdef yylex
# undef yylex
#endif

int TigerFlexLexer::yylex()
{
  std::cerr << "call parsepitFlexLexer::yylex()!" << std::endl;
  return 0;
}
