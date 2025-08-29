#ifndef PH_SYMTBL_H
#define PH_SYMTBL_H

typedef struct PH_Variable
{
  const struct PH_Symbol *name;
  struct PH_Object *value;
  bool constt, local, staticc, mut, buried;
  struct PH_Variable *next;
} PH_Variable;

typedef struct PH_Scope
{
  int nesting;
  struct PH_Variable *vars, *tail;
} PH_Scope;

typedef struct PH_Symtbl
{
  PH_Scope *scopes;
  size_t len, cap;
  size_t curr_scope;
} PH_Symtbl;

#endif
