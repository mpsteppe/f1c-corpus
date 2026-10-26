unsigned int __thiscall sub_5953E0(_DWORD *this, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 == 4096 )
  {
    this[60] = this[60] & 0xFFFFCFFF | 0x1000;
  }
  else if ( a2 == 0x2000 )
  {
    result = this[60] & 0xFFFFCFFF | 0x2000;
    this[60] = result;
  }
  return result;
}
