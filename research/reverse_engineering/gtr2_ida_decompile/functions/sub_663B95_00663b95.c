int __stdcall sub_663B95(_DWORD *a1)
{
  int result; // eax

  if ( !a1 )
    return 0;
  if ( a1[1] == 6 )
    return a1[5] + 16;
  if ( a1[1] == 11 )
    return 0;
  if ( a1[1] != 12 )
  {
    if ( a1[1] == 13 )
      return (int)(a1 + 12);
    return 0;
  }
  result = sub_663B95(a1[5]);
  if ( !result )
  {
    result = sub_663B95(a1[6]);
    if ( !result )
    {
      result = sub_663B95(a1[7]);
      if ( !result )
      {
        result = sub_663B95(a1[8]);
        if ( !result )
          return 0;
      }
    }
  }
  return result;
}
