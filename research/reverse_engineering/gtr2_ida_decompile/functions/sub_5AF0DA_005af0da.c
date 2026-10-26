float *__stdcall sub_5AF0DA(float *a1, float *a2, float *a3)
{
  double v3; // st5
  double v4; // st6
  double v5; // st7

  v3 = *a2 * a3[1] + a2[1] * a3[5] + a2[2] * a3[9] + a3[13];
  v4 = *a2 * a3[2] + a2[1] * a3[6] + a2[2] * a3[10] + a3[14];
  v5 = *a2 * a3[3] + a2[1] * a3[7] + a2[2] * a3[11] + a3[15];
  *a1 = *a2 * *a3 + a2[1] * a3[4] + a2[2] * a3[8] + a3[12];
  a1[1] = v3;
  a1[2] = v4;
  a1[3] = v5;
  return a1;
}
