#ifndef PH_LIST_H
#define PH_LIST_H

typedef struct PH_List
{
  struct PH_Object *head;
  struct PH_Object *tail;
} PH_List;

#endif
