#ifndef DIY_OBJECT_H
#define DIY_OBJECT_H

typedef struct DIY_Object
{
  struct DIY_GCHeader gc_header;
  struct DIY_Metatbl metatbl;
  enum
  {
    OBJ_String,
    OBJ_Character,
    OBJ_Symbol,
    OBJ_Closure,
    OBJ_Upvalue,
    OBJ_Tuple,
    OBJ_List,
    OBJ_DynArray,
    OBJ_Hashtbl,
    OBJ_Integer,
    OBJ_Rational,
    OBJ_Real,
    OBJ_Complex,
    OBJ_Coroutine,
    OBJ_Metaroutine,
    OBJ_Coprocess,
    OBJ_CFunction,
    OBJ_CType,
    OBJ_Bundle,
    OBJ_Exception,
    OBJ_Regexp,
    OBJ_Chunk,
    OBJ_StackFrame,
  } type;

  union
  {
    struct DIY_String *as_string;
    struct DIY_Character *as_character;
    struct DIY_Symbol *as_symbol;
    struct DIY_Closure *as_closure;
    struct DIY_Upvalue *as_upvalue;
    struct DIY_Tuple *as_tuple;
    struct DIY_List *as_list;
    struct DIY_Set *as_set;
    struct DIY_DynArray *as_dynarray;
    struct DIY_Hashtbl *as_hashtbl;
    struct DIY_Integer *as_integer;
    struct DIY_Rational *as_rational;
    struct DIY_Real *as_real;
    struct DIY_Complex *as_complex;
    struct DIY_Coroutine *as_coroutine;
    struct DIY_Metaroutine *as_metaroutine;
    struct DIY_Coprocess *as_coprocess;
    struct DIY_CFunction *as_cfunction;
    struct DIY_CType *as_ctype;
    struct DIY_Bundle *as_bundle;
    struct DIY_Exception *as_exception;
    struct DIY_Regexp *as_regexp;
    struct DIY_Chunk *as_chunk;
    struct DIY_StackFrame *as_stackframe;
  };

  struct DIY_Object *next;
} DIY_Object;

#endif
