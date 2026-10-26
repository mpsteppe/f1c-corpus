float *__stdcall sub_5A979F(float *a1, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st6
  float *result; // eax
  float v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+4h] [ebp-4h]

  v6 = a3[4] * a2[1] + *a2 * *a3;
  v3 = a3[1] * *a2;
  v4 = a3[5] * a2[1];
  result = a1;
  *a1 = v6;
  v7 = v3 + v4;
  a1[1] = v7;
  return result;
}
