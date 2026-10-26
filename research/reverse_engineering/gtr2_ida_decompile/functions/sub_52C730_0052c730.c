int __thiscall sub_52C730(_DWORD *this)
{
  int result; // eax
  _DWORD *i; // edx

  result = 0;
  for ( i = this + 84; *i != -1; ++i )
  {
    if ( ++result >= 10 )
      return result;
  }
  this[result + 84] = this[3];
  return result;
}
