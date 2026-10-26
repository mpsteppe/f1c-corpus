int __thiscall sub_4D7660(int *this)
{
  int v2; // eax
  const char *v3; // ecx
  int v4; // edi
  const char *v5; // eax
  int v6; // esi
  int *v7; // eax
  _DWORD *v8; // ebp
  _DWORD *v9; // edi
  bool v10; // zf
  const char *v11; // eax
  int v12; // esi
  const char *v13; // edx
  const char *v14; // ecx
  _DWORD *v15; // ecx
  int result; // eax
  int v17; // [esp+Ch] [ebp-204h]
  char v18[512]; // [esp+10h] [ebp-200h] BYREF

  TextureSurfaceDestroyer(this);
  v2 = FPUControlWordMaskExtract(512);
  v3 = (const char *)dword_5EC428;
  v4 = v2;
  v17 = v2;
  if ( !dword_5EC428 )
    v3 = byte_5EA438;
  v5 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v5 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v18, "%s%s", v5, v3);
  sub_565F80(aTbc, 1, (int)v18, 1);
  v6 = ShortComputation_5f70(&dword_8AD3B0);
  *this = v6;
  v7 = (int *)OperatorNewNhMallocWrapper(36 * v6 + 4);
  if ( v7 )
  {
    v8 = v7 + 1;
    *v7 = v6;
    v9 = v7 + 1;
    if ( v6 - 1 >= 0 )
    {
      do
      {
        StructInitWithSentinels(v9);
        v9 += 9;
        --v6;
      }
      while ( v6 );
    }
    v4 = v17;
  }
  else
  {
    v8 = 0;
  }
  v10 = *this == 0;
  this[1] = (int)v8;
  if ( (v10 || !v8) && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 1025) )
    DebugLogWrite(&dword_8AD25C, aNoTireBrandsTb);
  LinkedListPopFront_5f50(&dword_8AD3B0);
  v11 = (const char *)DirectoryEntryIterator(&dword_8AD3B0);
  if ( v11 )
  {
    v12 = 0;
    do
    {
      v13 = (const char *)dword_5EC428;
      if ( !dword_5EC428 )
        v13 = byte_5EA438;
      v14 = (const char *)dword_5EC3D8;
      if ( !dword_5EC3D8 )
        v14 = byte_5EA438;
      StringFormatWithBufferOverflowCheck(v18, "%s%s%s", v14, v13, v11);
      v15 = (_DWORD *)(v12 + this[1]);
      v12 += 36;
      TireBrandFileParser(v15, v18);
      if ( !(unsigned __int8)LinkedListNodePeek(&dword_8AD3B0) )
        break;
      v11 = (const char *)DirectoryEntryIterator(&dword_8AD3B0);
    }
    while ( v11 );
  }
  result = sub_565EB0(&dword_8AD3B0);
  if ( v4 != 512 )
    return EmptyStub_7780(v4);
  return result;
}

