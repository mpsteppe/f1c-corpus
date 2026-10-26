int __thiscall sub_51B2A0(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v7; // kr00_4
  int result; // eax

  v7 = __readeflags();
  __writeeflags(v7);
  *this = a5 + ((a4 + ((a3 + ((*(_DWORD *)(dword_16C6EB8 - 1442830849) + 8 * (a7 + 4 * a2)) << 6)) << 10)) << 8);
  this[1] = a6;
  result = sub_473680(&dword_B6CBA8);
  this[211] = result;
  return result;
}
