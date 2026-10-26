BOOL __stdcall sub_695A44(_DWORD *a1)
{
  int v2; // eax
  int v3; // eax
  bool v5; // cc

  while ( 1 )
  {
    while ( 1 )
    {
      if ( !a1 )
        return 0;
      v2 = a1[1];
      if ( v2 != 1 )
        break;
      if ( sub_695A44(a1[2]) )
        return 1;
      a1 = (_DWORD *)a1[3];
    }
    if ( v2 == 14 )
      return a1[4] != 6;
    if ( v2 != 13 )
      return 0;
    v3 = a1[7];
    if ( v3 > 23 )
      break;
    if ( v3 < 22 )
    {
      if ( v3 < 0 )
        return 1;
      if ( v3 > 1 )
      {
        if ( v3 > 19 )
        {
          v5 = v3 <= 21;
          return !v5;
        }
        return 1;
      }
    }
    a1 = (_DWORD *)a1[8];
  }
  if ( v3 < 25 )
    return 1;
  v5 = v3 <= 26;
  return !v5;
}
