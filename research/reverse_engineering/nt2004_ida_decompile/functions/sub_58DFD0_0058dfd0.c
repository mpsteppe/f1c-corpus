int __cdecl sub_58DFD0(__int16 a1, int *a2)
{
  int result; // eax
  int v3; // ecx
  _WORD *i; // esi

  result = 0;
  v3 = 0;
  if ( *a2 > 0 )
  {
    for ( i = (_WORD *)a2[1]; *i != a1; ++i )
    {
      if ( ++v3 >= *a2 )
        return result;
    }
    return 1;
  }
  return result;
}
