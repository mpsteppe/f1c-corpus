int __thiscall sub_683158(_DWORD *this, int a2, int a3)
{
  int v3; // edx
  int v5; // eax
  _DWORD *v6; // esi
  unsigned int v7; // ebx
  unsigned int v8; // eax
  _DWORD *v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // ebx
  _DWORD *v12; // eax

  v3 = a3;
  if ( a2 == a3 )
    return 1;
  v5 = *(_DWORD *)(this[5] + 4 * a3);
  if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v5 + 4)) + 4) & 2) == 0 )
    return 0;
  v6 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v5 + 72));
  if ( (*v6 & 0xFFF00000) == 0x10000000 )
  {
    v7 = v6[3];
    v8 = 0;
    if ( v7 )
    {
      v9 = (_DWORD *)v6[4];
      do
      {
        if ( *v9 == a3 )
          break;
        ++v8;
        ++v9;
      }
      while ( v8 < v7 );
    }
    if ( sub_683158(a2, *(_DWORD *)(v6[2] + 4 * v8)) )
      return 1;
    v3 = a3;
  }
  if ( (*v6 & 0xFFF00000) == 0x20500000 )
  {
    v10 = v6[3];
    v11 = 0;
    if ( v10 )
    {
      v12 = (_DWORD *)v6[4];
      do
      {
        if ( *v12 == v3 )
          break;
        ++v11;
        ++v12;
      }
      while ( v11 < v10 );
    }
    if ( sub_683158(a2, *(_DWORD *)(v6[2] + 4 * v11)) || sub_683158(a2, *(_DWORD *)(v6[2] + 4 * (v11 + v6[3]))) )
      return 1;
  }
  return 0;
}
