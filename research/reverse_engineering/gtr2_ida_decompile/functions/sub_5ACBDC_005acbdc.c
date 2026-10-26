float *__stdcall sub_5ACBDC(float *a1, int a2, float *a3, int a4, float *a5, int a6)
{
  int v6; // eax
  float *i; // ebx
  float *v9; // edi
  double v10; // st7
  double v11; // st6
  float v13; // [esp+4h] [ebp-10h]
  float v14; // [esp+8h] [ebp-Ch]
  float v15; // [esp+Ch] [ebp-8h]
  float v16; // [esp+10h] [ebp-4h]

  v6 = a6;
  for ( i = a1; v6; v9[1] = v16 )
  {
    v9 = i;
    i = (float *)((char *)i + a2);
    v13 = a5[4] * a3[1] + *a3 * *a5 + a5[12];
    v14 = a5[1] * *a3 + a5[5] * a3[1] + a5[13];
    v15 = a5[2] * *a3 + a5[6] * a3[1] + a5[14];
    v10 = *a3 * a5[3];
    v11 = a3[1];
    a3 = (float *)((char *)a3 + a4);
    --v6;
    v16 = v10 + v11 * a5[7] + a5[15];
    *v9++ = v13;
    *v9++ = v14;
    *v9 = v15;
  }
  return a1;
}
