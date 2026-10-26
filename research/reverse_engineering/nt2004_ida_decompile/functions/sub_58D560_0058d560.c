unsigned __int16 *__cdecl sub_58D560(int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  unsigned __int16 *i; // edx
  unsigned __int16 *result; // eax

  v2 = 0;
  v3 = *(unsigned __int16 *)(a1 + 16);
  if ( !(_WORD)v3 )
    return 0;
  for ( i = (unsigned __int16 *)(a1 + 24); ; ++i )
  {
    result = (unsigned __int16 *)(a1 + 4 * *i);
    if ( *result == a2 )
      break;
    if ( ++v2 >= v3 )
      return 0;
  }
  return result;
}
