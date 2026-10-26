unsigned int __thiscall sub_4D0530(_DWORD *this, int a2)
{
  unsigned int result; // eax

  result = (a2 << 18) | this[1] & 0xFF03FFFF;
  this[1] = result;
  return result;
}
