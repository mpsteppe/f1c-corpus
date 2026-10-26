// f1c  0x004b2b60  size=23
unsigned int __thiscall sub_4B2B60(_DWORD *this, int a2)
{
  unsigned int result; // eax

  result = (a2 << 15) | this[12] & 0xFFC07FFF;
  this[12] = result;
  return result;
}
