void __stdcall sub_4F3390(float *a1, float *a2, float *a3, float *a4)
{
  double v4; // st6
  double v5; // st7
  double v6; // st7
  double v7; // st6
  long double v8; // st4
  long double v9; // st7
  long double v10; // st6
  long double v11; // st5
  float v12; // [esp+4h] [ebp-24h]
  float v13; // [esp+4h] [ebp-24h]
  float v14; // [esp+8h] [ebp-20h]
  float v15; // [esp+Ch] [ebp-1Ch]
  float v16; // [esp+10h] [ebp-18h]
  float v17; // [esp+10h] [ebp-18h]
  float v18; // [esp+14h] [ebp-14h]
  float v19; // [esp+14h] [ebp-14h]
  float v20; // [esp+18h] [ebp-10h]
  float v21; // [esp+18h] [ebp-10h]
  float v22; // [esp+18h] [ebp-10h]
  float v23; // [esp+24h] [ebp-4h]
  float v24; // [esp+24h] [ebp-4h]

  v18 = *(float *)&dword_611390 * a3[1];
  v20 = *(float *)&dword_611390 * a3[2];
  v4 = a4[1] - v18;
  v23 = a4[2] - v20;
  v21 = a3[2] * 0.5;
  v12 = *a3 * 0.5 * *a2;
  v16 = *a1 - v12;
  v19 = a1[1] - a3[1] * 0.5 * *a2;
  v22 = a1[2] - v21 * *a2;
  v13 = v16 - (*a4 - *(float *)&dword_611390 * *a3);
  v14 = v19 - v4;
  v5 = v22 - v23;
  v15 = v5;
  if ( v5 * v15 + v14 * v14 + v13 * v13 < flt_611394 )
  {
    v6 = v15 * a3[2] + v14 * a3[1] + v13 * *a3;
    v24 = v6 * a3[2];
    v17 = v13 - v6 * *a3;
    v7 = v14 - v6 * a3[1];
    v8 = flt_611394 - ((v15 - v24) * (v15 - v24) + v7 * v7 + v17 * v17);
    if ( v8 > 0.0 )
    {
      v9 = sqrt(v8) - v6;
      if ( v9 > 0.0 )
      {
        *a1 = v9 * *a3 + *a1;
        v10 = v9 * a3[1];
        v11 = *a2 * 0.5;
        if ( v11 >= v10 )
          v11 = v10;
        *a2 = *a2 - v11;
        a1[1] = v10 - v11 * 0.5 + a1[1];
        a1[2] = v9 * a3[2] + a1[2];
      }
    }
  }
}
