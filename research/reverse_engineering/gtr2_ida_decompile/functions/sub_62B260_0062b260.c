int __fastcall sub_62B260(int a1, unsigned int a2)
{
  int v4; // esi
  int v5; // eax
  signed int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  signed int v16; // [esp+Ch] [ebp-4h]

  if ( !a1 )
    return -2;
  v4 = *(_DWORD *)(a1 + 28);
  if ( !v4 || a2 > 4 )
    return -2;
  if ( !*(_DWORD *)(a1 + 12)
    || !*(_DWORD *)a1 && *(_DWORD *)(a1 + 4)
    || (v5 = *(_DWORD *)(v4 + 4), v5 == 666) && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_911694[0];
    return -2;
  }
  if ( !*(_DWORD *)(a1 + 16) )
  {
    *(char **)(a1 + 24) = off_9116A0[0];
    return -5;
  }
  v7 = *(_DWORD *)(v4 + 30);
  *(_DWORD *)v4 = a1;
  v16 = v7;
  *(_DWORD *)(v4 + 30) = a2;
  if ( v5 == 42 )
  {
    v8 = (*(_DWORD *)(v4 + 122) - 1) >> 1;
    if ( v8 > 3 )
      v8 = 3;
    v9 = (v8 << 6) | (((*(_DWORD *)(v4 + 38) - 8) << 12) + 2048);
    if ( *(_DWORD *)(v4 + 98) )
      v9 |= 0x20u;
    *(_DWORD *)(v4 + 4) = 113;
    sub_62B1C0(v4, v9 - v9 % 0x1F + 31);
    if ( *(_DWORD *)(v4 + 98) )
    {
      v10 = sub_62B1C0(v4, *(_WORD *)(a1 + 50));
      sub_62B1C0(v10, *(_DWORD *)(a1 + 48));
    }
    *(_DWORD *)(a1 + 48) = 1;
  }
  if ( *(_DWORD *)(v4 + 20) )
  {
    sub_62B1F0(a1);
    if ( !*(_DWORD *)(a1 + 16) )
    {
LABEL_21:
      *(_DWORD *)(v4 + 30) = -1;
      return 0;
    }
  }
  else if ( !*(_DWORD *)(a1 + 4) && (int)a2 <= v16 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_9116A0[0];
    return -5;
  }
  v11 = *(_DWORD *)(v4 + 4);
  v12 = *(_DWORD *)(a1 + 4);
  if ( v11 == 666 )
  {
    if ( v12 )
    {
      *(char **)(a1 + 24) = off_9116A0[0];
      return -5;
    }
LABEL_31:
    if ( !*(_DWORD *)(v4 + 106) && (!a2 || v11 == 666) )
      goto LABEL_45;
    goto LABEL_34;
  }
  if ( !v12 )
    goto LABEL_31;
LABEL_34:
  v13 = ((int (__fastcall *)(int, unsigned int))funcs_62B3ED[3 * *(_DWORD *)(v4 + 122)])(v4, a2);
  if ( v13 == 2 || v13 == 3 )
    *(_DWORD *)(v4 + 4) = 666;
  if ( !v13 || v13 == 2 )
  {
    if ( *(_DWORD *)(a1 + 16) )
      return 0;
    *(_DWORD *)(v4 + 30) = -1;
    return 0;
  }
  if ( v13 == 1 )
  {
    if ( a2 == 1 )
    {
      sub_62E340(v4);
    }
    else
    {
      sub_62E2A0(0, 0);
      if ( a2 == 3 )
      {
        *(_WORD *)(*(_DWORD *)(v4 + 58) + 2 * *(_DWORD *)(v4 + 66) - 2) = 0;
        memset(*(void **)(v4 + 58), 0, 2 * *(_DWORD *)(v4 + 66) - 2);
      }
    }
    sub_62B1F0(a1);
    if ( !*(_DWORD *)(a1 + 16) )
      goto LABEL_21;
  }
LABEL_45:
  if ( a2 != 4 )
    return 0;
  if ( *(_DWORD *)(v4 + 24) )
    return 1;
  v14 = sub_62B1C0(v4, *(_WORD *)(a1 + 50));
  sub_62B1C0(v14, *(_DWORD *)(a1 + 48));
  sub_62B1F0(a1);
  v15 = *(_DWORD *)(v4 + 20);
  *(_DWORD *)(v4 + 24) = -1;
  return v15 == 0;
}
