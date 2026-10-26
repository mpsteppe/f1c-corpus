int __thiscall sub_600C50(int *this, int a2, int a3)
{
  int result; // eax

  if ( a2 == 1 )
  {
    result = a3;
    this[9] = a3;
  }
  else
  {
    if ( a2 == 2 )
    {
      result = *this | 0x400;
      this[13] = a3;
      *this = result;
      return result;
    }
    result = a2 - 3;
    if ( a2 == 3 )
    {
      this[17] = a3;
      return off_16C9828(3, a3);
    }
  }
  *this |= 0x400u;
  return result;
}
