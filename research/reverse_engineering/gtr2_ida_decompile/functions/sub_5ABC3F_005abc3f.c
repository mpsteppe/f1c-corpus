float *__stdcall sub_5ABC3F(float *a1, float a2, float a3, float a4, float a5, float a6, float a7)
{
  float *result; // eax
  double v8; // st7
  double v9; // st6
  double v10; // st7

  result = a1;
  v8 = 1.0 / (a3 - a2);
  v9 = 1.0 / (a5 - a4);
  *a1 = v8 * a6 * 2.0;
  a1[1] = 0.0;
  a1[2] = 0.0;
  a1[3] = 0.0;
  a1[4] = 0.0;
  a1[5] = v9 * a6 * 2.0;
  a1[6] = 0.0;
  a1[7] = 0.0;
  a1[8] = -((a2 + a3) * v8);
  a1[9] = -((a4 + a5) * v9);
  v10 = a7 / (a7 - a6);
  a1[10] = v10;
  a1[11] = 1.0;
  a1[12] = 0.0;
  a1[13] = 0.0;
  a1[14] = -(v10 * a6);
  a1[15] = 0.0;
  return result;
}
