int __thiscall sub_415780(int *this)
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

  v2 = *this;
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 && *v3 )
      StructDestructor(1);
    FreeWrapper_7bcf(v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v17 = dword_8AC390;
  if ( dword_8AC390 <= 0 )
    return 1;
  v5 = 0;
  v16 = 0;
  v15 = 0;
  do
  {
    v6 = (_DWORD *)OperatorNewNhMallocWrapper(176);
    v7 = (int)v6;
    if ( v6 )
    {
      *v6 = 0;
      v6[1] = -1;
      v8 = v6 + 4;
      v9 = 2;
      do
      {
        SmallEntryStructInit(v8);
        v8 += 5;
        --v9;
      }
      while ( v9 );
      v10 = (_DWORD *)(v7 + 56);
      v11 = 2;
      do
      {
        SmallEntryStructInit(v10);
        v10 += 5;
        --v11;
      }
      while ( v11 );
      sub_401000(v7 + 96, 20, 2, (int (__thiscall *)(int))SmallEntryStructInit);
      sub_401000(v7 + 136, 20, 2, (int (__thiscall *)(int))SmallEntryStructInit);
      TextFormatStructInitializer(v7);
      v5 = v16;
    }
    else
    {
      v7 = 0;
    }
    StringCopyWithBufferRealloc(v15 + dword_8AC394 + 188);
    *(_DWORD *)(v7 + 8) = v5;
    sub_414600((const char **)v7, 0);
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
    if ( *this )
    {
      *(_DWORD *)(this[1] + 4) = v12;
    }
    else
    {
      *this = v12;
      this[2] = v12;
    }
    v13 = this[3] + 1;
    this[1] = v12;
    ++v5;
    this[3] = v13;
    v16 = v5;
    v15 += 1060;
  }
  while ( v5 < v17 );
  return 0;
}
