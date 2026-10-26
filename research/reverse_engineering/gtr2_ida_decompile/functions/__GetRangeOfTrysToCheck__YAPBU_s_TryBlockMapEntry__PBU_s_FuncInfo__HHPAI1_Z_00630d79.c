TryBlockMapEntry *__cdecl _GetRangeOfTrysToCheck(
        const struct _s_FuncInfo *a1,
        int a2,
        int a3,
        unsigned int *a4,
        unsigned int *a5)
{
  unsigned int nTryBlocks; // esi
  TryBlockMapEntry *pTryBlockMap; // ebx
  unsigned int v8; // eax
  TryBlockMapEntry *v9; // eax
  unsigned int v10; // esi
  unsigned int v12; // [esp+Ch] [ebp-4h]
  const struct _s_FuncInfo *v13; // [esp+18h] [ebp+8h]

  nTryBlocks = a1->nTryBlocks;
  pTryBlockMap = a1->pTryBlockMap;
  v8 = nTryBlocks;
  v12 = nTryBlocks;
  v13 = (const struct _s_FuncInfo *)nTryBlocks;
  if ( a2 >= 0 )
  {
    do
    {
      if ( nTryBlocks == -1 )
        sub_635D4C();
      v9 = &pTryBlockMap[--nTryBlocks];
      if ( v9->tryHigh < a3 && a3 <= v9->catchHigh || nTryBlocks == -1 )
      {
        --a2;
        v12 = (unsigned int)v13;
        v13 = (const struct _s_FuncInfo *)nTryBlocks;
      }
    }
    while ( a2 >= 0 );
    v8 = v12;
  }
  v10 = nTryBlocks + 1;
  *a4 = v10;
  *a5 = v8;
  if ( v8 > a1->nTryBlocks || v10 > v8 )
    sub_635D4C();
  return &pTryBlockMap[v10];
}
