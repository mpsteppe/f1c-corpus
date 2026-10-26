float *__stdcall sub_5ABCE2(float *a1, float a2, float a3, float a4, float a5)
{
  float *result; // eax
  double v6; // st7

  result = a1;
  *a1 = 2.0 / a2;
  a1[1] = 0.0;
  a1[2] = 0.0;
  a1[3] = 0.0;
  a1[4] = 0.0;
  a1[5] = 2.0 / a3;
  a1[6] = 0.0;
  a1[7] = 0.0;
  a1[8] = 0.0;
  a1[9] = 0.0;
  v6 = 1.0 / (a5 - a4);
  a1[10] = v6;
  a1[11] = 0.0;
  a1[12] = 0.0;
  a1[13] = 0.0;
  a1[14] = -(v6 * a4);
  a1[15] = 1.0;
  return result;
}
