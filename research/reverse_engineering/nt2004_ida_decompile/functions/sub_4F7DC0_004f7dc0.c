int __thiscall sub_4F7DC0(_DWORD *this, int a2, float a3, int a4)
{
  int result; // eax

  this[2 * this[96]] = a2;
  *(float *)&this[2 * this[96] + 1] = a3;
  result = this[96] + 1;
  this[96] = result;
  return result;
}
