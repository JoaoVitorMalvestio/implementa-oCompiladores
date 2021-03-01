typedef union  {
	int pos;
	int ival;
	string sval;
	double fval;
	} YYSTYPE;
extern YYSTYPE yylval;

# define ID 258
# define STRING 259
# define INT 260
# define COMMA 261
# define COLON 262
# define SEMICOLON 263
# define LPAREN 264
# define RPAREN 265
# define LBRACK 266
# define RBRACK 267
# define LBRACE 268
# define RBRACE 269
# define DOT 270
# define PLUS 271
# define MINUS 272
# define TIMES 273
# define DIVIDE 274
# define EQ 275
# define NEQ 276
# define LT 277
# define LE 278
# define GT 279
# define GE 280
# define AND 281
# define OR 282
# define ASSIGN 283
# define ARRAY 284
# define IF 285
# define THEN 286
# define ELSE 287
# define WHILE 288
# define FOR 289
# define TO 290
# define LET 291
# define IN 292
# define END 293
# define OF 294
# define BREAK 295
# define NIL 296
# define FUNCTION 297
# define VAR 298
# define TYPE 299
# define DO 300
# define REAL 301
# define NULLCOALESCE 302

