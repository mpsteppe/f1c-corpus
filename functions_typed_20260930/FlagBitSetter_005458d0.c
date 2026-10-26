unsigned int __thiscall sub_5458D0(_DWORD *this, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      result = this[59] & 0xFF9FFFFF | 0x200000;
      this[59] = result;
    }
    else if ( a2 == 2 )
    {
      this[59] = this[59] & 0xFF9FFFFF | 0x400000;
    }
  }
  else
  {
    this[59] &= 0xFF9FFFFF;
  }
  return result;
}

