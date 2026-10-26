unsigned int __cdecl sub_58806E(_BYTE *a1, unsigned int a2, int a3, int a4)
{
  int v4; // edi
  unsigned int v6; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edi
  DWORD v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // [esp+18h] [ebp+8h]
  unsigned int v15; // [esp+24h] [ebp+14h]

  v4 = a3 * a2;
  v6 = a3 * a2;
  v14 = a3 * a2;
  if ( !(a3 * a2) )
    return 0;
  if ( (*(_WORD *)(a4 + 12) & 0x10C) != 0 )
    v15 = *(_DWORD *)(a4 + 24);
  else
    v15 = 4096;
  while ( 1 )
  {
    if ( (*(_WORD *)(a4 + 12) & 0x10C) != 0 )
    {
      v9 = *(_DWORD *)(a4 + 4);
      if ( v9 )
      {
        v10 = v6;
        if ( v6 >= v9 )
          v10 = *(_DWORD *)(a4 + 4);
        MemoryCopy_cc00(a1, *(_DWORD *)a4, v10);
        v14 -= v10;
        *(_DWORD *)(a4 + 4) -= v10;
        *(_DWORD *)a4 += v10;
        a1 += v10;
        v4 = a3 * a2;
        goto LABEL_20;
      }
    }
    if ( v6 >= v15 )
      break;
    v13 = sub_58C255(a4);
    if ( v13 == -1 )
      return (v4 - v14) / a2;
    *a1++ = v13;
    --v14;
    v15 = *(_DWORD *)(a4 + 24);
LABEL_20:
    if ( !v14 )
      return a3;
    v6 = v14;
  }
  v11 = v6;
  if ( v15 )
    v11 = v6 - v6 % v15;
  v12 = sub_58C9B4(*(_DWORD *)(a4 + 16), a1, v11);
  if ( !v12 )
  {
    *(_DWORD *)(a4 + 12) |= 0x10u;
    return (v4 - v14) / a2;
  }
  if ( v12 != -1 )
  {
    v14 -= v12;
    a1 += v12;
    goto LABEL_20;
  }
  *(_DWORD *)(a4 + 12) |= 0x20u;
  return (v4 - v14) / a2;
}

