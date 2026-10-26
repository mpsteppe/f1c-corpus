int (__cdecl *__stdcall sub_6B74F6(int a1, int a2, unsigned int a3))(int, int)
{
  unsigned int v3; // ebx
  int v4; // edi
  _BYTE *v5; // esi
  int (__cdecl *result)(int, int); // eax
  int v7; // [esp-Ch] [ebp-14h]
  int v8; // [esp-4h] [ebp-Ch]

  v3 = a3;
  v4 = a1;
  if ( (*(_BYTE *)(a1 + 408) || a3) && a3 <= 0x100 )
  {
    v8 = 3 * a3;
    v7 = a1;
    *(_WORD *)(a1 + 264) = a3;
    sub_6B743C(v7, (int)"PLTE", v8);
    if ( v3 )
    {
      v5 = (_BYTE *)(a2 + 2);
      do
      {
        LOWORD(a1) = *((_WORD *)v5 - 1);
        BYTE2(a1) = *v5;
        sub_6B747E(v4, (int)&a1, 3);
        v5 += 3;
        --v3;
      }
      while ( v3 );
    }
    result = (int (__cdecl *)(int, int))sub_6B74A7(v4);
    *(_DWORD *)(v4 + 88) |= 2u;
  }
  else
  {
    if ( *(_BYTE *)(a1 + 278) == 3 )
      sub_679F05(a1, (int)"Invalid number of colors in palette");
    return sub_679F26(a1, (int)"Invalid number of colors in palette");
  }
  return result;
}
