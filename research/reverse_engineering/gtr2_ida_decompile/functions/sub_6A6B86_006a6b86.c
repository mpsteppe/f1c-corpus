int __thiscall sub_6A6B86(_DWORD *this)
{
  unsigned int i; // eax
  int v3; // edx
  _DWORD *v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // ebx
  int v9; // [esp+4h] [ebp-8h]
  unsigned int j; // [esp+8h] [ebp-4h]

  v9 = sub_6A4BC7(this, this[6], this[3]);
  if ( v9 >= 0 )
  {
    for ( i = 0; i < this[3]; *(_DWORD *)(v3 + 36) = 0 )
    {
      *(_DWORD *)(*(_DWORD *)(this[6] + 4 * i) + 40) = 0;
      v3 = *(_DWORD *)(this[6] + 4 * i++);
    }
    for ( j = 0; j < this[3]; ++j )
    {
      v4 = *(_DWORD **)(this[6] + 4 * j);
      if ( sub_6A2293(*v4 & 0xFFF00000) || v5 == 285212672 )
      {
        v7 = v4[9];
        sub_6BB9A9(v6, v4, 1);
        v4[9] = v7;
      }
    }
  }
  return v9;
}
