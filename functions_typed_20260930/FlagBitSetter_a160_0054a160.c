unsigned int __thiscall sub_54A160(_DWORD *this, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 == 4096 )
  {
    this[59] = this[59] & 0xFFFFCFFF | 0x1000;
  }
  else if ( a2 == 0x2000 )
  {
    result = this[59] & 0xFFFFCFFF | 0x2000;
    this[59] = result;
  }
  return result;
}

