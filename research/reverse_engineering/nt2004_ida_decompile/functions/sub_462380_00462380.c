int __thiscall sub_462380(_DWORD *this, int a2)
{
  int v2; // eax
  int result; // eax
  _DWORD *i; // ecx
  _DWORD *j; // ecx

  v2 = this[1680];
  if ( v2 == 2 || v2 == 1 )
  {
    result = 0;
    for ( i = this + 111; a2 != *i; ++i )
    {
      if ( ++result >= 48 )
        return 63;
    }
  }
  else
  {
    result = 0;
    for ( j = this + 1629; a2 != *j; ++j )
    {
      if ( ++result >= 48 )
        return 63;
    }
  }
  return result;
}
