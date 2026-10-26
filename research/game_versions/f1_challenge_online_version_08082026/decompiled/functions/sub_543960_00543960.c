int __thiscall sub_543960(_DWORD *this, int a2)
{
  int result; // eax

  if ( a2 == 0x20000 )
  {
    result = this[59] | 0x10000;
    this[103] = 0x20000;
    this[59] = result;
  }
  else if ( a2 == 0x40000 )
  {
    result = this[59] | 0x10000;
    this[103] = 0x40000;
    this[59] = result;
  }
  else
  {
    result = this[59] | 0x10000;
    if ( a2 == 0x80000 )
      this[103] = 0x80000;
    else
      this[103] = 0;
    this[59] = result;
  }
  return result;
}
