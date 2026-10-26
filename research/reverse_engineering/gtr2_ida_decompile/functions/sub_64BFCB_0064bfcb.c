int __thiscall sub_64BFCB(_DWORD *this)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  void *v7; // eax
  void *v8; // eax
  int v9; // eax
  unsigned int v10; // ebx
  unsigned int j; // edi
  unsigned int k; // edi
  int v13; // eax
  unsigned int v14; // eax
  unsigned int m; // edi
  unsigned int v16; // [esp+4h] [ebp-14h]
  unsigned int v17; // [esp+8h] [ebp-10h]
  unsigned int v18; // [esp+Ch] [ebp-Ch]
  int v19; // [esp+Ch] [ebp-Ch]
  void *v20; // [esp+Ch] [ebp-Ch]
  void *v21; // [esp+10h] [ebp-8h]
  void *v22; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-8h]
  void *Block; // [esp+14h] [ebp-4h]

  if ( *((_BYTE *)this + 8) != 1 )
    return -2147467259;
  v3 = (_DWORD *)this[1];
  v4 = (_DWORD *)*this;
  v18 = v3[26];
  if ( v18 <= v4[26] )
    v18 = v4[26];
  v16 = v3[27];
  if ( v16 >= v4[27] )
    v16 = v4[27];
  v5 = v4[28];
  v17 = v3[28];
  if ( v17 >= v5 )
    v17 = v5;
  v6 = 16 * v18;
  v7 = operator new(16 * v18);
  v21 = v7;
  if ( v7 )
  {
    sub_41D1B0((int)v7, 16, v18, (int)sub_681563);
    Block = v21;
  }
  else
  {
    Block = 0;
  }
  if ( !Block )
    return -2147467259;
  v19 = *(_DWORD *)(this[1] + 104);
  v8 = operator new(16 * v19);
  v22 = v8;
  if ( v8 )
  {
    sub_41D1B0((int)v8, 16, v19, (int)sub_681563);
    v20 = v22;
  }
  else
  {
    v20 = 0;
  }
  if ( v20 )
  {
    memset(Block, 0, v6);
    memset(v20, 0, 16 * *(_DWORD *)(this[1] + 104));
    v9 = this[1];
    if ( *(_DWORD *)(v9 + 16) && *(_DWORD *)(*this + 16) )
    {
      *(_DWORD *)(v9 + 16) = 0;
      *(_DWORD *)(*this + 16) = 0;
    }
    v10 = v17;
    for ( i = 0; i < v17; v10 = v17 )
    {
      for ( j = 0; j < v16; ++j )
      {
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)*this + 4))(*this, j, i, Block);
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)this[1] + 8))(
          this[1],
          j,
          i,
          Block);
      }
      for ( k = v16; k < *(_DWORD *)(this[1] + 108); ++k )
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)this[1] + 8))(
          this[1],
          k,
          i,
          v20);
      ++i;
    }
    v13 = this[1];
    if ( v10 < *(_DWORD *)(v13 + 112) )
    {
      v14 = *(_DWORD *)(v13 + 108);
      do
      {
        for ( m = 0; m < v14; ++m )
        {
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)this[1] + 8))(
            this[1],
            m,
            v10,
            v20);
          v14 = *(_DWORD *)(this[1] + 108);
        }
        ++v10;
      }
      while ( v10 < *(_DWORD *)(this[1] + 112) );
    }
    j__free(Block);
    j__free(v20);
    return 0;
  }
  else
  {
    j__free(Block);
    return -2147467259;
  }
}
