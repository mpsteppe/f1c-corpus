int __stdcall sub_695AC0(_DWORD *a1)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int v6; // eax
  int v7; // eax

  while ( 1 )
  {
    while ( 1 )
    {
      if ( !a1 )
        return 1;
      v2 = a1[1];
      if ( v2 != 1 )
        break;
      if ( !sub_695AC0(a1[2]) )
        return 0;
      a1 = (_DWORD *)a1[3];
    }
    if ( v2 == 14 )
      return a1[4] != 6;
    if ( v2 != 13 )
      return 1;
    v3 = a1[7];
    if ( v3 < 20 )
      break;
    if ( v3 <= 21 || v3 == 25 )
      return 0;
    if ( v3 == 26 )
    {
      v6 = *(_DWORD *)(*(_DWORD *)(a1[8] + 8) + 24);
      if ( v6 > 70 )
      {
        if ( v6 >= 73 && (v6 <= 75 || v6 > 77 && (v6 <= 80 || v6 > 82 && v6 <= 85)) )
          return 0;
      }
      else if ( v6 >= 68 || v6 == 9 || v6 == 26 || v6 == 40 || v6 == 61 )
      {
        return 0;
      }
      if ( sub_695AC0(*(_DWORD *)(a1[9] + 8)) )
      {
        v7 = sub_695AC0(*(_DWORD *)(a1[9] + 12));
        return v7 != 0;
      }
      return 0;
    }
    if ( v3 != 27 )
      break;
    v4 = a1[9];
    if ( !v4 || *(_DWORD *)(v4 + 4) != 13 )
      return 0;
    a1 = *(_DWORD **)(v4 + 36);
  }
  if ( !sub_695AC0(a1[8]) )
    return 0;
  v7 = sub_695AC0(a1[9]);
  return v7 != 0;
}
