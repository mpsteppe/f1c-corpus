int (__cdecl *__stdcall sub_67A175(int a1, int a2))(int, _DWORD, _DWORD)
{
  int (__cdecl *result)(int, _DWORD, _DWORD); // eax
  bool v3; // cf
  bool v4; // zf
  char v5; // dl
  int v6; // ecx
  char v7; // al
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  int v10; // [esp-10h] [ebp-14h]
  unsigned int v11; // [esp-8h] [ebp-Ch]

  if ( !*(_DWORD *)(a1 + 212) && !*(_BYTE *)(a1 + 276) )
  {
    if ( *(char *)(a1 + 97) < 0 )
      sub_679F26(a1, (int)"PNG_WRITE_FILLER_SUPPORTED is not defined.");
    if ( (*(_BYTE *)(a1 + 96) & 4) != 0 )
      sub_679F26(a1, (int)"PNG_WRITE_PACK_SUPPORTED is not defined.");
    if ( (*(_BYTE *)(a1 + 96) & 8) != 0 )
      sub_679F26(a1, (int)"PNG_WRITE_SHIFT_SUPPORTED is not defined.");
    if ( (*(_BYTE *)(a1 + 96) & 1) != 0 )
      sub_679F26(a1, (int)"PNG_WRITE_BGR_SUPPORTED is not defined.");
    if ( (*(_BYTE *)(a1 + 96) & 0x10) != 0 )
      sub_679F26(a1, (int)"PNG_WRITE_SWAP_SUPPORTED is not defined.");
    sub_6B7588(a1);
  }
  if ( !*(_BYTE *)(a1 + 275) || (*(_BYTE *)(a1 + 96) & 2) == 0 )
    goto LABEL_37;
  switch ( *(_BYTE *)(a1 + 276) )
  {
    case 0:
      v4 = (*(_BYTE *)(a1 + 212) & 7) == 0;
LABEL_36:
      if ( v4 )
        goto LABEL_37;
      return (int (__cdecl *)(int, _DWORD, _DWORD))sub_6B7C17(a1);
    case 1:
      if ( (*(_BYTE *)(a1 + 212) & 7) != 0 )
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_6B7C17(a1);
      v3 = *(_DWORD *)(a1 + 184) < 5u;
LABEL_33:
      if ( !v3 )
        goto LABEL_37;
      return (int (__cdecl *)(int, _DWORD, _DWORD))sub_6B7C17(a1);
    case 2:
      v4 = (*(_BYTE *)(a1 + 212) & 7) == 4;
      goto LABEL_36;
    case 3:
      if ( (*(_BYTE *)(a1 + 212) & 3) != 0 )
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_6B7C17(a1);
      v3 = *(_DWORD *)(a1 + 184) < 3u;
      goto LABEL_33;
    case 4:
      v4 = (*(_BYTE *)(a1 + 212) & 3) == 2;
      goto LABEL_36;
    case 5:
      if ( (*(_BYTE *)(a1 + 212) & 1) != 0 )
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_6B7C17(a1);
      v3 = *(_DWORD *)(a1 + 184) < 2u;
      goto LABEL_33;
  }
  if ( *(_BYTE *)(a1 + 276) == 6 && (*(_BYTE *)(a1 + 212) & 1) == 0 )
    return (int (__cdecl *)(int, _DWORD, _DWORD))sub_6B7C17(a1);
LABEL_37:
  v5 = *(_BYTE *)(a1 + 283);
  v6 = *(_DWORD *)(a1 + 196);
  *(_BYTE *)(a1 + 248) = *(_BYTE *)(a1 + 278);
  v7 = *(_BYTE *)(a1 + 280);
  *(_BYTE *)(a1 + 249) = v7;
  v8 = v5 * v7;
  *(_BYTE *)(a1 + 251) = v8;
  v11 = (v6 * (unsigned int)v8 + 7) >> 3;
  *(_DWORD *)(a1 + 244) = v11;
  v10 = *(_DWORD *)(a1 + 220) + 1;
  *(_DWORD *)(a1 + 240) = v6;
  *(_BYTE *)(a1 + 250) = v5;
  sub_6B72C0(a1, v10, a2, v11);
  if ( *(_BYTE *)(a1 + 275) )
  {
    v9 = *(_BYTE *)(a1 + 276);
    if ( v9 < 6u && (*(_BYTE *)(a1 + 96) & 2) != 0 )
    {
      sub_6B76CA(a1 + 240, *(_DWORD *)(a1 + 220) + 1, v9);
      if ( !*(_DWORD *)(a1 + 240) )
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_6B7C17(a1);
    }
  }
  if ( *(_DWORD *)(a1 + 96) )
    nullsub_10(a1);
  sub_6B7E46(a1, a1 + 240);
  result = *(int (__cdecl **)(int, _DWORD, _DWORD))(a1 + 368);
  if ( result )
    return (int (__cdecl *)(int, _DWORD, _DWORD))result(a1, *(_DWORD *)(a1 + 212), *(unsigned __int8 *)(a1 + 276));
  return result;
}
