#ifndef PH_ARRAY
#define PH_ARRAY

#define PH_ARRAY_GROWTH_RATIO 0.85
#define PH_ARRAY_GROWTH_FACTOR 1.6

typedef struct PH_Array
{
  struct PH_Object **data;
  size_t cap, len;
} PH_Array;

#endif
