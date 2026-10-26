int __stdcall sub_67A0E8(int a1, int a2)
{
  int result; // eax

  sub_6B74D0(a1);
  result = sub_6B7931(
             a1,
             *(_DWORD *)a2,
             *(_DWORD *)(a2 + 4),
             *(unsigned __int8 *)(a2 + 24),
             *(unsigned __int8 *)(a2 + 25),
             *(unsigned __int8 *)(a2 + 26),
             *(unsigned __int8 *)(a2 + 27),
             *(unsigned __int8 *)(a2 + 28));
  if ( (*(_BYTE *)(a2 + 8) & 8) != 0 )
    return sub_6B74F6(a1, *(_DWORD *)(a2 + 16), *(unsigned __int16 *)(a2 + 20));
  if ( *(_BYTE *)(a2 + 25) == 3 )
    sub_679F05(a1, (int)"Valid palette required for paletted images\n");
  return result;
}
