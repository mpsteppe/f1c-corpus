// f1c  0x00592a62  size=58
_DWORD *__cdecl sub_592A62(int a1, _DWORD *a2)
{
  _DWORD *result; // eax

  result = a2;
  if ( *a2 != a1 )
  {
    do
      result += 3;
    while ( result < &a2[3 * dword_5E7894] && *result != a1 );
  }
  if ( result >= &a2[3 * dword_5E7894] || *result != a1 )
    return 0;
  return result;
}
