int __thiscall sub_4B4800(_BYTE *this, int a2, int a3)
{
  int result; // eax

  result = a3 / 8;
  this[13 * a2 + 53 + a3 / 8] |= 1 << (a3 % 8);
  return result;
}
