void __usercall FindHandlerForForeignException(
        const struct _s_CatchableType *a1@<ebx>,
        const struct _s_TryBlockMapEntry *a2@<edi>,
        struct EHExceptionRecord *a3,
        struct EHRegistrationNode *a4,
        struct EHRegistrationNode *a5,
        struct _CONTEXT *a6,
        struct _s_FuncInfo *a7,
        int a8,
        struct _s_FuncInfo *a9,
        struct EHRegistrationNode *a10)
{
  int v10; // esi
  TryBlockMapEntry *v11; // edi
  int v12; // ecx
  const struct _s_CatchableType *v13; // [esp-8h] [ebp-14h]
  const struct _s_TryBlockMapEntry *v14; // [esp-4h] [ebp-10h]
  int v15; // [esp+0h] [ebp-Ch]
  unsigned int v16; // [esp+4h] [ebp-8h] BYREF
  unsigned int v17; // [esp+8h] [ebp-4h] BYREF

  if ( a3->ExceptionCode != -2147483645
    && (!*(_DWORD *)(_getptd() + 116) || !_CallSETranslator(a3, a4, a5, a6, a7, (int)a9, a10)) )
  {
    v10 = a8;
    v14 = a2;
    v11 = _GetRangeOfTrysToCheck(a7, (int)a9, a8, &v17, &v16);
    if ( v17 < v16 )
    {
      v13 = a1;
      do
      {
        if ( v10 >= v11->tryLow && v10 <= v11->tryHigh )
        {
          v12 = *((_DWORD *)v11->pHandlerArray + 4 * v11->nCatches - 3);
          if ( !v12 || !*(_BYTE *)(v12 + 8) )
          {
            CatchIt(
              a3,
              a5,
              a6,
              a7,
              a9,
              (const struct _s_HandlerType *)a10,
              v13,
              v14,
              v15,
              (struct EHRegistrationNode *)v16,
              v17);
            v10 = a8;
          }
        }
        ++v17;
        ++v11;
      }
      while ( v17 < v16 );
    }
  }
}
