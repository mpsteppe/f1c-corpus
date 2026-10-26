int __thiscall sub_5B5B50(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  this[14] = a2;
  this[15] = a3;
  this[16] = a4;
  result = dword_7E8E5C;
  *(_DWORD *)(dword_7E8E5C + 240) |= 0x800u;
  return result;
}
