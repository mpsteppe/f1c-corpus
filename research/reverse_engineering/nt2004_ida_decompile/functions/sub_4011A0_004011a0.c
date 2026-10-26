long double __stdcall sub_4011A0(double a1, double a2, double a3, double a4, double a5, double a6)
{
  double v6; // st7
  double v7; // st6
  double v9; // kr00_8
  unsigned int v10; // edx
  unsigned int v11; // eax
  double v12; // st7
  double v13; // st6
  double v14; // st7
  double v15; // st6
  long double v16; // st5
  double v17; // [esp+0h] [ebp-20h]
  double v18; // [esp+8h] [ebp-18h]
  double v19; // [esp+10h] [ebp-10h]
  double v20; // [esp+18h] [ebp-8h]
  double v21; // [esp+24h] [ebp+4h]
  double v22; // [esp+24h] [ebp+4h]
  double v23; // [esp+2Ch] [ebp+Ch]
  double v24; // [esp+44h] [ebp+24h]
  double v25; // [esp+4Ch] [ebp+2Ch]

  v19 = a1 * a1 + a2 * a2;
  v18 = v19 - a3 * a3 - a4 * a4;
  v21 = a1 + a1;
  v17 = a3 + a3 - v21;
  v20 = a2 + a2;
  v6 = a4 + a4 - v20;
  v23 = v19 - a5 * a5 - a6 * a6;
  v22 = a5 + a5 - v21;
  v7 = a6 + a6 - v20;
  v24 = v7;
  if ( v6 == 0.0 )
  {
    if ( v7 == 0.0 )
      return 0.0;
    v9 = v23;
    v23 = v18;
    v10 = LODWORD(v22);
    v18 = v9;
    v11 = HIDWORD(v22);
    v22 = v17;
    v25 = v6;
    v17 = COERCE_DOUBLE(__PAIR64__(v11, v10));
    v6 = v7;
    v7 = v25;
    v24 = v25;
  }
  v12 = -(v7 / v6);
  v13 = v17 * v12 + v22;
  if ( v13 == 0.0 )
    return 0.0;
  v14 = (v12 * v18 + v23) * (-1.0 / v13);
  if ( v24 == 0.0 )
    return 0.0;
  v15 = (v22 * v14 + v23) * (-1.0 / v24) - a4;
  v16 = sqrt(v15 * v15 + (v14 - a3) * (v14 - a3));
  if ( v16 == 0.0 )
    return 0.0;
  else
    return 1.0 / v16;
}
