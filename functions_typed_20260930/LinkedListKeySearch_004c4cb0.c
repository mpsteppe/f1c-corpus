char __thiscall sub_4C4CB0(_DWORD *this, int a2)
{
  _DWORD **v2; // edx
  char result; // al
  _DWORD *v4; // edx
  int v5; // edx
  _DWORD **v6; // edx

  v2 = (_DWORD **)this[2];
  result = 0;
  this[4] = v2;
  if ( v2 )
  {
    v4 = *v2;
    if ( v4 )
    {
      while ( a2 != *v4 )
      {
        v5 = this[4];
        if ( v5 )
          this[4] = *(_DWORD *)(v5 + 4);
        v6 = (_DWORD **)this[4];
        if ( v6 )
        {
          v4 = *v6;
          if ( v4 )
            continue;
        }
        return result;
      }
      return 1;
    }
  }
  return result;
}

