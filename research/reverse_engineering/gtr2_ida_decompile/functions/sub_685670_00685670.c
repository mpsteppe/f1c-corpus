int __thiscall sub_685670(_DWORD *this, int a2, int a3, int a4)
{
  unsigned int i; // edx
  int v5; // eax
  unsigned int j; // edi
  int v7; // edx
  int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // edi
  int v11; // esi
  _DWORD *v12; // eax
  int v13; // edx
  int v14; // eax
  _DWORD *v15; // edx
  int k; // [esp+Ch] [ebp-8h]
  unsigned int m; // [esp+10h] [ebp-4h]

  for ( i = 0; i < this[1]; ++i )
  {
    v5 = *(_DWORD *)(this[4] + 4 * i);
    if ( (a3 & *(_DWORD *)(v5 + 4)) == a3 && (*(_DWORD *)(v5 + 4) & a4) == 0 )
      *(_DWORD *)(v5 + 8) = 0;
  }
  for ( j = 0; j < this[2]; ++j )
  {
    v7 = *(_DWORD *)(this[5] + 4 * j);
    v8 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(v7 + 4));
    if ( (a3 & *(_DWORD *)(v8 + 4)) == a3 && (*(_DWORD *)(v8 + 4) & a4) == 0 )
    {
      v9 = *(_DWORD *)(v7 + 12) + 1;
      if ( *(_DWORD *)(v8 + 8) <= v9 )
        *(_DWORD *)(v8 + 8) = v9;
    }
  }
  v10 = 0;
  v11 = 0;
  for ( k = 0; v10 < this[1]; ++v10 )
  {
    v12 = *(_DWORD **)(this[4] + 4 * v10);
    v13 = v12[1];
    if ( (a3 & v13) == a3 && (v13 & a4) == 0 )
    {
      v12[4] = v11;
      v12[6] = a2;
      if ( (v13 & 0x400) != 0 )
        k = 1;
      v11 += v12[2];
      v12[2] = 0;
    }
  }
  for ( m = 0; m < this[2]; ++m )
  {
    v14 = *(_DWORD *)(this[5] + 4 * m);
    v15 = *(_DWORD **)(this[4] + 4 * *(_DWORD *)(v14 + 4));
    if ( (a3 & v15[1]) == a3 && (v15[1] & a4) == 0 )
    {
      *(_DWORD *)(v14 + 4) = v15[6];
      *(_DWORD *)(v14 + 12) += v15[4];
    }
  }
  *(_DWORD *)(*(_DWORD *)(4 * a2 + this[4]) + 8) = v11;
  if ( k )
    *(_BYTE *)(*(_DWORD *)(4 * a2 + this[4]) + 5) |= 4u;
  return 0;
}
