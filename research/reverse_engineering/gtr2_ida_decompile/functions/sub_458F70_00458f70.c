bool __stdcall sub_458F70(float *a1, float *a2, float *a3, float *a4)
{
  float *v4; // esi
  float *v5; // edi
  float *v6; // edx
  float *v7; // ecx
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st3
  double v14; // st7
  double v15; // st7
  long double v16; // st7
  double v17; // [esp+8h] [ebp-38h]
  double v18; // [esp+10h] [ebp-30h]
  double v19; // [esp+18h] [ebp-28h]
  double v20; // [esp+20h] [ebp-20h]
  double v21; // [esp+28h] [ebp-18h]
  double v22; // [esp+30h] [ebp-10h]
  double v23; // [esp+38h] [ebp-8h]
  double v24; // [esp+38h] [ebp-8h]

  v4 = a1;
  v5 = a3;
  if ( a1 == a3 )
    return 0;
  v6 = a4;
  if ( a1 == a4 )
    return 0;
  v7 = a2;
  if ( a2 == a3 && a2 == a4 )
    return 0;
  if ( *a2 == *a1 )
  {
    if ( *a4 == *a3 )
      return 0;
    v4 = a3;
    v5 = a1;
    v7 = a4;
    v6 = a2;
  }
  v8 = *v4;
  v21 = *v7 - v8;
  v9 = v4[4];
  v20 = v7[4] - v9;
  v19 = *v5;
  v17 = *v6 - v19;
  v10 = v5[4];
  v22 = v6[4] - v10;
  v23 = 1.0 / v21;
  v11 = -(v23 * v20);
  v12 = v17 * v11 + v22;
  if ( v12 == 0.0 )
    return 0;
  v18 = (v11 * v8 + v9 - (v11 * v19 + v10)) / v12;
  if ( v18 <= 0.0 )
    return 0;
  if ( v18 >= 1.0 )
    return 0;
  v14 = (v18 * v17 + v19 - v8) * v23;
  if ( v14 <= 0.0 )
    return 0;
  if ( v14 >= 1.0 )
    return 0;
  v24 = sqrt(v20 * v20 + v21 * v21);
  v15 = v14 * v24;
  if ( v15 <= 0.001 )
    return 0;
  if ( v15 >= v24 - 0.001 )
    return 0;
  v16 = sqrt(v22 * v22 + v17 * v17);
  return v18 * v16 > 0.001 && v18 * v16 < v16 - 0.001;
}
