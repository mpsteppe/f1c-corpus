int __thiscall sub_595A30(float *this, int a2, int a3, int a4)
{
  int result; // eax

  this[98] = (double)a2 * 0.0039215689;
  this[99] = (double)a3 * 0.0039215689;
  this[100] = (double)a4 * 0.0039215689;
  result = dword_7E8E5C;
  *(_DWORD *)(dword_7E8E5C + 240) |= 0x800u;
  return result;
}
