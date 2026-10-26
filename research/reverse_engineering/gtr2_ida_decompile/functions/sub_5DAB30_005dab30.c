int __thiscall sub_5DAB30(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  _DWORD *v4; // ecx
  int v5; // eax

  v2 = this[112];
  v3 = a2;
  if ( a2 >= v2 )
  {
    v5 = a2 - v2;
    if ( a2 - v2 < 0 || v5 >= this[116] )
      return 0;
    v4 = (_DWORD *)this[113];
    if ( v5 > 0 )
    {
      while ( v4 )
      {
        v4 = (_DWORD *)v4[1];
        if ( --v5 <= 0 )
          goto LABEL_13;
      }
      return 0;
    }
  }
  else
  {
    if ( a2 < 0 || a2 >= v2 )
      return 0;
    v4 = (_DWORD *)this[109];
    if ( a2 > 0 )
    {
      while ( v4 )
      {
        v4 = (_DWORD *)v4[1];
        if ( --v3 <= 0 )
          goto LABEL_13;
      }
      return 0;
    }
  }
LABEL_13:
  if ( !v4 )
    return 0;
  return *v4;
}
