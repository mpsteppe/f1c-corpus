int __thiscall sub_415C40(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  char v4; // al
  int v5; // edi
  _DWORD *v6; // eax
  int v7; // esi
  _DWORD *v8; // edi
  int v9; // ebp
  _DWORD *v10; // edi
  int v11; // ebp
  int v12; // eax
  int v13; // esi
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]

  v2 = this[8];
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 && *v3 )
      ShortComputation_8cf0(1);
    FreeWrapper_7bcf(v3);
  }
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  v17 = dword_8AC488;
  if ( dword_8AC488 <= 0 )
    return 1;
  v5 = 0;
  v16 = 0;
  v15 = 0;
  do
  {
    v6 = (_DWORD *)OperatorNewNhMallocWrapper(92);
    v7 = (int)v6;
    if ( v6 )
    {
      *v6 = 0;
      v6[1] = -1;
      v8 = v6 + 3;
      v9 = 2;
      do
      {
        SmallEntryStructInit(v8);
        v8 += 5;
        --v9;
      }
      while ( v9 );
      v10 = (_DWORD *)(v7 + 52);
      v11 = 2;
      do
      {
        SmallEntryStructInit(v10);
        v10 += 5;
        --v11;
      }
      while ( v11 );
      TextFormatStructInitializer_4fe0(v7);
      v5 = v16;
    }
    else
    {
      v7 = 0;
    }
    StringCopyWithBufferRealloc(v15 + dword_8AC490 + 260);
    *(_DWORD *)(v7 + 8) = v5;
    CommentaryTVPWSPathBuilder((const char **)v7);
    v12 = OperatorNewNhMallocWrapper(12);
    if ( v12 )
    {
      *(_DWORD *)v12 = v7;
      *(_DWORD *)(v12 + 4) = 0;
      *(_BYTE *)(v12 + 8) = 1;
    }
    else
    {
      v12 = 0;
    }
    if ( this[8] )
    {
      *(_DWORD *)(this[9] + 4) = v12;
    }
    else
    {
      this[8] = v12;
      this[10] = v12;
    }
    v13 = this[11] + 1;
    this[9] = v12;
    ++v5;
    this[11] = v13;
    v16 = v5;
    v15 += 396;
  }
  while ( v5 < v17 );
  return 0;
}
