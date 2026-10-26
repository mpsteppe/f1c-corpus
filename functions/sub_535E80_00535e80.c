int __fastcall sub_535E80(int a1, unsigned int a2)
{
  int v4; // esi
  int v5; // eax
  signed int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  signed int v14; // [esp+10h] [ebp-4h]

  if ( !a1 )
    return -2;
  v4 = *(_DWORD *)(a1 + 28);
  if ( !v4 || a2 > 4 )
    return -2;
  if ( !*(_DWORD *)(a1 + 12)
    || !*(_DWORD *)a1 && *(_DWORD *)(a1 + 4)
    || (v5 = *(_DWORD *)(v4 + 4), v5 == 666) && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_5DA82C[0];
    return -2;
  }
  if ( !*(_DWORD *)(a1 + 16) )
  {
    *(char **)(a1 + 24) = off_5DA838[0];
    return -5;
  }
  v7 = *(_DWORD *)(v4 + 30);
  *(_DWORD *)v4 = a1;
  v14 = v7;
  *(_DWORD *)(v4 + 30) = a2;
  if ( v5 == 42 )
  {
    v8 = (*(_DWORD *)(v4 + 122) - 1) >> 1;
    if ( v8 > 3 )
      v8 = 3;
    v9 = (v8 << 6) | ((*(_DWORD *)(v4 + 38) << 12) - 30720);
    if ( *(_DWORD *)(v4 + 98) )
      v9 |= 0x20u;
    *(_DWORD *)(v4 + 4) = 113;
    BigEndianShortWriter(v4, v9 - v9 % 0x1F + 31);
    if ( *(_DWORD *)(v4 + 98) )
    {
      BigEndianShortWriter(v4, *(unsigned __int16 *)(a1 + 50));
      BigEndianShortWriter(v4, (unsigned __int16)*(_DWORD *)(a1 + 48));
    }
    *(_DWORD *)(a1 + 48) = 1;
  }
  if ( *(_DWORD *)(v4 + 20) )
  {
    BufferCopyWithSizeTracking(a1);
    if ( !*(_DWORD *)(a1 + 16) )
    {
      *(_DWORD *)(v4 + 30) = -1;
      return 0;
    }
  }
  else if ( !*(_DWORD *)(a1 + 4) && (int)a2 <= v14 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_5DA838[0];
    return -5;
  }
  v10 = *(_DWORD *)(v4 + 4);
  v11 = *(_DWORD *)(a1 + 4);
  if ( v10 == 666 )
  {
    if ( v11 )
    {
      *(char **)(a1 + 24) = off_5DA838[0];
      return -5;
    }
  }
  else if ( v11 )
  {
    goto LABEL_33;
  }
  if ( !*(_DWORD *)(v4 + 106) && (!a2 || v10 == 666) )
  {
LABEL_45:
    if ( a2 != 4 )
      return 0;
    if ( *(_DWORD *)(v4 + 24) )
      return 1;
    BigEndianShortWriter(v4, *(unsigned __int16 *)(a1 + 50));
    BigEndianShortWriter(v4, (unsigned __int16)*(_DWORD *)(a1 + 48));
    BufferCopyWithSizeTracking(a1);
    v13 = *(_DWORD *)(v4 + 20);
    *(_DWORD *)(v4 + 24) = -1;
    return v13 == 0;
  }
LABEL_33:
  v12 = ((int (__fastcall *)(int, unsigned int))funcs_536014[3 * *(_DWORD *)(v4 + 122)])(v4, a2);
  if ( v12 == 2 || v12 == 3 )
    *(_DWORD *)(v4 + 4) = 666;
  if ( v12 && v12 != 2 )
  {
    if ( v12 == 1 )
    {
      if ( a2 == 1 )
      {
        BitstreamEncoder(v4);
      }
      else
      {
        BitstreamWriteBits(0, 0);
        if ( a2 == 3 )
        {
          *(_WORD *)(*(_DWORD *)(v4 + 58) + 2 * *(_DWORD *)(v4 + 66) - 2) = 0;
          memset(*(void **)(v4 + 58), 0, 2 * *(_DWORD *)(v4 + 66) - 2);
        }
      }
      BufferCopyWithSizeTracking(a1);
      if ( !*(_DWORD *)(a1 + 16) )
      {
        *(_DWORD *)(v4 + 30) = -1;
        return 0;
      }
    }
    goto LABEL_45;
  }
  if ( !*(_DWORD *)(a1 + 16) )
    *(_DWORD *)(v4 + 30) = -1;
  return 0;
}
