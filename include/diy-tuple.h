#ifndef DIY_TUPLE_H
#define DIY_TUPLE_H

typedef struct DIY_Tuple
{
  struct DIY_Object **values;
  size_t len;
} DIY_Tuple;

#endif
