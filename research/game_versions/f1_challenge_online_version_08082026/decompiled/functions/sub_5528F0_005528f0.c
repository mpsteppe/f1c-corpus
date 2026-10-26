int __thiscall sub_5528F0(_DWORD *this)
{
  int result; // eax

  if ( (this[9] & 0x20000) != 0 )
  {
    result = this[538];
    if ( result )
      return sub_554D70(this[538]);
  }
  return result;
}
