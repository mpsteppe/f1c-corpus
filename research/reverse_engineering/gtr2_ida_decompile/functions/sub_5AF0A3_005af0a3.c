float *__stdcall sub_5AF0A3(float *a1, float *a2, float *a3)
{
  double v3; // st7

  v3 = *a2 * a3[1] + a2[1] * a3[5];
  *a1 = *a2 * *a3 + a2[1] * a3[4];
  a1[1] = v3;
  return a1;
}
