int __thiscall sub_6B0036(_DWORD *this, char *a2, unsigned int a3, int a4, _DWORD *a5)
{
  int v6; // esi
  int v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // eax
  unsigned int i; // eax
  unsigned int j; // eax
  int v16; // edi
  int v17; // edx
  int v18; // esi
  _DWORD *v19; // eax
  int v21; // edx
  unsigned int k; // ecx
  int v23; // esi
  _DWORD v24[4]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v25[4]; // [esp+1Ch] [ebp-14h] BYREF
  int v26; // [esp+2Ch] [ebp-4h]
  char *v27; // [esp+3Ch] [ebp+Ch]
  int v28; // [esp+40h] [ebp+10h]

  v6 = this[5];
  v7 = 4 * *(_DWORD *)a2;
  v26 = *(_DWORD *)(v6 + v7);
  v8 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(v26 + 4));
  v9 = 0;
  if ( *(char *)(v8 + 4) < 0 )
  {
    *a5 = &unk_E40000;
    return 0;
  }
  if ( (a4 & 0x10000) != 0 )
  {
    v25[0] = 0;
    v9 = 1;
  }
  if ( (a4 & 0x20000) != 0 )
    v25[v9++] = 1;
  if ( (a4 & 0x40000) != 0 )
    v25[v9++] = 2;
  if ( (a4 & 0x80000) != 0 )
    v25[v9++] = 3;
  if ( a3 > v9 )
    a3 = v9;
  v28 = (int)(this[27] << 30) >> 31;
  if ( (this[27] & 2) != 0 )
  {
    v10 = -1;
LABEL_24:
    v24[0] = v10;
    v24[1] = v10;
    v24[2] = v10;
    v24[3] = v10;
    goto LABEL_25;
  }
  v11 = 0;
  if ( !a3 )
    goto LABEL_23;
  v12 = this[5];
  v13 = *(_DWORD *)(*(_DWORD *)(v12 + v7) + 16);
  do
  {
    if ( v13 != *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)&a2[4 * v11]) + 16) )
      break;
    ++v11;
  }
  while ( v11 < a3 );
  if ( v11 >= a3 )
  {
LABEL_23:
    v10 = *(_DWORD *)(v26 + 16);
    goto LABEL_24;
  }
  for ( i = 0; i < 4; ++i )
    v24[i] = i;
LABEL_25:
  for ( j = 0; j < a3; v24[v16] = v17 )
  {
    v16 = v25[j];
    v17 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * *(_DWORD *)((char *)&v25[j++] + a2 - (char *)v25)) + 16);
  }
  v18 = 0;
  if ( !v28 )
  {
    v19 = v24;
LABEL_35:
    v21 = 0;
    for ( k = 16; k < 0x18; k += 2 )
    {
      v23 = *v19++ << k;
      v21 |= v23;
    }
    *a5 = v21;
    return 0;
  }
  v27 = (char *)&unk_91A658;
  while ( !sub_6A323B(v24, (int)v27) )
  {
    v27 += 16;
    if ( (unsigned int)++v18 >= 8 )
      goto LABEL_33;
  }
  v19 = (_DWORD *)((char *)&unk_91A658 + 16 * v18);
  if ( v19 )
    goto LABEL_35;
LABEL_33:
  sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4818, "internal error: invalid swizzle found");
  return -2147467259;
}
