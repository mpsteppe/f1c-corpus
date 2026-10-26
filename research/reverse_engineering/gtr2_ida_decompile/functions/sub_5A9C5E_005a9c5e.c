float *__stdcall sub_5A9C5E(float *a1, int a2, float *a3, int a4, float *a5, int a6)
{
  float *v6; // ebx
  float *v7; // ecx
  double v9; // st7
  int v10; // edx
  double v11; // st7
  float v13; // [esp+14h] [ebp-10h]
  float v14; // [esp+18h] [ebp-Ch]
  float v15; // [esp+1Ch] [ebp-8h]
  float v17; // [esp+2Ch] [ebp+8h]

  v6 = a1;
  if ( a6 )
  {
    v7 = a5;
    do
    {
      v13 = v7[4] * a3[1] + v7[8] * a3[2] + *a3 * *v7 + v7[12];
      v14 = v7[1] * *a3 + v7[5] * a3[1] + v7[9] * a3[2] + v7[13];
      v15 = a3[2] * v7[10] + *a3 * v7[2] + a3[1] * v7[6] + v7[14];
      v9 = v7[3] * *a3 + v7[7] * a3[1] + v7[11] * a3[2] + v7[15];
      *v6 = v13;
      v6[1] = v14;
      v17 = v9;
      v6[2] = v15;
      if ( !sub_5A9357(v17, 1.0) )
      {
        v11 = 1.0 / v17;
        *v6 = v11 * *v6;
        v6[1] = v11 * v6[1];
        v6[2] = v11 * v6[2];
      }
      a3 = (float *)(a4 + v10);
      v6 = (float *)((char *)v6 + a2);
      --a6;
    }
    while ( a6 );
  }
  return a1;
}
