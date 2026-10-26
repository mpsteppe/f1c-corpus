void __cdecl FindHandlerForForeignException(
        EXCEPTION_RECORD *ExceptionRecord,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        void *a4,
        const struct _s_FuncInfo *a5,
        __ehstate_t a6,
        int a7,
        struct EHRegistrationNode *TargetFrame)
{
  const struct _s_TryBlockMapEntry *v8; // esi
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // [esp+8h] [ebp-8h] BYREF
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF

  if ( !_getptd()[26]
    || !_CallSETranslator((struct EHExceptionRecord *)ExceptionRecord, a2, a3, a4, a5, a7, TargetFrame) )
  {
    v8 = (const struct _s_TryBlockMapEntry *)_GetRangeOfTrysToCheck(a5, a7, a6, &v12, &v11);
    while ( v12 < v11 )
    {
      if ( a6 >= v8->tryLow && a6 <= v8->tryHigh )
      {
        v9 = (int)&v8->pHandlerArray[v8->nCatches];
        v10 = *(_DWORD *)(v9 - 12);
        if ( !v10 || !*(_BYTE *)(v10 + 8) )
          CatchIt(ExceptionRecord, a2, a3, a4, a5, (const struct _s_HandlerType *)(v9 - 16), 0, v8, a7, TargetFrame, 1u);
      }
      ++v12;
      ++v8;
    }
  }
}
