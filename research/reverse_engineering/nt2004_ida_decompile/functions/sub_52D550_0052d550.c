_DWORD *__fastcall sub_52D550(float *a1, float *a2, float *a3, float *a4, float a5, _DWORD *a6)
{
  double v7; // st6
  double v8; // st5
  double v9; // st3
  long double v10; // st7
  _DWORD *result; // eax
  long double v12; // st4
  long double v13; // st7
  long double v14; // st4
  long double v15; // st7
  double v16; // st7
  double v17; // st6
  double v18; // st7
  float v19; // [esp+4h] [ebp-58h]
  float v20; // [esp+8h] [ebp-54h]
  float v21; // [esp+Ch] [ebp-50h]
  float v22; // [esp+10h] [ebp-4Ch]
  float v23; // [esp+10h] [ebp-4Ch]
  float v24; // [esp+14h] [ebp-48h]
  float v25; // [esp+18h] [ebp-44h]
  float v26; // [esp+1Ch] [ebp-40h]
  float v27; // [esp+28h] [ebp-34h]
  float v28; // [esp+3Ch] [ebp-20h]
  float v29; // [esp+40h] [ebp-1Ch]
  float v30; // [esp+48h] [ebp-14h]
  float v31; // [esp+4Ch] [ebp-10h]
  int v32; // [esp+60h] [ebp+4h]
  float v33; // [esp+60h] [ebp+4h]
  float v34; // [esp+64h] [ebp+8h]
  float v35; // [esp+68h] [ebp+Ch]

  v7 = a3[1] - a1[1];
  v8 = a3[2] - a1[2];
  v9 = *a3 - *a1;
  v10 = sqrt(v8 * v8 + v7 * v7 + v9 * v9);
  *(float *)&v32 = v10;
  if ( v10 <= 0.0 || a5 == 0.0 )
  {
    result = a6;
    *a6 = *(_DWORD *)a1;
    a6[1] = *((_DWORD *)a1 + 1);
    a6[2] = *((_DWORD *)a1 + 2);
  }
  else if ( a5 == 1.0 )
  {
    result = a6;
    *a6 = *(_DWORD *)a3;
    a6[1] = *((_DWORD *)a3 + 1);
    a6[2] = *((_DWORD *)a3 + 2);
  }
  else
  {
    v12 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
    if ( v12 > 0.0 )
    {
      v13 = 1.0 / sqrt(v12);
      *a2 = v13 * *a2;
      a2[1] = v13 * a2[1];
      a2[2] = v13 * a2[2];
    }
    v14 = *a4 * *a4 + a4[1] * a4[1] + a4[2] * a4[2];
    if ( v14 > 0.0 )
    {
      v15 = 1.0 / sqrt(v14);
      *a4 = v15 * *a4;
      a4[1] = v15 * a4[1];
      a4[2] = v15 * a4[2];
    }
    v16 = a5 * a5;
    v28 = a1[1];
    v17 = a5 * v16;
    v22 = *(float *)&v32 * a2[2];
    v24 = *a1 - *(float *)&v32 * *a2;
    v25 = v28 - *(float *)&v32 * a2[1];
    v29 = a1[2];
    v26 = v29 - v22;
    v30 = a3[1];
    v31 = a3[2];
    v27 = *(float *)&v32 * a4[2];
    v20 = *(float *)&v32 * *a4 + *a3;
    v21 = *(float *)&v32 * a4[1] + v30;
    v23 = v27 + v31;
    v19 = a5 * 0.0;
    v34 = 3.0 * v17 - v16 * 5.0 + v19 + 2.0;
    v33 = v16 * 4.0 - 3.0 * v17 + a5;
    v35 = v16 + v16 - v17 - a5;
    v18 = v17 - v16 + v19;
    result = a6;
    *(float *)a6 = (v35 * v24 + v33 * *a3 + v34 * *a1 + v18 * v20) * 0.5;
    *((float *)a6 + 1) = (v33 * v30 + v34 * v28 + v18 * v21 + v35 * v25) * 0.5;
    *((float *)a6 + 2) = (v33 * v31 + v34 * v29 + v18 * v23 + v35 * v26) * 0.5;
  }
  return result;
}
