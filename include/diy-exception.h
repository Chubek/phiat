#ifndef DIY_EXCEPTION_H
#define DIY_EXCEPTION_H

#include <setjmp.h>

typedef struct DIY_Exception
{
  struct DIY_Object *msg;
  jmp_buf ctx;
} DIY_Exception;

#endif
