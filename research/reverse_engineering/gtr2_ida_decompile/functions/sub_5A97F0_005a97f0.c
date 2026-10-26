float *__stdcall sub_5A97F0(float *a1, int a2, float *a3, int a4, float *a5, int a6)
{
  float *v6; // esi
  int v7; // edi
  float *result; // eax
  double v10; // st7
  double v11; // st6
  float v12; // [esp+8h] [ebp-8h]
  float v13; // [esp+Ch] [ebp-4h]

  v6 = a1;
  v7 = a6;
  for ( result = a1; v7; --v7 )
  {
    v12 = a5[4] * a3[1] + *a3 * *a5;
    v10 = a5[1] * *a3;
    v11 = a5[5] * a3[1];
    a3 = (float *)((char *)a3 + a4);
    *v6 = v12;
    v13 = v10 + v11;
    v6[1] = v13;
    v6 = (float *)((char *)v6 + a2);
  }
  return result;
}
