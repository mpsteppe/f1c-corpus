int __thiscall sub_5E8520(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // esi
  _DWORD *i; // edx

  result = a2;
  if ( a2 )
  {
    v3 = this[64];
    this[275] = a2;
    result = 0;
    if ( v3 > 0 )
    {
      v4 = this[65];
      for ( i = (_DWORD *)(v4 + 96); *i != 11; i += 121 )
      {
        if ( ++result >= this[64] )
          return result;
      }
      result *= 484;
      *(_DWORD *)(result + v4 + 96) = 13;
    }
  }
  return result;
}
