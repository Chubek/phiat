#ifndef DIY_STACKFRAME_H
#define DIY_STACKFRAME_H

typedef struct DIY_StackFrame
{
  size_t static_ptr;
  size_t dynamic_ptr;
  size_t frame_ptr;
  size_t nlocals;
} DIY_StackFrame;

#endif
