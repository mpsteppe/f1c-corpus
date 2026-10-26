BOOL __thiscall sub_695154(_DWORD *this, _DWORD *a2)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          if ( !a2 )
            return 1;
          v4 = a2[1];
          if ( v4 != 1 )
            break;
          if ( !sub_695154(a2[2]) )
            return 0;
          a2 = (_DWORD *)a2[3];
        }
        v5 = v4 - 6;
        if ( v5 )
          break;
        a2 = (_DWORD *)a2[6];
      }
      v6 = v5 - 2;
      if ( v6 )
        break;
      a2 = (_DWORD *)a2[4];
    }
    v7 = v6 - 1;
    if ( !v7 )
      break;
    if ( v7 != 2 )
    {
      sub_694C3A(this, 0, 0, "internal error: unknown node");
      return 0;
    }
    a2 = (_DWORD *)a2[8];
  }
  return a2[4] <= 2u;
}
