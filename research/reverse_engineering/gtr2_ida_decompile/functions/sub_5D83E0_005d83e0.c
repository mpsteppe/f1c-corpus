int __thiscall sub_5D83E0(int *this, int a2, int a3, int a4)
{
  int result; // eax

  this[24] = a2;
  this[26] = a4;
  result = *this | 2;
  this[25] = a3;
  *this = result;
  return result;
}
