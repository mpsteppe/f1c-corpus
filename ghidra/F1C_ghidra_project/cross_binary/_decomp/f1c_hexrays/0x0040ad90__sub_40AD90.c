// f1c  0x0040ad90  size=19
int __thiscall sub_40AD90(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 >= 0 && a2 < this[4] )
    this[5] = a2;
  return result;
}
