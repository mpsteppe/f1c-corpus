int __thiscall sub_6CCE53(int this)
{
  int v1; // eax
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // edx
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // esi
  int i; // [esp+4h] [ebp-Ch]
  unsigned int v14; // [esp+8h] [ebp-8h]
  unsigned int v15; // [esp+Ch] [ebp-4h]
  unsigned int j; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD *)(this + 256);
  if ( *(_DWORD *)(this + 140) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v1 + 16)) + 4) )
    return sub_6CCA8D((_DWORD *)this, 46, 0);
  if ( (*(_BYTE *)(this + 110) & 0x10) == 0 )
  {
    v15 = 0;
    v14 = *(_DWORD *)(v1 + 12);
    if ( v14 )
    {
      v3 = *(_DWORD *)(this + 256);
      v4 = *(_DWORD **)(v3 + 16);
      v5 = *(_DWORD *)(this + 20);
      v6 = *(_DWORD *)(v3 + 8) - (_DWORD)v4;
      v7 = v4;
      for ( i = v6; ; v6 = i )
      {
        v8 = *(_DWORD **)(v5 + 4 * *(_DWORD *)((char *)v7 + v6));
        v9 = *(_DWORD **)(v5 + 4 * *v7);
        if ( v9[1] != v8[1]
          || v9[2] != v8[2]
          || v9[3] != v8[3]
          || v9[4] != v8[4]
          || v9[15] != v8[15]
          || (*(_BYTE *)(this + 204) & 4) != 0 && v9[24] )
        {
          break;
        }
        ++v15;
        ++v7;
        if ( v15 >= v14 )
          break;
      }
    }
    if ( v15 == v14 )
      return 0;
  }
  for ( j = 0; j < *(_DWORD *)(*(_DWORD *)(this + 256) + 12); ++j )
  {
    v10 = *(_DWORD *)(this + 256);
    v11 = *(_DWORD *)(this + 20);
    v12 = *(_DWORD **)(v11 + 4 * *(_DWORD *)(*(_DWORD *)(v10 + 16) + 4 * j));
    if ( (*v12 & 0xE000000) == 0 )
      *v12 |= **(_DWORD **)(v11 + 4 * *(_DWORD *)(*(_DWORD *)(v10 + 8) + 4 * j)) & 0xE000000;
  }
  return sub_6CB29C(
           (_DWORD *)this,
           1,
           *(_DWORD **)(*(_DWORD *)(this + 256) + 16),
           *(_DWORD *)(*(_DWORD *)(this + 256) + 12),
           *(_DWORD **)(*(_DWORD *)(this + 256) + 8),
           0,
           0,
           *(_DWORD *)(*(_DWORD *)(this + 256) + 12),
           0,
           0,
           0,
           0);
}
