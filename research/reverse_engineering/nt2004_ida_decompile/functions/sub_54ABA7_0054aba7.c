float *__stdcall sub_54ABA7(float *a1, float *a2, float *a3)
{
  double v3; // st5
  double v4; // st6
  double v5; // st7

  v3 = a3[3] * a2[1] - *a3 * a2[2] + a3[1] * a2[3] + a3[2] * *a2;
  v4 = a3[3] * a2[2] + *a3 * a2[1] - a3[1] * *a2 + a3[2] * a2[3];
  v5 = a3[3] * a2[3] - *a3 * *a2 - a3[1] * a2[1] - a3[2] * a2[2];
  *a1 = a3[3] * *a2 + *a3 * a2[3] + a3[1] * a2[2] - a3[2] * a2[1];
  a1[1] = v3;
  a1[2] = v4;
  a1[3] = v5;
  return a1;
}
