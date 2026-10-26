int __thiscall sub_6AEC2C(_DWORD *this)
{
  int result; // eax

  if ( this[86] )
    result = sub_6C9357(this[50] & 0x7FFFFFFF);
  else
    result = sub_6C9357(this[50]);
  if ( result >= 0 )
  {
    result = sub_6C64E6(this);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
