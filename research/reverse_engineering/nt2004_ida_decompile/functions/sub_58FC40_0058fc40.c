int __cdecl sub_58FC40(int a1, unsigned int a2)
{
  int result; // eax

  result = -1;
  if ( a2 < 8 )
    return *(unsigned __int8 *)(3 * a2 + 12 + ((2 * *(unsigned __int8 *)(a1 + 6) + 3) & 0xFFFFFFFC) + a1);
  return result;
}
