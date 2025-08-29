#ifndef DIY_STRING_H
#define DIY_STRING_H

#define DIY_STRING_GROWTH_RATION 0.95
#define DIY_STRING_GROWTH_FACTOR 1.6

typedef struct DIY_String
{
  const char32_t *ubuff;
  size_t len, cap;
  uint32_t hash;
} DIY_String;

#endif
