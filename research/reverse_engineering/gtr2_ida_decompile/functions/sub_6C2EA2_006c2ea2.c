int __thiscall sub_6C2EA2(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // eax
  int v5; // esi
  int v6; // edx
  _DWORD *v7; // edi
  unsigned int v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // edx
  _DWORD *v14; // edx
  int v15; // ecx
  unsigned int v17; // [esp+10h] [ebp-4h]
  _DWORD *v18; // [esp+1Ch] [ebp+8h]

  v4 = *(_DWORD **)(this[5] + 4 * a2);
  v5 = v4[18];
  if ( v4[22] != v4[21] )
    return 1;
  v6 = -1;
  if ( v5 == -1 )
    return 1;
  v7 = *(_DWORD **)(this[6] + 4 * v5);
  if ( (*v7 & 0xFFF00000) != 0x20400000 )
    return 1;
  v17 = 0;
  v8 = v7[3];
  if ( !v8 )
    return 1;
  v9 = (_DWORD *)v7[4];
  do
  {
    if ( *v9 == a2 )
      v6 = v17;
    ++v17;
    ++v9;
  }
  while ( v17 < v8 );
  if ( v6 == -1 )
    return 1;
  v10 = v7[2];
  v18 = (_DWORD *)(v10 + 4 * v6);
  v11 = (_DWORD *)(v10 + 4 * ((*v7 & 0xFFFFF) + v6));
  v12 = this[5];
  v13 = this[4];
  if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(*(_DWORD *)(v12 + 4 * *v11) + 4)) + 5) & 1) != 0 )
  {
    v14 = v18;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(*(_DWORD *)(v12 + 4 * *v18) + 4)) + 5) & 1) == 0 )
      return 1;
    v14 = v11;
    v11 = v18;
  }
  v15 = this[5];
  if ( *(double *)(*(_DWORD *)(v15 + 4 * *v11) + 32) == 1.0
    && (*(_DWORD *)(*(_DWORD *)(v15 + 4 * *v14) + 60) & 0x1F0000) == 0x80000 )
  {
    *a4 = *v14;
    *a3 = v7;
    return 0;
  }
  return 1;
}
