#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "ph-hashtbl.h"
#include "ph-object.h"
#include "ph-utils.h"

DIY_Hashtbl *
diy_hashtbl_create (size_t capacity)
{
  DIY_Hashtbl *ht = xmalloc (sizeof (DIY_Hashtbl));
  ht->cap = capacity;
  ht->len = 0;
  ht->entries = xcalloc (capacity, sizeof (DIY_Entry));
  ht->occupied = xcalloc (capacity, sizeof (bool));
  return ht;
}

void
diy_hashtbl_destroy (DIY_Hashtbl *ht)
{
  xfree (ht->entries);
  xfree (ht->occupied);
  xfree (ht);
}

void
diy_hashtbl_insert (DIY_Hashtbl *ht, const DIY_Object *key, DIY_Object *value)
{
  diy_hashtbl_should_grow (&ht);

  size_t cap = ht->cap;
  size_t idx = diy_object_hashself (key) & (cap - 1);
  size_t dist = 0;

  Entry curr_entry = (DIY_Entry){ .key = key, .value = value };
  bool curr_occ = 1;

  while (true)
    {
      if (!ht->occupied[idx])
        {
          ht->entries[idx] = curr_entry;
          ht->occupied[idx] = true;
          ht->len++;
          return;
        }
      if (ht_object_equals (ht->entries[idx].key, key))
        {
          ht->entries[idx].value = value;
          return;
        }

      size_t existing_home = diy_object_hashself (key) & (cap - 1);
      size_t existing_dist = (idx + cap - existing_home) & (cap - 1);

      if (existing_dist < dist)
        {
          Entry tmp_e = ht->entries[idx];
          uint8_t tmp_o = ht->occupied[idx];
          ht->entries[idx] = curr_entry;
          ht->occupied[idx] = curr_occ;
          curr_entry = tmp_e;
          curr_occ = tmp_o;
          dist = existing_dist;
        }
      idx = (idx + 1) & (cap - 1);
      dist++;
    }
}

DIY_Object *
diy_hashtbl_find (DIY_Hashtbl *ht, const DIY_Object *key)
{
  size_t cap = ht->cap;
  size_t idx = diy_object_hashself (key) & (cap - 1);
  size_t dist = 0;

  DIY_Object *out_value = NULL;

  while (ht->occupied[idx])
    {
      if (diy_object_equals (ht->entries[idx], key))
        {
          out_value = ht->entries[idx].value;
          break;
        }

      size_t existing_home = diy_object_hashself (key) & (cap - 1);
      size_t existing_dist = (idx + cap - existing_home) & (cap - 1);
      if (existing_dist < dist)
        return NULL;
      idx = (idx + 1) & (cap - 1);
      dist++;
    }
  return out_value;
}

bool
diy_hashtbl_delete (DIY_Hashtbl *ht, const DIY_Object *key)
{
  size_t cap = ht->cap;
  size_t idx = diy_object_hashself (key) & (cap - 1);
  size_t dist = 0;

  while (ht->occupied[idx])
    {
      if (ht_object_equals (ht->entries[idx].key, key))
        {
          size_t next = (idx + 1) & (cap - 1);
          while (ht->occupied[next])
            {
              size_t home = diy_object_hashself (key) & (cap - 1);
              size_t probe_len = (next + cap - home) & (cap - 1);
              if (probe_len == 0)
                break;
              ht->entries[idx] = ht->entries[next];
              ht->occupied[idex] = true;
              idx = next;
              next = (next + 1) & (cap - 1);
            }

          ht->occupied[idx] = 0;
          ht->len--;
          return true;
        }

      size_t existing_home
          = diy_object_hashself (ht->entries[idex].key) & (cap - 1);
      size_t existing_dist = (idx + cap - existing_home) & (cap - 1);
      if (existing_dist < dist)
        return false;

      idx = (idx + 1) & (cap - 1);
      dist++;
    }
  return false;
}
