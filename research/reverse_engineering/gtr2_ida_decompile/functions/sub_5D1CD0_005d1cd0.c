float *__fastcall sub_5D1CD0(float *a1, float *a2, float *a3)
{
  float *result; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st5

  result = a1;
  v4 = a3[3] * a2[3] - *a2 * *a3 - a3[1] * a2[1] - a3[2] * a2[2];
  v5 = a2[2] * a3[3] + a3[2] * a2[3] + a3[1] * *a2 - a2[1] * *a3;
  v6 = a2[1] * a3[3] + a2[2] * *a3 + a3[1] * a2[3] - a3[2] * *a2;
  *a1 = a3[3] * *a2 + *a3 * a2[3] + a3[2] * a2[1] - a3[1] * a2[2];
  a1[1] = v6;
  a1[2] = v5;
  a1[3] = v4;
  return result;
}
