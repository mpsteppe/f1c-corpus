BOOL __stdcall sub_695259(_DWORD *a1, _DWORD *a2)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  while ( 1 )
  {
    while ( 1 )
    {
      if ( !a1 )
        return a2 == 0;
      v4 = a1[1];
      if ( v4 != 1 )
        break;
      if ( !a2 )
        return 0;
      if ( a2[1] != 1 )
        break;
      if ( !sub_695259(a1[2], a2[2]) )
        return 0;
      a1 = (_DWORD *)a1[3];
      a2 = (_DWORD *)a2[3];
    }
    if ( !a2 || v4 != a2[1] )
      break;
    v5 = v4 - 6;
    if ( v5 )
    {
      v6 = v5 - 2;
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( !v7 )
          return a1[4] == a2[4] && a1[5] == a2[5] && a1[6] == a2[6] && a1[7] == a2[7];
        if ( v7 != 2 )
          return 0;
        a2 = (_DWORD *)a2[8];
        a1 = (_DWORD *)a1[8];
      }
      else
      {
        if ( a1[5] != a2[5] )
          return 0;
        a2 = (_DWORD *)a2[4];
        a1 = (_DWORD *)a1[4];
      }
    }
    else
    {
      a2 = (_DWORD *)a2[6];
      a1 = (_DWORD *)a1[6];
    }
  }
  return 0;
}
