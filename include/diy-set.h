#ifndef DIY_SET_H
#define DIY_SET_H

typedef struct DIY_Set
{
  struct DIY_Object **values;
  size_t len, cap;
  bool frozen;
} DIY_Set;

#endif
