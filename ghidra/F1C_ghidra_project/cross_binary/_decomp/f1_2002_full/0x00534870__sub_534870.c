// f1_2002_full  0x00534870  size=55
int __thiscall sub_534870(int *this, int a2, int a3)
{
  int result; // eax

  result = a3;
  if ( (a3 & 0x800) != 0 )
  {
    result = a2;
    this[137] = a2;
    *this |= 0x800u;
  }
  else if ( (a3 & 0x1000) != 0 )
  {
    result = *this | 0x1000;
    this[138] = a2;
    *this = result;
  }
  return result;
}
