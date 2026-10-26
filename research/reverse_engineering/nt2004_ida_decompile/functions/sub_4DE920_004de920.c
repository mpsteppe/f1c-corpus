int __thiscall sub_4DE920(_DWORD *this)
{
  int result; // eax
  _DWORD *i; // edx

  result = 0;
  for ( i = this + 83; *i != -1; ++i )
  {
    if ( ++result >= 10 )
      return result;
  }
  this[result + 83] = this[3];
  return result;
}
