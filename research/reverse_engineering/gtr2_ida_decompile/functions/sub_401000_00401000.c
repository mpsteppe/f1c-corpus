double __stdcall sub_401000(double a1, double a2, double a3, double a4, double a5, double a6)
{
  double v6; // st7
  double v7; // st6
  double v8; // st6
  double v9; // st7
  double v10; // st6
  double v12; // st7
  long double v13; // st5
  double v14; // [esp+0h] [ebp-20h]
  double v15; // [esp+0h] [ebp-20h]
  double v16; // [esp+8h] [ebp-18h]
  double v17; // [esp+10h] [ebp-10h]
  double v18; // [esp+18h] [ebp-8h]
  double v19; // [esp+24h] [ebp+4h]
  double v20; // [esp+24h] [ebp+4h]
  double v21; // [esp+24h] [ebp+4h]
  double v22; // [esp+2Ch] [ebp+Ch]
  double v23; // [esp+44h] [ebp+24h]

  v14 = a1 * a1 + a2 * a2;
  v17 = v14 - a3 * a3 - a4 * a4;
  v19 = a1 + a1;
  v16 = a3 + a3 - v19;
  v18 = a2 + a2;
  v6 = a4 + a4 - v18;
  v15 = v14 - a5 * a5 - a6 * a6;
  v22 = a5 + a5 - v19;
  v20 = a6 + a6 - v18;
  if ( v6 == 0.0 )
  {
    if ( v20 == 0.0 )
      return 0.0;
    v7 = v17;
    v17 = v15;
    v15 = v7;
    v8 = v16;
    v16 = v22;
    v22 = v8;
    v23 = v6;
    v6 = v20;
    v20 = v23;
  }
  v9 = -(v20 / v6);
  v10 = v16 * v9 + v22;
  if ( v10 == 0.0 )
    return 0.0;
  v12 = (v9 * v17 + v15) * (-1.0 / v10);
  if ( v20 == 0.0 )
    return 0.0;
  v21 = (v22 * v12 + v15) * (-1.0 / v20);
  v13 = sqrt((v21 - a4) * (v21 - a4) + (v12 - a3) * (v12 - a3));
  if ( v13 == 0.0 )
    return 0.0;
  return 1.0 / v13;
}
