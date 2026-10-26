float *__stdcall sub_548EAC(float *a1, float *a2, float *a3, float *a4, float *a5, float a6)
{
  double v6; // st7
  float *result; // eax
  double v8; // st6
  double v9; // st7
  float v10; // [esp+0h] [ebp-8h]
  float v11; // [esp+4h] [ebp-4h]
  float v12; // [esp+24h] [ebp+1Ch]

  v6 = a6 * a6;
  result = a1;
  v8 = a6 * v6;
  v10 = v8 + v8 - v6 * 3.0 + 1.0;
  v11 = v8 - (v6 + v6) + a6;
  v12 = v6 * 3.0 - (v8 + v8);
  v9 = v8 - v6;
  *a1 = v10 * *a2 + v11 * *a3 + v12 * *a4 + v9 * *a5;
  a1[1] = v9 * a5[1] + v12 * a4[1] + v11 * a3[1] + v10 * a2[1];
  return result;
}
