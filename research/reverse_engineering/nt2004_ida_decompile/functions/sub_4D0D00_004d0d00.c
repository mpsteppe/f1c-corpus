int __thiscall sub_4D0D00(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int result; // eax

  result = a5 + ((a4 + ((a3 + ((dword_75CBB0 + 16 * (a7 + 4 * a2)) << 6)) << 10)) << 6);
  *this = result;
  this[1] = a6;
  this[51] = -1;
  return result;
}
