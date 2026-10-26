float *__thiscall sub_5299C0(float *this, float *a2, int a3)
{
  double v4; // st7
  float *result; // eax

  v4 = sub_529A00(a3);
  result = a2;
  *a2 = v4 * this[11] + this[49];
  a2[2] = v4 * this[13] + this[51];
  a2[1] = v4 * this[12] + this[50];
  return result;
}
