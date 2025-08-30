#ifndef DIY_CHUNK_H
#define DIY_CHUNK_H

#define DIY_CHUNK_GROWTH_RATIO 0.90
#define DIY_CHUNK_GROWTH_FACTOR 1.4

typedef struct DIY_Code
{
  uint16_t opcode : 6;
  uint16_t operand1 : 8;
  uint16_t operand2 : : 2;
} DIY_Code;

typedef struct DIY_Chunk
{
  DIY_Code **prog;
  size_t len, cap;
} DIY_Chunk;

#endif
