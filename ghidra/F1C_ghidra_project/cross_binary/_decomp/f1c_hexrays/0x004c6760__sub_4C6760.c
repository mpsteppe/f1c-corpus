// f1c  0x004c6760  size=19
int __thiscall sub_4C6760(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 >= 0 && a2 < this[5] )
    this[6] = a2;
  return result;
}
