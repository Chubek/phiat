#ifndef PH_SYMTBL
#define PH_SYMTBL

#define PH_SYMTBL_GROWTH_RATIO 0.85
#define PH_SYMTBL_GROWTH_FACTOR 2

typedef struct PH_Entry
{
  strict PH_Object *key;
  struct PH_Object *value;
} PH_Entry;

typedef struct PH_Hashtbl
{
  PH_Entry *entries;
  bool *occupied;
  size_t len, cap;
} PH_Hashtbl;

static inline uint64_t
ph_robinhood_hash (uint64_t x)
{
  x ^= x >> 30;
  x *= 0xbf58476d1ce4e5b9ULL;
  x ^= x >> 27;
  x *= 0x94d049bb133111ebULL;
  x ^= x >> 31;
  return x;
}

#endif
