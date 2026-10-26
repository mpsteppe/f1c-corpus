void __stdcall sub_4CBDD0(float *a1, float *a2, float a3, float *a4)
{
  double v4; // st7
  double v5; // st7
  double v6; // st6
  long double v7; // st4
  long double v8; // st7
  long double v9; // st6
  long double v10; // st5
  long double v11; // st7
  float v12; // [esp+0h] [ebp-24h]
  float v13; // [esp+4h] [ebp-20h]
  float v14; // [esp+4h] [ebp-20h]
  float v15; // [esp+8h] [ebp-1Ch]
  float v16; // [esp+8h] [ebp-1Ch]
  float v17; // [esp+8h] [ebp-1Ch]
  float v18; // [esp+Ch] [ebp-18h]
  float v19; // [esp+Ch] [ebp-18h]
  float v20; // [esp+14h] [ebp-10h]
  float v21; // [esp+20h] [ebp-4h]
  float v22; // [esp+20h] [ebp-4h]
  float v23; // [esp+20h] [ebp-4h]

  v13 = *(float *)&dword_5D3488 * a2[1];
  v15 = *(float *)&dword_5D3488 * a2[2];
  v21 = a4[2] - v15;
  v16 = a3 * a2[2];
  v18 = *a1 - a3 * *a2;
  v20 = a1[2] - v16;
  v12 = v18 - (*a4 - *(float *)&dword_5D3488 * *a2);
  v14 = a1[1] - a3 * a2[1] - (a4[1] - v13);
  v4 = v20 - v21;
  v17 = v4;
  if ( v4 * v17 + v14 * v14 + v12 * v12 < flt_5D348C )
  {
    v5 = v17 * a2[2] + v14 * a2[1] + v12 * *a2;
    v22 = v5 * a2[2];
    v19 = v12 - v5 * *a2;
    v6 = v14 - v5 * a2[1];
    v7 = flt_5D348C - ((v17 - v22) * (v17 - v22) + v6 * v6 + v19 * v19);
    if ( v7 > 0.0 )
    {
      v8 = sqrt(v7) - v5;
      if ( v8 > 0.0 )
      {
        v9 = v8 * *a2;
        v10 = v8;
        v11 = v8 * a2[1];
        v23 = v10 * a2[2];
        *a1 = v9 + *a1;
        a1[1] = v11 + a1[1];
        a1[2] = v23 + a1[2];
      }
    }
  }
}
