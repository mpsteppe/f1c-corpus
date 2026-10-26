float *__stdcall sub_5ACCE0(float *a1, int a2, float *a3, int a4, float *a5, int a6)
{
  float *v6; // esi
  int v7; // edi
  float *v9; // ecx
  double v11; // st7
  int v12; // edx
  double v13; // st7
  float v15; // [esp+14h] [ebp-10h]
  float v16; // [esp+18h] [ebp-Ch]
  float v17; // [esp+2Ch] [ebp+8h]

  v6 = a1;
  v7 = a6;
  if ( a6 )
  {
    v9 = a5;
    do
    {
      v15 = v9[4] * a3[1] + *a3 * *v9 + v9[12];
      v16 = v9[1] * *a3 + v9[5] * a3[1] + v9[13];
      v11 = v9[3] * *a3 + v9[7] * a3[1] + v9[15];
      *v6 = v15;
      v6[1] = v16;
      v17 = v11;
      if ( !sub_5A9357(v17, 1.0) )
      {
        v13 = 1.0 / v17;
        *v6 = v13 * *v6;
        v6[1] = v13 * v6[1];
      }
      a3 = (float *)(a4 + v12);
      v6 = (float *)((char *)v6 + a2);
      --v7;
    }
    while ( v7 );
  }
  return a1;
}
