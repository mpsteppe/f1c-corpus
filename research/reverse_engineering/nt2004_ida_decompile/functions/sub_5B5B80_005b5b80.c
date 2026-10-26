int __thiscall sub_5B5B80(_DWORD *this, int a2)
{
  int result; // eax

  this[20] = a2;
  result = dword_7E8E5C;
  *(_DWORD *)(dword_7E8E5C + 240) |= 0x800u;
  return result;
}
