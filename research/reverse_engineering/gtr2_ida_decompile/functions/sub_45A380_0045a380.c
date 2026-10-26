bool __fastcall sub_45A380(double *a1, double *a2, double *a3, double *a4)
{
  double *v4; // esi
  double *v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st4
  double v10; // st3
  double v12; // st7
  double v13; // st7
  long double v14; // st7
  double v15; // [esp+10h] [ebp-38h]
  double v16; // [esp+18h] [ebp-30h]
  double v17; // [esp+20h] [ebp-28h]
  double v18; // [esp+28h] [ebp-20h]
  double v19; // [esp+30h] [ebp-18h]
  double v20; // [esp+38h] [ebp-10h]
  double v21; // [esp+40h] [ebp-8h]
  double v22; // [esp+40h] [ebp-8h]

  if ( *a2 == *a1 )
  {
    if ( *a4 == *a3 )
      return 0;
    v4 = a1;
    v5 = a2;
    a1 = a3;
    a2 = a4;
  }
  else
  {
    v5 = a4;
    v4 = a3;
  }
  v6 = *a1;
  v19 = *a2 - v6;
  v7 = a1[1];
  v18 = a2[1] - v7;
  v17 = *v4;
  v15 = *v5 - v17;
  v8 = v4[1];
  v20 = v5[1] - v8;
  v21 = 1.0 / v19;
  v9 = -(v21 * v18);
  v10 = v15 * v9 + v20;
  if ( v10 == 0.0 )
    return 0;
  v16 = (v9 * v6 + v7 - (v9 * v17 + v8)) / v10;
  if ( v16 <= 0.0 )
    return 0;
  if ( v16 >= 1.0 )
    return 0;
  v12 = (v16 * v15 + v17 - v6) * v21;
  if ( v12 <= 0.0 )
    return 0;
  if ( v12 >= 1.0 )
    return 0;
  v22 = sqrt(v18 * v18 + v19 * v19);
  v13 = v12 * v22;
  if ( v13 <= 0.01 )
    return 0;
  if ( v13 >= v22 - 0.01 )
    return 0;
  v14 = sqrt(v20 * v20 + v15 * v15);
  return v16 * v14 > 0.01 && v16 * v14 < v14 - 0.01;
}
