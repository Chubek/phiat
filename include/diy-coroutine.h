#ifndef DIY_COROUTINE_H
#define DIY_COROUTINE_H

typedef struct DIY_Coroutine
{
  struct DIY_Object *refobj;
  enum
  {
    CORO_Pending,
    CORO_Running,
    CORO_Paused,
    CORO_Completed,
  } state;

  struct DIY_Stack *stack;
  struct DIY_Object *retval;
  struct DIY_Object *context;
  struct DIY_Object *function;
} DIY_Coroutine;

#endif
