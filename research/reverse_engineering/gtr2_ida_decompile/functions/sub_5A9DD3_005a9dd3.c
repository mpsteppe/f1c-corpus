float *__stdcall sub_5A9DD3(float *a1, int a2, float *a3, int a4, float *a5, int a6)
{
  int v6; // eax
  float *i; // ebx
  float *v9; // edi
  double v10; // st7
  double v11; // st6
  float v13; // [esp+4h] [ebp-Ch]
  float v14; // [esp+8h] [ebp-8h]
  float v15; // [esp+Ch] [ebp-4h]

  v6 = a6;
  for ( i = a1; v6; v9[1] = v15 )
  {
    v9 = i;
    i = (float *)((char *)i + a2);
    v13 = a5[4] * a3[1] + a5[8] * a3[2] + *a3 * *a5;
    v14 = a5[1] * *a3 + a5[5] * a3[1] + a5[9] * a3[2];
    v10 = a3[2] * a5[10] + *a3 * a5[2];
    v11 = a3[1];
    a3 = (float *)((char *)a3 + a4);
    --v6;
    v15 = v10 + v11 * a5[6];
    *v9++ = v13;
    *v9 = v14;
  }
  return a1;
}
