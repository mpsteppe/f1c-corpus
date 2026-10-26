float *__thiscall sub_5D0760(__int16 *this, float *a2)
{
  int v2; // edx
  double v3; // st7
  float *result; // eax
  double v5; // st5

  v2 = this[2];
  v3 = (double)this[3] * 0.000030518509;
  result = a2;
  v5 = (double)this[1];
  *a2 = (double)*this * 0.000030518509;
  a2[1] = v5 * 0.000030518509;
  a2[2] = (double)v2 * 0.000030518509;
  a2[3] = v3;
  return result;
}
