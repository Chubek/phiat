#ifndef DIY_LIST_H
#define DIY_LIST_H

typedef struct DIY_List
{
  struct DIY_Object *head;
  struct DIY_Object *tail;
} DIY_List;

#endif
