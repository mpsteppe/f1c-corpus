int __cdecl sub_512366(int a1, unsigned __int8 a2, int a3)
{
  int result; // eax
  char v4; // cl

  result = a1;
  *(_BYTE *)(a1 + 97) |= 0x80u;
  *(_WORD *)(a1 + 286) = a2;
  if ( a3 == 1 )
    *(_BYTE *)(a1 + 92) |= 0x80u;
  else
    *(_BYTE *)(a1 + 92) &= ~0x80u;
  v4 = *(_BYTE *)(a1 + 278);
  if ( v4 == 2 )
    *(_BYTE *)(a1 + 283) = 4;
  if ( !v4 && *(_BYTE *)(a1 + 279) >= 8u )
    *(_BYTE *)(a1 + 283) = 2;
  return result;
}

