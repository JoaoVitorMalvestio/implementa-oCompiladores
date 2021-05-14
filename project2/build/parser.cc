// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 5 "parser.yy"


/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"

#define yylex driver.scanner_->yylex


#line 50 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"


#include "parser.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 50 "parser.yy"
namespace Tiger {
#line 147 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 169 "parser.yy"
                        {absyn_root = (yystack_[0].value.exp);}
#line 643 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 3:
#line 171 "parser.yy"
             {(yylhs.value.exp)=(yystack_[0].value.exp);}
#line 649 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 4:
#line 172 "parser.yy"
          {(yylhs.value.exp) = NULL;}
#line 655 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 5:
#line 175 "parser.yy"
                   {(yylhs.value.exp) = A_IntExp(EM_tokPos,(yystack_[0].value.integerVal));}
#line 661 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 6:
#line 176 "parser.yy"
                   {(yylhs.value.exp) = A_StringExp(EM_tokPos,(yystack_[0].value.stringVal));}
#line 667 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 7:
#line 177 "parser.yy"
                   {(yylhs.value.exp) = A_VarExp(EM_tokPos,(yystack_[0].value.var));}
#line 673 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 8:
#line 178 "parser.yy"
                   {(yylhs.value.exp) = A_NilExp(EM_tokPos);}
#line 679 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 9:
#line 179 "parser.yy"
                                    {(yylhs.value.exp) = A_SeqExp(EM_tokPos,(yystack_[1].value.explist));}
#line 685 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 10:
#line 180 "parser.yy"
                        {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_plusOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 691 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 11:
#line 181 "parser.yy"
                         {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_minusOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 697 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 12:
#line 182 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_timesOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 703 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 13:
#line 183 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_divideOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 709 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 14:
#line 184 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_eqOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 715 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 15:
#line 185 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_neqOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 721 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 16:
#line 186 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_ltOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 727 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 17:
#line 187 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_leOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 733 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 18:
#line 188 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_gtOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 739 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 19:
#line 189 "parser.yy"
                          {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_geOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 745 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 20:
#line 190 "parser.yy"
                          {(yylhs.value.exp) = A_IfExp(EM_tokPos,(yystack_[2].value.exp),(yystack_[0].value.exp),A_IntExp(EM_tokPos,0));}
#line 751 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 21:
#line 191 "parser.yy"
                          {(yylhs.value.exp) = A_IfExp(EM_tokPos,(yystack_[2].value.exp),A_IntExp(EM_tokPos,1),(yystack_[0].value.exp));}
#line 757 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 22:
#line 192 "parser.yy"
                                    {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_nullcoalesceOp,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 763 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 23:
#line 193 "parser.yy"
                                  {(yylhs.value.exp) = A_OpExp(EM_tokPos,A_minusOp,A_IntExp(EM_tokPos,0),(yystack_[0].value.exp));}
#line 769 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 24:
#line 194 "parser.yy"
                                  {(yylhs.value.exp) = (yystack_[1].value.exp);}
#line 775 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 25:
#line 195 "parser.yy"
                                            {(yylhs.value.exp) = A_CallExp(EM_tokPos,S_Symbol((yystack_[3].value.stringVal)),(yystack_[1].value.explist));}
#line 781 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 26:
#line 196 "parser.yy"
                                    {(yylhs.value.exp) = A_AssignExp(EM_tokPos,(yystack_[2].value.var),(yystack_[0].value.exp));}
#line 787 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 27:
#line 197 "parser.yy"
                                      {(yylhs.value.exp) = A_IfExp(EM_tokPos,(yystack_[2].value.exp),(yystack_[0].value.exp),NULL);}
#line 793 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 28:
#line 198 "parser.yy"
                                     {(yylhs.value.exp) = A_IfExp(EM_tokPos,(yystack_[4].value.exp),(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 799 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 29:
#line 199 "parser.yy"
                                      {(yylhs.value.exp) = A_WhileExp(EM_tokPos,(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 805 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 30:
#line 200 "parser.yy"
                                                   {(yylhs.value.exp) = A_ForExp(EM_tokPos,S_Symbol((yystack_[6].value.stringVal)),(yystack_[4].value.exp),(yystack_[2].value.exp),(yystack_[0].value.exp));}
#line 811 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 31:
#line 201 "parser.yy"
                                           {(yylhs.value.exp) = A_BreakExp(EM_tokPos);}
#line 817 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 32:
#line 202 "parser.yy"
                                           {(yylhs.value.exp) = A_LetExp(EM_tokPos,(yystack_[3].value.declist),(yystack_[1].value.exp));}
#line 823 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 33:
#line 203 "parser.yy"
                                                   {(yylhs.value.exp) = A_RecordExp(EM_tokPos,S_Symbol((yystack_[3].value.stringVal)),(yystack_[1].value.efieldlist));}
#line 829 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 34:
#line 204 "parser.yy"
                                                   {(yylhs.value.exp) = A_ArrayExp(EM_tokPos,S_Symbol((yystack_[5].value.stringVal)),(yystack_[3].value.exp),(yystack_[0].value.exp));}
#line 835 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 35:
#line 207 "parser.yy"
                      {(yylhs.value.var) = A_SimpleVar(EM_tokPos,S_Symbol((yystack_[0].value.stringVal)));}
#line 841 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 36:
#line 208 "parser.yy"
                     {(yylhs.value.var) = (yystack_[0].value.var);}
#line 847 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 37:
#line 211 "parser.yy"
                          {(yylhs.value.var) = (yystack_[0].value.var);}
#line 853 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 38:
#line 212 "parser.yy"
                                     {(yylhs.value.var) = A_FieldVar(EM_tokPos,(yystack_[2].value.var),S_Symbol((yystack_[0].value.stringVal)));}
#line 859 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 39:
#line 213 "parser.yy"
                                        {(yylhs.value.var) = A_SubscriptVar(EM_tokPos,(yystack_[3].value.var),(yystack_[1].value.exp));}
#line 865 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 40:
#line 216 "parser.yy"
                                   {(yylhs.value.var) = A_FieldVar(EM_tokPos,A_SimpleVar(EM_tokPos,S_Symbol((yystack_[2].value.stringVal))),S_Symbol((yystack_[0].value.stringVal)));}
#line 871 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 41:
#line 217 "parser.yy"
                                                     {(yylhs.value.var) = A_SubscriptVar(EM_tokPos,A_SimpleVar(EM_tokPos,S_Symbol((yystack_[3].value.stringVal))),(yystack_[1].value.exp));}
#line 877 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 42:
#line 221 "parser.yy"
                      {(yylhs.value.efieldlist) =(yystack_[0].value.efieldlist);}
#line 883 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 43:
#line 222 "parser.yy"
           {(yylhs.value.efieldlist) = NULL;}
#line 889 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 44:
#line 225 "parser.yy"
                        {(yylhs.value.efieldlist) = A_EfieldList((yystack_[0].value.efield),NULL);}
#line 895 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 45:
#line 226 "parser.yy"
                                      {(yylhs.value.efieldlist) = A_EfieldList((yystack_[2].value.efield),(yystack_[0].value.efieldlist));}
#line 901 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 46:
#line 229 "parser.yy"
                                    {(yylhs.value.efield) = A_Efield(S_Symbol((yystack_[2].value.stringVal)),(yystack_[0].value.exp));}
#line 907 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 47:
#line 232 "parser.yy"
                                               {(yylhs.value.explist) = A_ExpList((yystack_[2].value.exp),(yystack_[0].value.explist));}
#line 913 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 48:
#line 235 "parser.yy"
                                        {(yylhs.value.explist) = A_ExpList((yystack_[0].value.exp),NULL);}
#line 919 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 49:
#line 236 "parser.yy"
                                         {(yylhs.value.explist) = A_ExpList((yystack_[2].value.exp),(yystack_[0].value.explist));}
#line 925 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 50:
#line 240 "parser.yy"
                                  {(yylhs.value.explist) = (yystack_[0].value.explist);}
#line 931 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 51:
#line 241 "parser.yy"
           {(yylhs.value.explist) = NULL;}
#line 937 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 52:
#line 244 "parser.yy"
                         {(yylhs.value.explist) = A_ExpList((yystack_[0].value.exp),NULL);}
#line 943 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 53:
#line 245 "parser.yy"
                                    {(yylhs.value.explist) = A_ExpList((yystack_[2].value.exp),(yystack_[0].value.explist));}
#line 949 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 54:
#line 248 "parser.yy"
                         {(yylhs.value.exp) = A_SeqExp(EM_tokPos,(yystack_[0].value.explist));}
#line 955 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 55:
#line 249 "parser.yy"
          {(yylhs.value.exp) = NULL;}
#line 961 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 56:
#line 253 "parser.yy"
                       {(yylhs.value.declist) = (yystack_[0].value.declist);}
#line 967 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 57:
#line 254 "parser.yy"
          {(yylhs.value.declist) = NULL;}
#line 973 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 58:
#line 257 "parser.yy"
                                 {(yylhs.value.declist) = A_DecList((yystack_[0].value.dec),NULL);}
#line 979 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 59:
#line 258 "parser.yy"
                                          {(yylhs.value.declist) = A_DecList((yystack_[1].value.dec),(yystack_[0].value.declist));}
#line 985 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 60:
#line 261 "parser.yy"
                               {(yylhs.value.dec) = A_TypeDec(EM_tokPos,(yystack_[0].value.nametylist));}
#line 991 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 61:
#line 262 "parser.yy"
                  {(yylhs.value.dec) = (yystack_[0].value.dec);}
#line 997 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 62:
#line 263 "parser.yy"
                  {(yylhs.value.dec) = A_FunctionDec(EM_tokPos,(yystack_[0].value.fundeclist));}
#line 1003 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 63:
#line 266 "parser.yy"
                                {(yylhs.value.nametylist) = A_NametyList((yystack_[0].value.namety),NULL);}
#line 1009 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 64:
#line 267 "parser.yy"
                               {(yylhs.value.nametylist) = A_NametyList((yystack_[1].value.namety),(yystack_[0].value.nametylist));}
#line 1015 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 65:
#line 270 "parser.yy"
                                         {(yylhs.value.namety) = A_Namety(S_Symbol((yystack_[2].value.stringVal)),(yystack_[0].value.ty));}
#line 1021 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 66:
#line 273 "parser.yy"
                      {(yylhs.value.ty) = A_NameTy(EM_tokPos,S_Symbol((yystack_[0].value.stringVal)));}
#line 1027 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 67:
#line 274 "parser.yy"
                                  {(yylhs.value.ty) = A_RecordTy(EM_tokPos,(yystack_[1].value.fieldlist));}
#line 1033 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 68:
#line 275 "parser.yy"
                              {(yylhs.value.ty) = A_ArrayTy(EM_tokPos,S_Symbol((yystack_[0].value.stringVal)));}
#line 1039 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 69:
#line 278 "parser.yy"
                                   {(yylhs.value.fieldlist) = (yystack_[0].value.fieldlist);}
#line 1045 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 70:
#line 279 "parser.yy"
            {(yylhs.value.fieldlist) = NULL;}
#line 1051 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 71:
#line 282 "parser.yy"
                                                     {(yylhs.value.fieldlist) = A_FieldList(A_Field(EM_tokPos,S_Symbol((yystack_[2].value.stringVal)),S_Symbol((yystack_[0].value.stringVal))),NULL);}
#line 1057 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 72:
#line 283 "parser.yy"
                                                               {(yylhs.value.fieldlist) = A_FieldList(A_Field(EM_tokPos,S_Symbol((yystack_[4].value.stringVal)),S_Symbol((yystack_[2].value.stringVal))),(yystack_[0].value.fieldlist));}
#line 1063 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 73:
#line 286 "parser.yy"
                                   {(yylhs.value.dec) = A_VarDec(EM_tokPos,S_Symbol((yystack_[2].value.stringVal)),S_Symbol(""),(yystack_[0].value.exp));}
#line 1069 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 74:
#line 287 "parser.yy"
                                                      {(yylhs.value.dec) = A_VarDec(EM_tokPos,S_Symbol((yystack_[4].value.stringVal)),S_Symbol((yystack_[2].value.stringVal)),(yystack_[0].value.exp));}
#line 1075 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 75:
#line 290 "parser.yy"
                                {(yylhs.value.fundeclist) = A_FundecList((yystack_[0].value.fundec),NULL);}
#line 1081 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 76:
#line 291 "parser.yy"
                               {(yylhs.value.fundeclist) = A_FundecList((yystack_[1].value.fundec),(yystack_[0].value.fundeclist));}
#line 1087 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 77:
#line 294 "parser.yy"
                                                                   {(yylhs.value.fundec) = A_Fundec(EM_tokPos,S_Symbol((yystack_[5].value.stringVal)),(yystack_[3].value.fieldlist),S_Symbol(""),(yystack_[0].value.exp));}
#line 1093 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;

  case 78:
#line 295 "parser.yy"
                                                                              {(yylhs.value.fundec) = A_Fundec(EM_tokPos,S_Symbol((yystack_[7].value.stringVal)),(yystack_[5].value.fieldlist),S_Symbol((yystack_[2].value.stringVal)),(yystack_[0].value.exp));}
#line 1099 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"
    break;


#line 1103 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -65;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      48,   -65,   -38,    48,   -10,   -65,    48,    48,    48,   -65,
     -17,   -65,    19,   -65,   316,   -23,   -11,   -65,   -22,    79,
     -20,   -19,   -18,     9,   -65,   -10,   -65,     4,   -65,   -65,
      18,   120,   -13,     2,   143,     3,   -15,    48,    48,    -8,
     -65,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    -7,    48,    48,    48,     5,
      30,   -28,    48,   -65,   -65,   -65,    48,   -65,    48,   -65,
     -65,   151,    36,   -65,   192,    33,    35,   -65,    46,   -13,
     -13,    21,    21,   361,   339,   369,   369,   369,   369,   369,
     369,   -65,   316,   -65,   215,   239,   262,    28,    27,    29,
      48,   285,   -65,    68,   316,   -65,    48,   -65,    61,    48,
     -65,    -8,   -65,    48,    48,    51,    49,   -65,    65,    28,
     -65,   -65,    42,   316,    48,   -65,   -65,    48,   316,   -65,
     308,   316,    39,   -24,    40,    52,    48,   -65,   316,    48,
      62,    43,    48,   -65,   -65,   316,   316,    28,    54,   316,
     -65,    48,   316
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,    31,     0,     0,    57,     8,     0,     0,     4,     5,
      35,     6,     0,     2,     3,     7,    36,    37,     0,     0,
       0,     0,     0,     0,    56,    58,    60,    63,    61,    62,
      75,     0,    23,     0,     3,     0,     0,    51,     0,    43,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    59,    64,    76,     0,    24,     0,     9,
      40,    52,     0,    50,     0,     0,     0,    42,    44,    12,
      13,    10,    11,    20,    21,    14,    15,    16,    17,    18,
      19,    22,    26,    38,     0,     0,    27,    70,     0,     0,
       0,    48,    54,     0,    29,    47,     0,    25,    41,     0,
      33,     0,    39,     0,     0,     0,     0,    69,     0,    70,
      66,    65,     0,    73,     0,    32,    53,     0,    46,    45,
       0,    28,     0,     0,     0,     0,     0,    49,    34,     0,
      71,     0,     0,    68,    67,    74,    30,     0,     0,    77,
      72,     0,    78
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -65,   -65,    84,     0,   -65,   -65,   -65,   -65,   -12,   -65,
     -65,   -64,   -65,    -5,   -65,   -65,    69,   -65,    71,   -65,
     -65,    -9,   -40,   -65,    78,   -65
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    12,    13,   101,    15,    16,    17,    76,    77,    78,
      35,   102,    72,    73,   103,    23,    24,    25,    26,    27,
     121,   116,   117,    28,    29,    30
  };

  const short
  Parser::yytable_[] =
  {
      14,    99,    20,    19,   105,   141,    31,    32,    34,    18,
      21,    36,    22,   142,    37,   100,    38,    55,    39,    40,
      54,    57,    56,    62,    21,    41,    42,    59,    60,    61,
      20,    53,    70,   118,    67,    69,    97,    71,    74,    75,
      93,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     1,    94,    95,    96,     2,
     137,     3,   119,     4,     5,    53,   104,    98,   107,     6,
     109,   110,     7,   111,   120,   115,   122,   125,   127,     8,
     132,   133,   134,    41,    42,   136,   140,   143,   144,   147,
     148,   151,    33,     9,    63,    10,    11,    58,    64,   129,
     123,   126,    43,    44,    45,    46,    71,   150,    65,   128,
     135,     0,     0,   130,   131,     0,    47,    48,    49,    50,
      51,    52,     0,    53,    41,    42,     0,   138,    66,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,   146,
       0,     0,   149,    43,    44,    45,    46,    41,    42,     0,
       0,   152,     0,     0,     0,    41,    42,    47,    48,    49,
      50,    51,    52,     0,    53,     0,    43,    44,    45,    46,
       0,     0,     0,    68,    43,    44,    45,    46,   106,     0,
      47,    48,    49,    50,    51,    52,     0,    53,    47,    48,
      49,    50,    51,    52,     0,    53,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    41,
      42,     0,     0,     0,     0,     0,   108,     0,     0,    47,
      48,    49,    50,    51,    52,     0,    53,     0,    43,    44,
      45,    46,     0,    41,    42,     0,     0,     0,     0,   112,
       0,     0,    47,    48,    49,    50,    51,    52,   113,    53,
       0,     0,    43,    44,    45,    46,    41,    42,     0,     0,
       0,     0,   114,     0,     0,     0,    47,    48,    49,    50,
      51,    52,     0,    53,     0,    43,    44,    45,    46,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,     0,    53,     0,    43,    44,
      45,    46,    41,    42,     0,   124,   139,     0,     0,     0,
      41,    42,    47,    48,    49,    50,    51,    52,     0,    53,
       0,    43,    44,    45,    46,     0,     0,     0,     0,    43,
      44,    45,    46,    41,    42,    47,    48,    49,    50,    51,
      52,     0,    53,    47,    48,    49,    50,    51,    52,     0,
      53,     0,    43,    44,    45,    41,    42,     0,     0,     0,
       0,     0,     0,    41,    42,     0,    47,    48,    49,    50,
      51,    52,     0,    53,    43,    44,     0,     0,     0,     0,
       0,     0,    43,    44,     0,     0,     0,     0,    47,    48,
      49,    50,    51,    52,     0,    53,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    53
  };

  const short
  Parser::yycheck_[] =
  {
       0,    29,    12,     3,    68,    29,     6,     7,     8,    47,
      20,    28,    22,    37,    31,    43,    33,    28,    35,     0,
      43,    43,    33,    14,    20,     4,     5,    47,    47,    47,
      12,    44,    47,     6,    32,    32,    31,    37,    38,    47,
      47,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     7,    56,    57,    58,    11,
     124,    13,    35,    15,    16,    44,    66,    37,    32,    21,
      37,    36,    24,    27,    47,    47,    47,     9,    17,    31,
      29,    32,    17,     4,     5,    43,    47,    47,    36,    27,
      47,    37,     8,    45,    25,    47,    48,    18,    27,   111,
     100,   106,    23,    24,    25,    26,   106,   147,    30,   109,
     119,    -1,    -1,   113,   114,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,     4,     5,    -1,   127,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,   139,
      -1,    -1,   142,    23,    24,    25,    26,     4,     5,    -1,
      -1,   151,    -1,    -1,    -1,     4,     5,    37,    38,    39,
      40,    41,    42,    -1,    44,    -1,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    23,    24,    25,    26,    27,    -1,
      37,    38,    39,    40,    41,    42,    -1,    44,    37,    38,
      39,    40,    41,    42,    -1,    44,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,     4,
       5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44,    -1,    23,    24,
      25,    26,    -1,     4,     5,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    19,    44,
      -1,    -1,    23,    24,    25,    26,     4,     5,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    -1,    23,    24,    25,    26,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44,    -1,    23,    24,
      25,    26,     4,     5,    -1,    30,     8,    -1,    -1,    -1,
       4,     5,    37,    38,    39,    40,    41,    42,    -1,    44,
      -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,     4,     5,    37,    38,    39,    40,    41,
      42,    -1,    44,    37,    38,    39,    40,    41,    42,    -1,
      44,    -1,    23,    24,    25,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    37,    38,    39,    40,
      41,    42,    -1,    44,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    -1,    44,    37,    38,    39,    40,
      41,    42,    -1,    44
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     7,    11,    13,    15,    16,    21,    24,    31,    45,
      47,    48,    53,    54,    55,    56,    57,    58,    47,    55,
      12,    20,    22,    67,    68,    69,    70,    71,    75,    76,
      77,    55,    55,    54,    55,    62,    28,    31,    33,    35,
       0,     4,     5,    23,    24,    25,    26,    37,    38,    39,
      40,    41,    42,    44,    43,    28,    33,    43,    18,    47,
      47,    47,    14,    68,    70,    76,     8,    32,    30,    32,
      47,    55,    64,    65,    55,    47,    59,    60,    61,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    47,    55,    55,    55,    31,    37,    29,
      43,    55,    63,    66,    55,    63,    27,    32,    34,    37,
      36,    27,    34,    19,    10,    47,    73,    74,     6,    35,
      47,    72,    47,    55,    30,     9,    65,    17,    55,    60,
      55,    55,    29,    32,    17,    73,    43,    63,    55,     8,
      47,    29,    37,    47,    36,    55,    55,    27,    47,    55,
      74,    37,    55
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    70,    70,    71,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     0,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     4,     3,     4,     6,     4,
       8,     1,     5,     4,     6,     1,     1,     1,     3,     4,
       3,     4,     1,     0,     1,     3,     3,     3,     1,     3,
       1,     0,     1,     3,     1,     0,     1,     0,     1,     2,
       1,     1,     1,     1,     2,     4,     1,     3,     3,     1,
       0,     3,     5,     4,     6,     1,     2,     7,     9
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"TIMES\"", "\"DIVIDE\"", "\"ARRAY\"", "\"BREAK\"", "\"DO\"", "\"END\"",
  "\"ELSE\"", "\"FOR\"", "\"FUNCTION\"", "\"IF\"", "\"IN\"", "\"LET\"",
  "\"NIL\"", "\"OF\"", "\"THEN\"", "\"TO\"", "\"TYPE\"", "\"WHILE\"",
  "\"VAR\"", "\"PLUS\"", "\"MINUS\"", "\"AND\"", "\"OR\"", "\"COMMA\"",
  "\".\"", "\":\"", "\";\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"",
  "\"}\"", "\"=\"", "\"<>\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"",
  "\"ASSIGN\"", "\"NULLCOALESCE\"", "\"INTEGER\"", "\"DOUBLE\"",
  "\"IDENTIFIER\"", "\"STRING\"", "LOWER", "LOW", "UMINUS", "$accept",
  "program", "exp_em", "exp", "lvalue", "oneormore", "one", "rec",
  "rec_nonempty", "rec_one", "sequencing", "sequencing_exps", "actuals",
  "nonemptyactuals", "expseq", "decs", "decs_nonempty", "decs_nonempty_s",
  "tydec", "tydec_one", "ty", "tyfields", "tyfields_nonempty", "vardec",
  "fundec", "fundec_one", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   169,   169,   171,   172,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   207,   208,   211,   212,   213,
     216,   217,   221,   222,   225,   226,   229,   232,   235,   236,
     240,   241,   244,   245,   248,   249,   253,   254,   257,   258,
     261,   262,   263,   266,   267,   270,   273,   274,   275,   278,
     279,   282,   283,   286,   287,   290,   291,   294,   295
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
    };
    const int user_token_number_max_ = 306;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 50 "parser.yy"
} // Tiger
#line 1696 "/home/joao.malvestio/git/my/implementacaoCompilador/project2/build/parser.cc"

#line 298 "parser.yy"


namespace Tiger {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
