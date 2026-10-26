int __thiscall sub_6A251E(_DWORD *this)
{
  int v1; // eax
  int v2; // edx
  int v4; // esi
  _DWORD *v5; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // edx
  _DWORD *v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // [esp+0h] [ebp-10h]
  int v13; // [esp+4h] [ebp-Ch]
  int v14; // [esp+8h] [ebp-8h]
  unsigned int v15; // [esp+Ch] [ebp-4h]
  unsigned int v16; // [esp+Ch] [ebp-4h]

  v1 = this[5];
  v2 = *(_DWORD *)(*(_DWORD *)(v1 + 4 * *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 28)) + 72);
  if ( v2 == -1 )
    return 1;
  v4 = this[6];
  v5 = *(_DWORD **)(v4 + 4 * v2);
  if ( (*v5 & 0xFFF00000) != 0x10000000 )
    return 1;
  v12 = -1;
  v6 = *(_DWORD *)(this[64] + 8);
  v7 = *(_DWORD *)(v1 + 4 * *(_DWORD *)(v6 + 24));
  v13 = *(_DWORD *)(v6 + 24);
  v8 = *(_DWORD *)(v7 + 72);
  if ( v8 != -1 && !*(_DWORD *)(v7 + 60) )
  {
    v9 = *(_DWORD **)(v4 + 4 * v8);
    if ( (*v9 & 0xFFF00000) == 0x10000000 )
    {
      v15 = 0;
      if ( v9[1] )
      {
        do
        {
          if ( *(_DWORD *)(v9[4] + 4 * v15) == v13 )
            v12 = *(_DWORD *)(4 * v15 + v9[2]);
          ++v15;
        }
        while ( v15 < v9[1] );
        v6 = *(_DWORD *)(this[64] + 8);
      }
    }
  }
  v14 = 0;
  v16 = 0;
  if ( !v5[1] )
    return 1;
  do
  {
    v10 = 4 * v16;
    v11 = *(_DWORD *)(v5[2] + 4 * v16);
    if ( v11 == v13 && *(_DWORD *)(v10 + v5[4]) == *(_DWORD *)(v6 + 28) )
      v14 = 1;
    if ( v11 == v12 && *(_DWORD *)(v10 + v5[4]) == *(_DWORD *)(v6 + 28) )
      v14 = 1;
    ++v16;
  }
  while ( v16 < v5[1] );
  if ( !v14 )
    return 1;
  *(_DWORD *)this[64] = 1927282691;
  *(_DWORD *)(this[64] + 4) = 6;
  *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 12) = *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 16);
  *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 16) = *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 20);
  *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 20) = *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 24);
  return 0;
}
