int __thiscall sub_4BD760(_DWORD *this)
{
  int result; // eax
  _DWORD *i; // edx

  result = 0;
  for ( i = this + 56; *i != -1; ++i )
  {
    if ( ++result >= 10 )
      return result;
  }
  this[result + 56] = this[2];
  return result;
}
