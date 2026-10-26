int __thiscall sub_64BEF8(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // edi
  void *v5; // eax
  void *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  unsigned int i; // edi
  void *Block; // [esp+Ch] [ebp-4h]

  v2 = (_DWORD *)this[1];
  v3 = (_DWORD *)*this;
  v4 = v2[26];
  if ( v4 != v3[26] || v2[27] != v3[27] || v2[28] != v3[28] )
    return -2147467259;
  v5 = operator new(16 * v4);
  v6 = v5;
  if ( v5 )
  {
    sub_41D1B0((int)v5, 16, v4, (int)sub_681563);
    Block = v6;
  }
  else
  {
    Block = 0;
  }
  if ( !Block )
    return -2147467259;
  v7 = this[1];
  if ( *(_DWORD *)(v7 + 16) && *(_DWORD *)(*this + 16) )
  {
    *(_DWORD *)(v7 + 16) = 0;
    *(_DWORD *)(*this + 16) = 0;
  }
  v8 = this[1];
  v9 = 0;
  if ( *(_DWORD *)(v8 + 112) )
  {
    v10 = *(_DWORD *)(v8 + 108);
    do
    {
      for ( i = 0; i < v10; ++i )
      {
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)*this + 4))(*this, i, v9, Block);
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(*(_DWORD *)this[1] + 8))(
          this[1],
          i,
          v9,
          Block);
        v10 = *(_DWORD *)(this[1] + 108);
      }
      ++v9;
    }
    while ( v9 < *(_DWORD *)(this[1] + 112) );
  }
  j__free(Block);
  return 0;
}
