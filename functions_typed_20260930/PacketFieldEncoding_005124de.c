unsigned int __cdecl sub_5124DE(int a1, int a2)
{
  char v2; // dl
  char v3; // dl
  char v4; // dl
  unsigned __int8 v5; // al
  unsigned int result; // eax

  if ( (*(_BYTE *)(a1 + 97) & 0x10) != 0 )
  {
    v2 = *(_BYTE *)(a2 + 25);
    if ( v2 == 3 )
    {
      *(_BYTE *)(a2 + 25) = 4 * (*(_WORD *)(a1 + 266) != 0) + 2;
    }
    else
    {
      if ( *(_WORD *)(a1 + 266) )
        *(_BYTE *)(a2 + 25) = v2 | 4;
      if ( *(_BYTE *)(a2 + 24) >= 8u )
        goto LABEL_8;
    }
    *(_BYTE *)(a2 + 24) = 8;
LABEL_8:
    *(_WORD *)(a2 + 22) = 0;
  }
  if ( (*(_BYTE *)(a1 + 97) & 0x20) != 0 )
    *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 304);
  if ( (*(_BYTE *)(a1 + 97) & 4) != 0 && *(_BYTE *)(a2 + 24) == 16 )
    *(_BYTE *)(a2 + 24) = 8;
  if ( (*(_BYTE *)(a1 + 96) & 0x40) != 0 )
  {
    v3 = *(_BYTE *)(a2 + 25);
    if ( (v3 == 2 || v3 == 6) && *(_DWORD *)(a1 + 372) && *(_BYTE *)(a2 + 24) == 8 )
      *(_BYTE *)(a2 + 25) = 3;
  }
  if ( (*(_BYTE *)(a1 + 96) & 4) != 0 && *(_BYTE *)(a2 + 24) < 8u )
    *(_BYTE *)(a2 + 24) = 8;
  v4 = *(_BYTE *)(a2 + 25);
  if ( v4 == 3 || (v4 & 2) == 0 )
    *(_BYTE *)(a2 + 29) = 1;
  else
    *(_BYTE *)(a2 + 29) = 3;
  if ( (v4 & 4) != 0 )
    ++*(_BYTE *)(a2 + 29);
  if ( *(char *)(a1 + 97) < 0 && (v4 == 2 || !v4) )
    ++*(_BYTE *)(a2 + 29);
  v5 = *(_BYTE *)(a2 + 29) * *(_BYTE *)(a2 + 24);
  *(_BYTE *)(a2 + 30) = v5;
  result = (*(_DWORD *)a2 * (unsigned int)v5 + 7) >> 3;
  *(_DWORD *)(a2 + 12) = result;
  return result;
}

