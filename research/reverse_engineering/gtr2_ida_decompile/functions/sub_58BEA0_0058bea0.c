int __thiscall sub_58BEA0(float *this, int a2, float a3, float a4)
{
  int result; // eax

  result = a2;
  this[2 * a2 + 31] = 1.0 / (a3 * 0.1047197551196598);
  this[2 * a2 + 32] = 1.0 / a4;
  return result;
}
