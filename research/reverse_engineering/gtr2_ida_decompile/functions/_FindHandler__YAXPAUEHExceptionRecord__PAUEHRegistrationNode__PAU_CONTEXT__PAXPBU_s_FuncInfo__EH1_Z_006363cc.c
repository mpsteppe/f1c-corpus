void __usercall FindHandler(
        int a1@<ebx>,
        int a2@<edi>,
        const struct _s_TryBlockMapEntry *a3@<esi>,
        struct EHExceptionRecord *a4,
        struct EHRegistrationNode *a5,
        struct EHRegistrationNode *a6,
        struct _CONTEXT *a7,
        struct _s_FuncInfo *a8,
        unsigned __int8 a9,
        struct _s_FuncInfo *a10,
        struct EHRegistrationNode *a11)
{
  __ehstate_t state; // eax
  struct EHExceptionRecord *v12; // ebx
  unsigned int magicNumber; // eax
  struct EHExceptionRecord *v14; // esi
  unsigned int v15; // eax
  unsigned int v16; // eax
  int v17; // esi
  TryBlockMapEntry *v18; // eax
  int pHandlerArray; // esi
  CatchableTypeArray *pCatchableTypeArray; // ecx
  int *arrayOfCatchableTypes; // edx
  int nCatchableTypes; // ecx
  TryBlockMapEntry *v23; // edi
  const struct _s_CatchableType *v24; // [esp-Ch] [ebp-30h]
  const struct _s_TryBlockMapEntry *v25; // [esp-8h] [ebp-2Ch]
  int v26; // [esp-4h] [ebp-28h]
  struct EHRegistrationNode *v27; // [esp+0h] [ebp-24h]
  unsigned int v28; // [esp+4h] [ebp-20h] BYREF
  int v29; // [esp+8h] [ebp-1Ch]
  int nCatches; // [esp+Ch] [ebp-18h]
  int v31; // [esp+10h] [ebp-14h]
  int *v32; // [esp+14h] [ebp-10h]
  unsigned int v33; // [esp+18h] [ebp-Ch] BYREF
  TryBlockMapEntry *v34; // [esp+1Ch] [ebp-8h]
  char v35; // [esp+23h] [ebp-1h]

  state = a5->state;
  v35 = 0;
  v29 = state;
  if ( state < -1 || state >= a8->maxState )
    sub_635D4C();
  v26 = a1;
  v12 = a4;
  v25 = a3;
  v24 = (const struct _s_CatchableType *)a2;
  if ( a4->ExceptionCode != -529697949 )
    goto LABEL_41;
  a2 = 429065504;
  if ( a4->NumberParameters == 3 )
  {
    magicNumber = a4->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505) && !a4->params.pThrowInfo )
    {
      if ( !*(_DWORD *)(_getptd() + 124) )
        return;
      v14 = *(struct EHExceptionRecord **)(_getptd() + 124);
      a4 = v14;
      a6 = *(struct EHRegistrationNode **)(_getptd() + 128);
      v35 = 1;
      if ( !_ValidateRead(v14, 1u) )
        sub_635D4C();
      if ( v14->ExceptionCode != -529697949 )
      {
        v12 = v14;
LABEL_41:
        if ( a9 )
          terminate();
        FindHandlerForForeignException(
          (const struct _s_CatchableType *)v12,
          (const struct _s_TryBlockMapEntry *)a2,
          v12,
          a5,
          a6,
          a7,
          a8,
          v29,
          a10,
          a11);
        return;
      }
      if ( v14->NumberParameters == 3 )
      {
        v15 = v14->params.magicNumber;
        if ( (v15 == 429065504 || v15 == 429065505) && !v14->params.pThrowInfo )
          sub_635D4C();
      }
      v12 = v14;
    }
  }
  if ( v12->ExceptionCode != -529697949 )
    goto LABEL_41;
  if ( v12->NumberParameters != 3 )
    goto LABEL_41;
  v16 = v12->params.magicNumber;
  if ( v16 != 429065504 && v16 != 429065505 )
    goto LABEL_41;
  v17 = v29;
  v18 = _GetRangeOfTrysToCheck(a8, (int)a10, v29, &v33, &v28);
  v34 = v18;
  if ( v33 < v28 )
  {
    while ( 1 )
    {
      if ( v18->tryLow <= v17 && v17 <= v18->tryHigh )
      {
        pHandlerArray = (int)v18->pHandlerArray;
        nCatches = v18->nCatches;
        if ( nCatches > 0 )
        {
          while ( 1 )
          {
            pCatchableTypeArray = v12->params.pThrowInfo->pCatchableTypeArray;
            arrayOfCatchableTypes = (int *)pCatchableTypeArray->arrayOfCatchableTypes;
            nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
            v32 = arrayOfCatchableTypes;
            v31 = nCatchableTypes;
            if ( nCatchableTypes > 0 )
              break;
LABEL_33:
            --nCatches;
            pHandlerArray += 16;
            if ( nCatches <= 0 )
              goto LABEL_36;
          }
          while ( 1 )
          {
            v27 = (struct EHRegistrationNode *)*v32;
            if ( TypeMatch(*v32, pHandlerArray, (const struct _s_HandlerType *)v12->params.pThrowInfo) )
              break;
            --v31;
            ++v32;
            if ( v31 <= 0 )
            {
              v18 = v34;
              goto LABEL_33;
            }
          }
          v23 = v34;
          CatchIt(v12, a6, a7, a8, a10, (const struct _s_HandlerType *)a11, v24, v25, v26, v27, v28);
          v12 = a4;
          v18 = v23;
        }
      }
LABEL_36:
      ++v33;
      v34 = ++v18;
      if ( v33 >= v28 )
        break;
      v17 = v29;
    }
  }
  if ( a9 )
    __DestructExceptionObject(v12, 1);
}
