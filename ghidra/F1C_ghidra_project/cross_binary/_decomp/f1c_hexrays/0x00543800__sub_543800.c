// f1c  0x00543800  size=99
int __thiscall sub_543800(float *this, int a2, int a3, int a4)
{
  int result; // eax

  this[95] = (double)a2 * 0.0039215689;
  this[96] = (double)a3 * 0.0039215689;
  this[97] = (double)a4 * 0.0039215689;
  sub_541670((_DWORD **)dword_8B78A0, a4 + ((a3 + (a2 << 8)) << 8));
  result = dword_8B8F28;
  *(_DWORD *)(dword_8B8F28 + 236) |= 0x800u;
  return result;
}
