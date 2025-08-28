#ifndef PH_LIST
#define PH_LIST

typedef struct PH_List
{
  struct PH_Object *head;
  struct PH_Object *tail;
} PH_List;

#endif
