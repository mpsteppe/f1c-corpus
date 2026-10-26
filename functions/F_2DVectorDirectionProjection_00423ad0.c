double __fastcall sub_423AD0(float *a1, float *a2)
{
  double v2; // st7

  v2 = *a1 * *a1 + a1[2] * a1[2];
  if ( v2 == 0.0 )
    return 0.0;
  else
    return (a2[2] * a1[2] + *a1 * *a2) / v2;
}
