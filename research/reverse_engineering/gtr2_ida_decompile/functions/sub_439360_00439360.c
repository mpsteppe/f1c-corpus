double __fastcall sub_439360(float *a1, float *a2, float *a3, float *a4)
{
  double v4; // st7
  double v6; // st6
  double v7; // st5
  double v9; // st7
  double v10; // st6
  float v11; // [esp+4h] [ebp-8h]
  float v12; // [esp+8h] [ebp-4h]
  float v13; // [esp+10h] [ebp+4h]
  float v14; // [esp+10h] [ebp+4h]
  float v15; // [esp+14h] [ebp+8h]

  v4 = *a3 - *a1;
  v11 = *a2;
  v6 = *a4;
  v12 = a2[2];
  v15 = a3[2] - a1[2];
  v7 = a4[2];
  if ( v6 == 0.0 )
  {
    if ( v7 == 0.0 )
      return 3.4028235e38;
    v13 = v6 / v7;
    v9 = v4 - v13 * v15;
    v10 = v11 - v13 * v12;
  }
  else
  {
    v14 = v7 / v6;
    v9 = v15 - v4 * v14;
    v10 = v12 - v14 * v11;
  }
  if ( v10 == 0.0 )
    return 3.4028235e38;
  return v9 / v10;
}
