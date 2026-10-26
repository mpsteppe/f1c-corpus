void __fastcall sub_56C540(double *a1, double *a2, double *a3)
{
  double v3; // st7
  long double v4; // st7
  double v5; // [esp+4h] [ebp-10h]
  double v6; // [esp+Ch] [ebp-8h]

  *a3 = a2[2] * a1[1] - a2[1] * a1[2];
  a3[1] = *a2 * a1[2] - *a1 * a2[2];
  v3 = *a1 * a2[1] - *a2 * a1[1];
  a3[2] = v3;
  if ( *a3 != 0.0 || a3[1] != 0.0 || v3 != 0.0 )
  {
    v5 = *a1 * *a2 + a2[2] * a1[2] + a2[1] * a1[1];
    v6 = a3[1] * a3[1] + *a3 * *a3 + v3 * v3;
    if ( v5 > 1.0 )
      v5 = 1.0;
    sub_5894A0();
    v4 = v5 / sqrt(v6);
    *a3 = v4 * *a3;
    a3[1] = v4 * a3[1];
    a3[2] = v4 * a3[2];
  }
}
