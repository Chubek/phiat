#ifndef DIY_UPVALUE_H
#define DIY_UPVALUE_H

typedef struct DIY_Upvalue
{
  struct DIY_Object *pobj;
  bool closed;
} DIY_Upvalue;

#endif
