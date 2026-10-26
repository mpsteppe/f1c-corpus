float *__stdcall sub_52D830(float *a1, float *a2, float *a3)
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
  float v28; // [esp+10h] [ebp-8h]
  float v29; // [esp+14h] [ebp-4h]
  float v30; // [esp+1Ch] [ebp+4h]
  float v31; // [esp+1Ch] [ebp+4h]

  v3 = a1;
  for ( i = (a2[2] - a1[51]) * a1[55] + (a2[1] - a1[50]) * a1[54] + (*a2 - a1[49]) * a1[53];
        i < 0.0;
        i = (a2[2] - v3[51]) * v3[55] + (a2[1] - v3[50]) * v3[54] + (*a2 - v3[49]) * v3[53] )
  {
    v3 = (float *)*((_DWORD *)v3 + 73);
  }
  for ( ; i > v3[26]; i = (a2[2] - v3[51]) * v3[55] + (a2[1] - v3[50]) * v3[54] + (*a2 - v3[49]) * v3[53] )
    v3 = (float *)*((_DWORD *)v3 + 74);
  v5 = i / v3[26];
  if ( v5 >= 0.0 )
  {
    if ( v5 > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  v6 = *((_DWORD *)v3 + 74);
  v7 = *(float *)(*(_DWORD *)(v6 + 296) + 196) - v3[49];
  v8 = *(float *)(*(_DWORD *)(v6 + 296) + 204);
  v9 = *(float *)(*(_DWORD *)(v6 + 296) + 200) - v3[50];
  v6 += 196;
  v10 = v8 - v3[51];
  v29 = v10;
  v11 = 1.0 / sqrt(v10 * v29 + v9 * v9 + v7 * v7);
  v30 = v11;
  v26 = v11 * v7;
  v12 = *(float *)(v6 - 8);
  v27 = v26 * v12;
  v28 = v12 * (v30 * v9);
  v13 = v12 * (v30 * v29);
  v14 = *(float *)v6 - *(float *)(*((_DWORD *)v3 + 73) + 196);
  v15 = *(float *)(v6 + 4) - *(float *)(*((_DWORD *)v3 + 73) + 200);
  v16 = *(float *)(v6 + 8) - *(float *)(*((_DWORD *)v3 + 73) + 204);
  v25 = v16;
  v17 = 1.0 / sqrt(v16 * v25 + v15 * v15 + v14 * v14);
  v31 = v17;
  v22 = v17 * v14;
  result = a3;
  v19 = v3[47];
  v23 = v22 * v19;
  v24 = v19 * (v31 * v15);
  *a3 = (v27 - v23) * v5 + v23;
  a3[1] = (v28 - v24) * v5 + v24;
  v20 = v13;
  v21 = v19 * (v31 * v25);
  a3[2] = (v20 - v21) * v5 + v21;
  return result;
}
