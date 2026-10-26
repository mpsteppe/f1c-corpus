char __fastcall sub_5795E0(float *a1, float *a2, int a3)
{
  long double v3; // st7
  long double v4; // st7
  char v5; // cl
  bool v6; // al
  long double v7; // st7
  char result; // al
  float v9; // [esp+4h] [ebp-24h]
  float v10; // [esp+8h] [ebp-20h]
  float v11; // [esp+8h] [ebp-20h]
  float v12; // [esp+Ch] [ebp-1Ch]
  float v13; // [esp+Ch] [ebp-1Ch]
  float v14; // [esp+10h] [ebp-18h]
  float v15; // [esp+10h] [ebp-18h]
  float v16; // [esp+14h] [ebp-14h]
  float v17; // [esp+14h] [ebp-14h]
  float v18; // [esp+18h] [ebp-10h]
  float v19; // [esp+18h] [ebp-10h]
  float v20; // [esp+1Ch] [ebp-Ch]
  float v21; // [esp+1Ch] [ebp-Ch]
  float v22; // [esp+1Ch] [ebp-Ch]
  float v23; // [esp+20h] [ebp-8h]
  float v24; // [esp+20h] [ebp-8h]
  float v25; // [esp+20h] [ebp-8h]
  float v26; // [esp+24h] [ebp-4h]
  float v27; // [esp+24h] [ebp-4h]
  float v28; // [esp+24h] [ebp-4h]

  if ( !a3 || *a1 == 0.0 && a1[1] == 0.0 && a1[2] == 0.0 || *a2 == 0.0 && a2[1] == 0.0 && a2[2] == 0.0 )
    return 0;
  v20 = -*a1;
  v23 = -a1[1];
  v10 = a2[1];
  v26 = -a1[2];
  v12 = a2[2];
  v3 = 1.0 / sqrt(v12 * v12 + v10 * v10 + *a2 * *a2);
  v9 = *a2 * v3;
  v11 = v10 * v3;
  v13 = v3 * v12;
  v4 = 1.0 / sqrt(v26 * v26 + v23 * v23 + v20 * v20);
  v14 = v20 * v4;
  v16 = v23 * v4;
  v18 = v4 * v26;
  if ( v14 != v9 )
    goto LABEL_12;
  if ( v16 == v11 && v18 == v13 )
    v5 = 1;
  else
LABEL_12:
    v5 = 0;
  v6 = -v9 == v14 && -v11 == v16 && -v13 == v18;
  if ( v5 || v6 )
    return 0;
  v21 = v18 * v11 - v13 * v16;
  v24 = v13 * v14 - v18 * v9;
  v27 = v16 * v9 - v11 * v14;
  v7 = 1.0 / sqrt(v27 * v27 + v24 * v24 + v21 * v21);
  v15 = v21 * v7;
  v17 = v24 * v7;
  v19 = v7 * v27;
  v25 = v19 * v9 - v15 * v13;
  *(float *)a3 = -asin(v25);
  if ( fabs(v25) == 1.0 )
  {
    *(_DWORD *)(a3 + 8) = 0;
    result = 1;
    *(float *)(a3 + 4) = atan2(-v19, v15);
  }
  else
  {
    result = 1;
    v22 = v17 * v13 - v19 * v11;
    v28 = v15 * v11 - v17 * v9;
    *(float *)(a3 + 4) = atan2(v22, v28);
    *(float *)(a3 + 8) = atan2(v17, v11);
  }
  return result;
}
