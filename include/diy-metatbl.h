#ifndef DIY_METATBL_H
#define DIY_METATBL_H



typedef struct DIY_Metatbl
{
   uint64_t obj_id;
   size_t obj_size;

   struct DIY_Metaroutine *mr_hash;
   struct DIY_Metaroutine *mr_repr;
   struct DIY_Metaroutine *mr_opunary;
   struct DIY_Metaroutine *mr_opbinary;
   struct DIY_Metaroutine *mr_getidx;
   struct DIY_Metaroutine *mr_setidx;
   struct DIY_Metaroutine *mr_deref;
   struct DIY_Metaroutine *mr_addrof;
   struct DIY_Metaroutine *mr_serialize;
   struct DIY_Metaroutine *mr_deserialize;
} DIY_Metatbl;





#endif
