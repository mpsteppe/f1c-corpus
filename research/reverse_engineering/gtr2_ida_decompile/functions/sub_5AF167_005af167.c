float *__stdcall sub_5AF167(float *a1, float *a2, float *a3)
{
  double v3; // st6
  double v4; // st7

  v3 = *a2 * a3[1] + a2[1] * a3[5] + a2[2] * a3[9];
  v4 = *a2 * a3[2] + a2[1] * a3[6] + a2[2] * a3[10];
  *a1 = *a2 * *a3 + a2[1] * a3[4] + a2[2] * a3[8];
  a1[1] = v3;
  a1[2] = v4;
  return a1;
}
