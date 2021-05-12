#include <stdio.h>
#include "util.hh"
#include "errormsg.hh"
#include <iostream>

using namespace std;

extern int yyparse(void);

void parse(string fname)
{
  EM_reset(fname);
  if (yyparse() == 0) /* parsing worked */
    fprintf(stderr, "Parsing successful!\n");
  else
    fprintf(stderr, "Parsing failed\n");
}