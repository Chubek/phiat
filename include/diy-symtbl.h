#ifndef DIY_SYMTBL_H
#define DIY_SYMTBL_H

typedef struct DIY_Variable
{
  const struct DIY_Symbol *name;
  struct DIY_Object *value;
  bool constt, local, staticc, mut, buried;
  struct DIY_Variable *next;
} DIY_Variable;

typedef struct DIY_Scope
{
  int nesting;
  struct DIY_Variable *vars, *tail;
} DIY_Scope;

typedef struct DIY_Symtbl
{
  DIY_Scope *scopes;
  size_t len, cap;
  size_t curr_scope;
} DIY_Symtbl;

#endif
