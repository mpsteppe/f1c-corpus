void __cdecl FindHandler(
        struct EHExceptionRecord *ExceptionRecord,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        void *a4,
        const struct _s_FuncInfo *a5,
        char a6,
        int a7,
        struct EHRegistrationNode *TargetFrame)
{
  struct EHExceptionRecord *v8; // esi
  int v9; // edi
  const struct _s_TryBlockMapEntry *v10; // ebx
  CatchableTypeArray *pCatchableTypeArray; // eax
  const struct _s_CatchableType **arrayOfCatchableTypes; // edi
  unsigned int v13; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 v14[4]; // [esp+4h] [ebp-14h]
  int state; // [esp+8h] [ebp-10h]
  int nCatches; // [esp+Ch] [ebp-Ch]
  int nCatchableTypes; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h] BYREF
  const struct _s_HandlerType *ExceptionRecorda; // [esp+20h] [ebp+8h]

  v14[0] = 0;
  state = a2->state;
  if ( state < -1 || state >= a5->maxState )
    sub_5CB21D();
  v8 = ExceptionRecord;
  if ( ExceptionRecord->ExceptionCode != -529697949 )
    goto LABEL_35;
  if ( ExceptionRecord->NumberParameters == 3
    && ExceptionRecord->params.magicNumber == 429065504
    && !ExceptionRecord->params.pThrowInfo )
  {
    if ( !_getptd()[27] )
      return;
    v8 = (struct EHExceptionRecord *)_getptd()[27];
    a3 = (struct _CONTEXT *)_getptd()[28];
    v14[0] = 1;
    if ( !_ValidateRead(v8, 1u) )
      sub_5CB21D();
    if ( v8->ExceptionCode != -529697949 )
      goto LABEL_35;
    if ( v8->NumberParameters == 3 && v8->params.magicNumber == 429065504 && !v8->params.pThrowInfo )
      sub_5CB21D();
  }
  if ( v8->ExceptionCode != -529697949 || v8->NumberParameters != 3 || v8->params.magicNumber != 429065504 )
  {
LABEL_35:
    if ( a6 )
      terminate();
    FindHandlerForForeignException(v8, a2, a3, a4, a5, state, a7, TargetFrame);
    return;
  }
  v9 = state;
  v10 = (const struct _s_TryBlockMapEntry *)_GetRangeOfTrysToCheck(a5, a7, state, &v18, &v13);
  while ( v18 < v13 )
  {
    if ( v10->tryLow <= v9 && v9 <= v10->tryHigh )
    {
      ExceptionRecorda = (const struct _s_HandlerType *)v10->pHandlerArray;
      nCatches = v10->nCatches;
      if ( nCatches > 0 )
      {
        while ( 1 )
        {
          pCatchableTypeArray = v8->params.pThrowInfo->pCatchableTypeArray;
          arrayOfCatchableTypes = (const struct _s_CatchableType **)pCatchableTypeArray->arrayOfCatchableTypes;
          nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
          if ( nCatchableTypes > 0 )
            break;
LABEL_27:
          --nCatches;
          ++ExceptionRecorda;
          if ( nCatches <= 0 )
            goto LABEL_30;
        }
        while ( !TypeMatch(ExceptionRecorda, *arrayOfCatchableTypes, v8->params.pThrowInfo) )
        {
          --nCatchableTypes;
          ++arrayOfCatchableTypes;
          if ( nCatchableTypes <= 0 )
            goto LABEL_27;
        }
        CatchIt(
          (PEXCEPTION_RECORD)v8,
          a2,
          a3,
          a4,
          a5,
          ExceptionRecorda,
          *arrayOfCatchableTypes,
          v10,
          a7,
          TargetFrame,
          v14[0]);
      }
LABEL_30:
      v9 = state;
    }
    ++v18;
    ++v10;
  }
  if ( a6 )
    unknown_libname_184(v8, 1);
}
