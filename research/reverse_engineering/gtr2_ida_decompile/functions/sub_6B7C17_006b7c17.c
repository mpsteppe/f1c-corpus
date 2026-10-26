unsigned int __stdcall sub_6B7C17(int a1)
{
  unsigned int result; // eax
  unsigned __int8 v3; // bl
  int v4; // ecx
  bool v5; // zf
  void *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // [esp+4h] [ebp-4h]
  int v11; // [esp+10h] [ebp+8h]

  result = a1 + 212;
  if ( ++*(_DWORD *)(a1 + 212) >= *(_DWORD *)(a1 + 192) )
  {
    if ( *(_BYTE *)(a1 + 275) )
    {
      *(_DWORD *)result = 0;
      if ( (*(_BYTE *)(a1 + 96) & 2) != 0 )
      {
        result = a1 + 276;
        v3 = ++*(_BYTE *)(a1 + 276);
LABEL_8:
        if ( v3 < 7u )
        {
          v6 = *(void **)(a1 + 216);
          if ( v6 )
          {
            result = 0;
            memset(
              v6,
              0,
              ((*(_DWORD *)(a1 + 184) * *(unsigned __int8 *)(a1 + 280) * (unsigned int)*(unsigned __int8 *)(a1 + 283) + 7) >> 3)
            + 1);
          }
          return result;
        }
      }
      else
      {
        while ( 1 )
        {
          v3 = ++*(_BYTE *)(a1 + 276);
          if ( v3 >= 7u )
            break;
          v4 = v3;
          *(_DWORD *)(a1 + 196) = (*(_DWORD *)(a1 + 184) - dword_744FC0[v4] + dword_744FDC[v4] - 1)
                                / (unsigned int)dword_744FDC[v4];
          result = (*(_DWORD *)(a1 + 188) - dword_744FF8[v4] + dword_745014[v4] - 1) / (unsigned int)dword_745014[v4];
          v5 = *(_DWORD *)(a1 + 196) == 0;
          *(_DWORD *)(a1 + 192) = result;
          if ( !v5 && result )
            goto LABEL_8;
        }
      }
    }
    v11 = a1 + 100;
    do
    {
      v7 = sub_6B8942(v11, 4);
      v10 = v7;
      if ( v7 >= 2 )
      {
        if ( *(_DWORD *)(a1 + 124) )
          sub_679F05(a1, *(_DWORD *)(a1 + 124));
        sub_679F05(a1, (int)"zlib error");
      }
      if ( !*(_DWORD *)(a1 + 116) && !v7 )
      {
        sub_6B7BD3(a1, *(_DWORD *)(a1 + 156), *(_DWORD *)(a1 + 160));
        *(_DWORD *)(a1 + 112) = *(_DWORD *)(a1 + 156);
        *(_DWORD *)(a1 + 116) = *(_DWORD *)(a1 + 160);
      }
    }
    while ( v10 != 1 );
    v8 = *(_DWORD *)(a1 + 116);
    v9 = *(_DWORD *)(a1 + 160);
    if ( v8 < v9 )
      sub_6B7BD3(a1, *(_DWORD *)(a1 + 156), v9 - v8);
    return sub_6B9659(v11);
  }
  return result;
}
