int __thiscall sub_4D3760(_BYTE *this, int a2, int a3)
{
  int result; // eax

  result = a3 / 8;
  this[7 * a2 + 29 + a3 / 8] |= 1 << (a3 % 8);
  return result;
}
