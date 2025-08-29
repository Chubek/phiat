#ifndef DIY_SYMTBL_H
#define DIY_SYMTBL_H

#define DIY_HASHTBL_GROWTH_RATIO 0.85
#define DIY_HASHTBL_GROWTH_FACTOR 2

typedef struct DIY_Entry
{
  const struct DIY_Object *key;
  struct DIY_Object *value;
} DIY_Entry;

typedef struct DIY_Hashtbl
{
  DIY_Entry *entries;
  bool *occupied;
  size_t len, cap;
} DIY_Hashtbl;

static inline uint64_t
diy_robinhood_hash (uint64_t x)
{
  x ^= x >> 30;
  x *= 0xbf58476d1ce4e5b9ULL;
  x ^= x >> 27;
  x *= 0x94d049bb133111ebULL;
  x ^= x >> 31;
  return x;
}

#endif
