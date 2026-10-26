int __thiscall sub_431A70(float *this, int a2, int a3, float a4)
{
  int result; // eax

  result = a3 + 2 * (a2 + 617) + a2 + 617;
  this[result] = a4;
  *((_BYTE *)this + a2 + 7400) = 1;
  return result;
}
