int __cdecl sub_58EEE0(int a1, int a2, int a3)
{
  int result; // eax

  result = 1;
  if ( a3 > *(unsigned __int8 *)(a2 + 5) )
    return 0;
  if ( (*(_WORD *)(a1 + 2) == 0xFFFF || (result = sub_58EF90(a1, a2, a3)) != 0) && *(char *)(a2 + 4) < 0 )
    return sub_58EF50(
             ((*(unsigned __int8 *)(a2 + 5) * ((*(_BYTE *)(a2 + 4) & 0xF) + 2) + 15) & 0xFFFFFFFC)
           + a2
           + 4 * (*(_BYTE *)(a2 + 4) & 0xF)
           + 1,
             a3);
  return result;
}
