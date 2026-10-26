// f1c  0x00499eb0  size=37
int __thiscall sub_499EB0(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = a3;
  this[24] = a2 < 0 ? 0 : a2;
  this[25] = a3 < 0 ? 0 : a3;
  return result;
}
