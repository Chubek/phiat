#ifndef PH_METATBL
#define PH_METATBL



typedef struct PH_Metatbl
{
   uint32_t obj_id;
   size_t obj_size;

   struct PH_Metaroutine *mr_hash;
   struct PH_Metaroutine *mr_repr;
   struct PH_Metaroutine *mr_opunary;
   struct PH_Metaroutine *mr_opbinary;
   struct PH_Metaroutine *mr_getidx;
   struct PH_Metaroutine *mr_setidx;
   struct PH_Metaroutine *mr_deref;
   struct PH_Metaroutine *mr_addrof;
   struct PH_Metaroutine *mr_serialize;
   struct PH_Metaroutine *mr_deserialize;
} PH_Metatbl;





#endif
