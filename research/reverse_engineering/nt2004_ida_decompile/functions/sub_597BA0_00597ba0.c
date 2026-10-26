unsigned int __thiscall sub_597BA0(_DWORD *this, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      result = this[60] & 0xFF9FFFFF | 0x200000;
      this[60] = result;
    }
    else if ( a2 == 2 )
    {
      this[60] = this[60] & 0xFF9FFFFF | 0x400000;
    }
  }
  else
  {
    this[60] &= 0xFF9FFFFF;
  }
  return result;
}
