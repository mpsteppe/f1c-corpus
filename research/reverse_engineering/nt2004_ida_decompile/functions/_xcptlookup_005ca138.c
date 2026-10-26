_DWORD *__cdecl xcptlookup(int a1, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a2;
  if ( *a2 != a1 )
  {
    do
      result += 3;
    while ( result < &a2[3 * dword_62655C] && *result != a1 );
  }
  if ( result >= &a2[3 * dword_62655C] || *result != a1 )
    return 0;
  return result;
}
