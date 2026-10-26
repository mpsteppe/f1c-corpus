BOOL __fastcall sub_5C18D0(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6)
{
  double v7; // st4
  double v8; // st3
  double v9; // st4
  double v10; // st3
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st5
  double v15; // st3
  double v16; // st4
  double v17; // st3
  long double v18; // st4
  long double v19; // st7
  long double v20; // st6
  long double v21; // st6
  double v22; // st5
  double v23; // st4
  float v25; // [esp+Ch] [ebp-D8h]
  float v26; // [esp+10h] [ebp-D4h] BYREF
  float v27; // [esp+14h] [ebp-D0h]
  float v28; // [esp+18h] [ebp-CCh]
  float v29; // [esp+1Ch] [ebp-C8h]
  float v30; // [esp+20h] [ebp-C4h]
  float v31[16]; // [esp+24h] [ebp-C0h] BYREF
  float v32[16]; // [esp+64h] [ebp-80h] BYREF
  int v33[16]; // [esp+A4h] [ebp-40h] BYREF

  v26 = *a4 - *a1;
  v27 = a4[1] - a1[1];
  v28 = a4[2] - a1[2];
  v7 = a2[2] - a1[2];
  v8 = a2[1] - a1[1];
  v9 = v7 * v7 + v8 * v8;
  v10 = *a2 - *a1;
  v25 = sqrt(v9 + v10 * v10);
  v11 = *a3 - *a2;
  v12 = a3[1] - a2[1];
  v13 = a3[2] - a2[2];
  v30 = sqrt(v13 * v13 + v12 * v12 + v11 * v11);
  sub_5C1720(&v26, a5, v31);
  qmemcpy(v33, v31, sizeof(v33));
  sub_5C1840(v33);
  qmemcpy(v32, v33, sizeof(v32));
  v14 = v32[6] * v27 + v32[2] * v26 + v32[10] * v28;
  v15 = v32[5] * v27 + v32[1] * v26 + v32[9] * v28;
  v16 = v14 * v14 + v15 * v15;
  v17 = v32[4] * v27 + v32[0] * v26 + v32[8] * v28;
  v18 = sqrt(v16 + v17 * v17);
  v29 = v25 * v25;
  v19 = (v18 + (v29 - v30 * v30) / v18) * 0.5;
  if ( v25 < v19 )
    v19 = v25;
  if ( v19 < 0.0 )
    v19 = 0.0;
  v20 = v29 - v19 * v19;
  if ( v20 > 0.0 )
    v21 = sqrt(v20);
  else
    v21 = 0.0000099999997;
  v27 = v31[5] * v21 + v31[1] * v19 + v31[9] * 0.0;
  v28 = v31[6] * v21 + v31[2] * v19 + v31[10] * 0.0;
  v22 = v27 + a1[1];
  v23 = v28 + a1[2];
  *a6 = v31[4] * v21 + v31[0] * v19 + v31[8] * 0.0 + *a1;
  a6[1] = v22;
  a6[2] = v23;
  return v19 > 0.0 && v19 < v25;
}
