#ifndef DIY_DYNARRAY_H
#define DIY_DYNARRAY_H

#define DIY_DYNARRAY_GROWTH_RATIO 0.85
#define DIY_DYNARRAY_GROWTH_FACTOR 1.6

typedef struct DIY_DynArray
{
  struct DIY_Object **data;
  size_t cap, len;
} DIY_DynArray;

#endif
