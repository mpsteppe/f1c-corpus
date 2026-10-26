float *__fastcall sub_5BC0A0(float *a1, float *a2, double a3)
{
  float *result; // eax
  double v4; // st7
  double v5; // st6

  result = a1;
  v4 = a2[2] * a3;
  v5 = a2[1] * a3;
  *a1 = *a2 * a3;
  a1[1] = v5;
  a1[2] = v4;
  return result;
}
