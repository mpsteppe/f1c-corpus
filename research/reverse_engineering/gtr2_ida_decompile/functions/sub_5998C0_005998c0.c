float *__stdcall sub_5998C0(float *a1, float *a2, float *a3)
{
  float *v3; // ecx
  double i; // st7
  double v5; // st7
  int v6; // eax
  double v7; // st6
  float v8; // edx
  double v9; // st5
  double v10; // st4
  long double v11; // st4
  double v12; // st4
  double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st3
  long double v17; // st3
  float *result; // eax
  double v19; // st3
  double v20; // st5
  double v21; // st6
  float v22; // [esp+0h] [ebp-18h]
  float v23; // [esp+0h] [ebp-18h]
  float v24; // [esp+4h] [ebp-14h]
  float v25; // [esp+8h] [ebp-10h]
  float v26; // [esp+Ch] [ebp-Ch]
  float v27; // [esp+Ch] [ebp-Ch]
  float v28; // [esp+Ch] [ebp-Ch]
  float v29; // [esp+Ch] [ebp-Ch]
  float v30; // [esp+Ch] [ebp-Ch]
  float v31; // [esp+10h] [ebp-8h]
  float v32; // [esp+10h] [ebp-8h]
  float v33; // [esp+10h] [ebp-8h]
  float v34; // [esp+10h] [ebp-8h]
  float v35; // [esp+14h] [ebp-4h]
  float v36; // [esp+14h] [ebp-4h]
  float v37; // [esp+14h] [ebp-4h]
  float v38; // [esp+14h] [ebp-4h]
  float v39; // [esp+1Ch] [ebp+4h]
  float v40; // [esp+1Ch] [ebp+4h]

  v3 = a1;
  v26 = *a2 - a1[38];
  v31 = a2[1] - a1[39];
  v35 = a2[2] - a1[40];
  for ( i = v35 * a1[44] + v31 * a1[43] + v26 * a1[42]; i < 0.0; i = v36 * v3[44] + v32 * v3[43] + v27 * v3[42] )
  {
    v3 = (float *)*((_DWORD *)v3 + 68);
    v27 = *a2 - v3[38];
    v32 = a2[1] - v3[39];
    v36 = a2[2] - v3[40];
  }
  for ( ; i > v3[16]; i = v37 * v3[44] + v33 * v3[43] + v28 * v3[42] )
  {
    v3 = (float *)*((_DWORD *)v3 + 69);
    v28 = *a2 - v3[38];
    v33 = a2[1] - v3[39];
    v37 = a2[2] - v3[40];
  }
  v5 = i / v3[16];
  if ( v5 >= 0.0 )
  {
    if ( v5 > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = *((_DWORD *)v3 + 69);
  v7 = *(float *)(*(_DWORD *)(v6 + 276) + 152) - v3[38];
  v8 = *(float *)(*(_DWORD *)(v6 + 276) + 160);
  v9 = *(float *)(*(_DWORD *)(v6 + 276) + 156) - v3[39];
  v6 += 152;
  v10 = v8 - v3[40];
  v38 = v10;
  v11 = 1.0 / sqrt(v10 * v38 + v9 * v9 + v7 * v7);
  v39 = v11;
  v29 = v11 * v7;
  v12 = *(float *)(v6 - 8);
  v30 = v29 * v12;
  v34 = v12 * (v39 * v9);
  v13 = v12 * (v39 * v38);
  v14 = *(float *)v6 - *(float *)(*((_DWORD *)v3 + 68) + 152);
  v15 = *(float *)(v6 + 4) - *(float *)(*((_DWORD *)v3 + 68) + 156);
  v16 = *(float *)(v6 + 8) - *(float *)(*((_DWORD *)v3 + 68) + 160);
  v25 = v16;
  v17 = 1.0 / sqrt(v16 * v25 + v15 * v15 + v14 * v14);
  result = a3;
  v40 = v17;
  v22 = v17 * v14;
  v19 = v3[36];
  v23 = v22 * v19;
  v24 = v19 * (v40 * v15);
  *a3 = (v30 - v23) * v5 + v23;
  a3[1] = (v34 - v24) * v5 + v24;
  v20 = v13;
  v21 = v19 * (v40 * v25);
  a3[2] = (v20 - v21) * v5 + v21;
  return result;
}
