void __thiscall sub_40D5D0(float *this, int a2)
{
  long double v2; // st7

  *(float *)a2 = -asin(this[5]);
  if ( 1.0 == fabs(this[5]) )
  {
    v2 = atan2(-this[6], *this);
    *(_DWORD *)(a2 + 8) = 0;
    *(float *)(a2 + 4) = v2;
  }
  else
  {
    *(float *)(a2 + 4) = atan2(this[2], this[8]);
    *(float *)(a2 + 8) = atan2(this[3], this[4]);
  }
}
