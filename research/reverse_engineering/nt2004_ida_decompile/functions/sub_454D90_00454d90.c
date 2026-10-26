int __thiscall sub_454D90(_DWORD *this, int a2, int a3)
{
  int result; // eax

  *this = 0;
  result = sub_454D10(this + 1, a2, a3);
  this[8] = 0;
  this[7] = 0;
  return result;
}
