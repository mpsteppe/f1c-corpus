int __thiscall sub_593D50(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  result = a4 + ((a3 + (a2 << 8)) << 8);
  this[31] = result;
  return result;
}
