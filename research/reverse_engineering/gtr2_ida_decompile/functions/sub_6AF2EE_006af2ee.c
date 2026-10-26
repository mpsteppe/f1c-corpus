int __thiscall sub_6AF2EE(_DWORD *this, int a2, unsigned int a3)
{
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // edi
  unsigned int v9; // eax
  unsigned int i; // edi
  int v11; // eax
  _DWORD *v12; // eax
  char *v13; // eax
  int v16; // eax
  _DWORD *v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // eax
  int v20; // ecx
  _DWORD v21[4]; // [esp+14h] [ebp-10h]
  int v22; // [esp+2Ch] [ebp+8h]
  unsigned int j; // [esp+2Ch] [ebp+8h]

  v4 = this[2];
  v5 = 0;
  if ( v4 )
  {
    v6 = this[34];
    v7 = this[5];
    v8 = v4;
    do
    {
      if ( v6 == *(_DWORD *)(*(_DWORD *)v7 + 4) )
      {
        v9 = *(_DWORD *)(*(_DWORD *)v7 + 12);
        if ( v9 >= v5 )
          v5 = v9 + 1;
      }
      v7 += 4;
      --v8;
    }
    while ( v8 );
  }
  for ( i = 0; i < 4; ++i )
  {
    v11 = sub_681AAA(this, this[34], v5, i, 0.0);
    v21[i] = v11;
    if ( v11 == -1 )
      return -2147024882;
  }
  v12 = (_DWORD *)sub_681186(116);
  if ( v12 )
    v13 = (char *)sub_680CEC(v12);
  else
    v13 = 0;
  *(_DWORD *)a2 = v13;
  if ( !v13 )
    return -2147024882;
  v16 = sub_6811D1(v13, a3 & 0xFFFFF | 0x10000000, a3, a3, 0);
  v17 = *(_DWORD **)a2;
  v22 = v16;
  if ( v16 < 0 )
    goto LABEL_18;
  v22 = sub_680D22(v17, this[64]);
  if ( v22 < 0 )
  {
    v17 = *(_DWORD **)a2;
LABEL_18:
    if ( v17 )
      sub_66238F(v17, 1);
    return v22;
  }
  v18 = 0;
  for ( j = 0; j < a3; ++j )
  {
    v19 = 4 * v18;
    v20 = v21[v19 / 4];
    *(_DWORD *)(v19 + *(_DWORD *)(*(_DWORD *)a2 + 8)) = v20;
    *(_DWORD *)(v19 + *(_DWORD *)(*(_DWORD *)a2 + 16)) = *(_DWORD *)(v19 + *(_DWORD *)(this[64] + 16));
    *(_DWORD *)(v19 + *(_DWORD *)(this[64] + 16)) = v20;
    v18 = j + 1;
  }
  return 0;
}
