void __fastcall sub_614B30(float *a1, int a2)
{
  long double v2; // st7

  *(float *)a2 = -asin(a1[5]);
  if ( 1.0 == fabs(a1[5]) )
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
