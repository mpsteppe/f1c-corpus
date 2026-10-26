void __stdcall sub_548520(float *a1, float *a2, float *a3, float *a4, float a5)
{
  double v5; // st7
  double v6; // st7
  double v7; // st6
  long double v8; // st7
  long double v9; // st7
  long double v10; // st6
  long double v11; // st5
  float v12; // [esp+4h] [ebp-24h]
  float v13; // [esp+4h] [ebp-24h]
  float v14; // [esp+8h] [ebp-20h]
  float v15; // [esp+8h] [ebp-20h]
  float v16; // [esp+Ch] [ebp-1Ch]
  float v17; // [esp+Ch] [ebp-1Ch]
  float v18; // [esp+10h] [ebp-18h]
  float v19; // [esp+10h] [ebp-18h]
  float v20; // [esp+10h] [ebp-18h]
  float v21; // [esp+10h] [ebp-18h]
  float v22; // [esp+14h] [ebp-14h]
  float v23; // [esp+14h] [ebp-14h]
  float v24; // [esp+14h] [ebp-14h]
  float v25; // [esp+14h] [ebp-14h]
  float v26; // [esp+18h] [ebp-10h]
  float v27; // [esp+18h] [ebp-10h]
  float v28; // [esp+18h] [ebp-10h]
  float v29; // [esp+18h] [ebp-10h]
  float v30; // [esp+1Ch] [ebp-Ch]
  float v31; // [esp+1Ch] [ebp-Ch]
  float v32; // [esp+20h] [ebp-8h]
  float v33; // [esp+20h] [ebp-8h]
  float v34; // [esp+24h] [ebp-4h]
  float v35; // [esp+24h] [ebp-4h]
  float v36; // [esp+3Ch] [ebp+14h]

  v12 = *(float *)&dword_903990 * *a3;
  v14 = *(float *)&dword_903990 * a3[1];
  v16 = *(float *)&dword_903990 * a3[2];
  v13 = *a4 - v12;
  v15 = a4[1] - v14;
  v17 = a4[2] - v16;
  v18 = *a3 * 0.5;
  v22 = a3[1] * 0.5;
  v26 = a3[2] * 0.5;
  v5 = *a2;
  v19 = v18 * v5;
  v23 = v22 * v5;
  v27 = v26 * v5;
  v20 = *a1 - v19;
  v24 = a1[1] - v23;
  v28 = a1[2] - v27;
  v21 = v20 - v13;
  v25 = v24 - v15;
  v29 = v28 - v17;
  if ( LOBYTE(a5) )
    v6 = flt_B713D4 + flt_903994;
  else
    v6 = flt_903994;
  if ( v29 * v29 + v25 * v25 + v21 * v21 < v6 )
  {
    v7 = v21 * *a3 + v29 * a3[2] + v25 * a3[1];
    v36 = v7;
    v30 = v7 * *a3;
    v32 = v36 * a3[1];
    v34 = v36 * a3[2];
    v31 = v21 - v30;
    v33 = v25 - v32;
    v35 = v29 - v34;
    v8 = v6 - (v35 * v35 + v33 * v33 + v31 * v31);
    if ( v8 > 0.0 )
    {
      v9 = sqrt(v8) - v36;
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
