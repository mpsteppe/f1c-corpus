int __thiscall sub_54C110(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = a3;
  if ( (a3 & 0x800) != 0 )
  {
    result = a2;
    this[141] = a2;
    this[15] |= 0x800u;
  }
  else if ( (a3 & 0x1000) != 0 )
  {
    result = this[15] | 0x1000;
    this[142] = a2;
    this[15] = result;
  }
  return result;
}
