int sub_4D2450()
{
  int result; // eax
  float v1; // eax
  int v2; // ecx

  result = 0;
  if ( dword_5C329C > 0 )
  {
    while ( *(_DWORD *)(LODWORD(dword_7C54F0[result]) + 16484) )
    {
      if ( ++result >= dword_5C329C )
        return result;
    }
    v1 = dword_7C54F0[result];
    v2 = *(_DWORD *)(LODWORD(v1) + 16484);
    result = LODWORD(v1) + 16436;
    if ( v2 != 3 )
      *(_DWORD *)(result + 48) = 1;
  }
  return result;
}

