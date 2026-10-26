int __thiscall sub_479D00(_DWORD *this, int a2)
{
  int v2; // eax
  int result; // eax
  _DWORD *i; // ecx
  _DWORD *j; // ecx

  v2 = this[28332];
  if ( v2 == 2 || v2 == 1 )
  {
    result = 0;
    for ( i = this + 424; a2 != *i; ++i )
    {
      if ( ++result >= 104 )
        return 104;
    }
  }
  else
  {
    result = 0;
    for ( j = this + 28222; a2 != *j; ++j )
    {
      if ( ++result >= 104 )
        return 104;
    }
  }
  return result;
}
