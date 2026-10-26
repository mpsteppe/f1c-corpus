void __fastcall sub_5791A0(float *a1, int a2)
{
  long double v2; // st7

  *(float *)a2 = -asin(a1[5]);
  if ( fabs(a1[5]) == 1.0 )
  {
    v2 = atan2(-a1[6], *a1);
    *(_DWORD *)(a2 + 8) = 0;
    *(float *)(a2 + 4) = v2;
  }
  else
  {
    *(float *)(a2 + 4) = atan2(a1[2], a1[8]);
    *(float *)(a2 + 8) = atan2(a1[3], a1[4]);
  }
}
