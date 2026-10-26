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
  unsigned int v9; // esi
  unsigned int v11; // [esp+Ch] [ebp-4h]
  const struct _s_FuncInfo *v12; // [esp+18h] [ebp+8h]

  nTryBlocks = a1->nTryBlocks;
  pTryBlockMap = a1->pTryBlockMap;
  v8 = nTryBlocks;
  v12 = (const struct _s_FuncInfo *)nTryBlocks;
  v11 = nTryBlocks;
  if ( a2 >= 0 )
  {
    do
    {
      if ( nTryBlocks == -1 )
        sub_5CB21D();
      if ( pTryBlockMap[--nTryBlocks].tryHigh < a3 && a3 <= pTryBlockMap[nTryBlocks].catchHigh || nTryBlocks == -1 )
      {
        --a2;
        v11 = (unsigned int)v12;
        v12 = (const struct _s_FuncInfo *)nTryBlocks;
      }
    }
    while ( a2 >= 0 );
    v8 = v11;
  }
  v9 = nTryBlocks + 1;
  *a4 = v9;
  *a5 = v8;
  if ( v8 > a1->nTryBlocks || v9 > v8 )
    sub_5CB21D();
  return &pTryBlockMap[v9];
}
