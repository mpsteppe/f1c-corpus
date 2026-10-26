int __thiscall sub_5A3330(_DWORD *this)
{
  int result; // eax

  if ( (this[25] & 0x20000) != 0 )
  {
    result = this[1070];
    if ( result )
      return sub_5AB000(this[1070]);
  }
  return result;
}
