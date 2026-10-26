int __thiscall sub_5E3A50(unsigned int *this, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( a2 == 8 )
  {
    *this = *this & 0xFFFFFFF3 | 8;
    result = a3;
    if ( a3 < 1 )
    {
      this[2] = -1;
      return result;
    }
    goto LABEL_6;
  }
  if ( a2 == 4 )
  {
    result = a3;
    *this = *this & 0xFFFFFFF3 | 4;
LABEL_6:
    this[2] = result;
    return result;
  }
  *this &= 0xFFFFFFF3;
  this[2] = 1;
  return result;
}
