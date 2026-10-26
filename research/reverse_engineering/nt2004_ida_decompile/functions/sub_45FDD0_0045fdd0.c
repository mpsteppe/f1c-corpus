int __thiscall sub_45FDD0(_DWORD *this)
{
  int result; // eax
  _DWORD *i; // ecx

  result = 0;
  for ( i = this + 111; *i != -1; ++i )
  {
    if ( ++result >= 48 )
      return -1;
  }
  return result;
}
