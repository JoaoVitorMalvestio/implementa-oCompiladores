#include <stdio.h>
#include "util.hpp"
#include "symbol.hpp"
#include "absyn.hpp"
#include "types.h"

typedef struct E_enventry_ *E_enventry;

enum Kind {
	E_varEntry,
	E_funEntry
};
struct E_enventry_ {
	Kind kind;
	union {
		struct {
			Ty_ty ty; 
		} var;
		struct {
			Ty_tyList formals;
			Ty_ty result;
		} fun;
	} u;
};

E_enventry E_VarEntry(Ty_ty ty);
E_enventry E_FunEntry(Ty_tyList formals, Ty_ty result);

S_table E_base_tenv(void);  /*Ty_ty environment */
S_table E_base_venv(void);  /*E_enventry environment */
