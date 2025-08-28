#ifndef PH_OBJECT_H
#define PH_OBJECT_H

typedef struct PH_Object
{
  struct PH_GCHeader gc_header;
  struct PH_Metatbl metatbl;
  enum
  {
    OBJ_String,
    OBJ_Symbol,
    OBJ_Closure,
    OBJ_Upvalue,
    OBJ_Tuple,
    OBJ_List,
    OBJ_Array,
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
  } type;

  union
  {
    struct PH_String *as_string;
    struct PH_Symbol *as_symbol;
    struct PH_Closure *as_closure;
    struct PH_Upvalue *as_upvalue;
    struct PH_Tuple *as_tuple;
    struct PH_List *as_list;
    struct PH_Array *as_array;
    struct PH_Hashtbl *as_hashtbl;
    struct PH_Integer *as_integer;
    struct PH_Rational *as_rational;
    struct PH_Real *as_real;
    struct PH_Complex *as_complex;
    struct PH_Coroutine *as_coroutine;
    struct PH_Metaroutine *as_metaroutine;
    struct PH_Coprocess *as_coprocess;
    struct PH_CFunction *as_cfunction;
    struct PH_CType *as_ctype;
    struct PH_Bundle *as_bundle;
    struct PH_Exception *as_exception;
    struct PH_Regexp *as_regexp;
    struct PH_Chunk *as_chunk;
  };

  struct PH_Object *next;
} PH_Object;

#endif
