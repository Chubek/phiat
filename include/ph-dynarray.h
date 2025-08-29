#ifndef PH_DYNARRAY_H
#define PH_DYNARRAY_H

#define PH_DYNARRAY_GROWTH_RATIO 0.85
#define PH_DYNARRAY_GROWTH_FACTOR 1.6

typedef struct PH_DynArray
{
  struct PH_Object **data;
  size_t cap, len;
} PH_DynArray;

#endif
