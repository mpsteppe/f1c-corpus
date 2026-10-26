void __thiscall sub_486080(_DWORD *this)
{
  _DWORD *v2; // esi
  void *v3; // edi
  _DWORD *v4; // esi
  void *v5; // edi
  _DWORD *v6; // esi
  void *v7; // edi
  _DWORD *v8; // esi
  void *v9; // edi
  void (__thiscall ***i)(_DWORD, int); // esi
  int v11; // esi
  LPVOID **v12; // ebp
  char v13; // al
  LPVOID *v14; // edi

  v2 = (_DWORD *)this[51];
  while ( v2 )
  {
    v3 = v2;
    v2 = (_DWORD *)v2[6];
    DualConditionalFree(v3);
    FreeWrapper_7bcf(v3);
  }
  v4 = (_DWORD *)this[52];
  while ( v4 )
  {
    v5 = v4;
    v4 = (_DWORD *)v4[6];
    DualConditionalFree(v5);
    FreeWrapper_7bcf(v5);
  }
  v6 = (_DWORD *)this[53];
  while ( v6 )
  {
    v7 = v6;
    v6 = (_DWORD *)v6[6];
    DualConditionalFree(v7);
    FreeWrapper_7bcf(v7);
  }
  v8 = (_DWORD *)this[54];
  while ( v8 )
  {
    v9 = v8;
    v8 = (_DWORD *)v8[6];
    DualConditionalFree(v9);
    FreeWrapper_7bcf(v9);
  }
  for ( i = (void (__thiscall ***)(_DWORD, int))this[36]; i; i = (void (__thiscall ***)(_DWORD, int))this[36] )
  {
    this[36] = StructFieldAccessor(i);
    (**i)(i, 1);
  }
  this[36] = 0;
  v11 = this[21];
  while ( v11 )
  {
    v12 = (LPVOID **)v11;
    v13 = *(_BYTE *)(v11 + 8);
    v11 = *(_DWORD *)(v11 + 4);
    if ( v13 )
    {
      v14 = *v12;
      if ( *v12 )
      {
        if ( *v14 )
          FreeWrapper_7bcf(*v14);
        FreeWrapper_7bcf(v14);
      }
    }
    FreeWrapper_7bcf(v12);
  }
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
}
