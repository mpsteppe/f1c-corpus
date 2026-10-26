int __thiscall sub_5DB5B0(int *this, int a2, int a3)
{
  int result; // eax

  result = a3;
  if ( (a3 & 0x800) != 0 )
    return off_16C9204(a2, a3);
  if ( (a3 & 0x1000) != 0 )
  {
    result = *this | 0x1000;
    this[162] = a2;
    *this = result;
  }
  return result;
}
