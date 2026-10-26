int __stdcall sub_65B242(_BYTE *a1, int a2, int a3)
{
  int result; // eax
  int v4; // edi
  BOOL i; // edx

  result = 0;
  v4 = 0;
  for ( i = 0; a2; --a2 )
  {
    if ( *a1 == 34 )
    {
      if ( a3 )
        *(_BYTE *)(result + a3) = 92;
      ++result;
      if ( !v4 )
        i = !i;
    }
    v4 = 0;
    if ( i && *a1 == 92 )
    {
      if ( a3 )
        *(_BYTE *)(result + a3) = 92;
      ++result;
      v4 = 1;
    }
    if ( a3 )
      *(_BYTE *)(result + a3) = *a1;
    ++result;
    ++a1;
  }
  return result;
}
