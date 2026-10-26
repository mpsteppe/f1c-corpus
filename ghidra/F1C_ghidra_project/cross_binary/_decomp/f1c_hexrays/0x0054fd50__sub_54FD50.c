// f1c  0x0054fd50  size=80
int __thiscall sub_54FD50(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( a2 == 8 )
  {
    this[16] = this[16] & 0xFFFFFFF3 | 8;
    result = a3;
    if ( a3 < 1 )
    {
      this[17] = -1;
      return result;
    }
    goto LABEL_6;
  }
  if ( a2 == 4 )
  {
    result = a3;
    this[16] = this[16] & 0xFFFFFFF3 | 4;
LABEL_6:
    this[17] = result;
    return result;
  }
  this[16] &= 0xFFFFFFF3;
  this[17] = 1;
  return result;
}
