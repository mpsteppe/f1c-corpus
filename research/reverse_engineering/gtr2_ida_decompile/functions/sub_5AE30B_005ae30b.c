float *__stdcall sub_5AE30B(float *a1, float *a2, float *a3, float a4, float *a5)
{
  float *result; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // st6
  float v10; // [esp+8h] [ebp-Ch]
  float v11; // [esp+Ch] [ebp-8h]

  result = a5;
  *a5 = *a1;
  a5[1] = a1[1];
  a5[2] = a1[2];
  *a5 = *a5 - *a2;
  a5[1] = a5[1] - a2[1];
  v6 = a5[2] - a2[2];
  a5[2] = v6;
  v7 = v6 * a3[2] + *a3 * *result + result[1] * a3[1];
  v10 = v7 * *a3;
  v11 = v7 * a3[1];
  a5[2] = v6 - v7 * a3[2];
  v8 = (*a5 - v10) * a4;
  *a5 = v8;
  v9 = (a5[1] - v11) * a4;
  a5[1] = v9;
  a5[2] = a4 * a5[2];
  *a5 = v8 + *a2;
  a5[1] = v9 + a2[1];
  a5[2] = a2[2] + a5[2];
  return result;
}
