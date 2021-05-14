#pragma once

#include "parser.hh"

# ifndef YY_DECL
#  define YY_DECL Tiger::Parser::token_type                         \
     Tiger::Scanner::yylex(Tiger::Parser::semantic_type* yylval,    \
                              Tiger::Parser::location_type*,        \
                              Tiger::Driver& driver)
# endif


# ifndef __FLEX_LEXER_H
#  define yyFlexLexer TigerFlexLexer
#  include <FlexLexer.h>
#  undef yyFlexLexer
# endif

namespace Tiger {
  class Scanner : public TigerFlexLexer {
  public:
    Scanner();
    virtual ~Scanner();
    virtual Parser::token_type yylex(Parser::semantic_type* yylval,
				     Parser::location_type* l,
				     Driver& driver);
    void set_debug(bool b);
  };
}

