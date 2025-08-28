#ifndef PH_STRING
#define PH_STRING

#define PH_STRING_GROWTH_RATION 0.95
#define PH_STRING_GROWTH_FACTOR 1.6

typedef struct PH_String
{
  const char32_t *ubuff;
  size_t len, cap;
  uint32_t hash;
} PH_String;

#endif
