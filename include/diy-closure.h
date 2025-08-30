#ifndef DIY_CLOSURE_H
#define DIY_CLOSURE_H

typedef struct DIY_Closure
{
  struct DIY_Object *stackframe;
  struct DIY_Object *upvalue;
  struct DIY_Object *locals;
  struct DIY_Object *env;
} DIY_Closure;

#endif
