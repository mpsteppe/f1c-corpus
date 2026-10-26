unsigned int __thiscall sub_51A240(_DWORD *this, int a2)
{
  unsigned int result; // eax

  result = (a2 << 15) | this[1] & 0xFFC07FFF;
  this[1] = result;
  return result;
}
