int __thiscall sub_4974A0(float *this)
{
  double v2; // st7

  v2 = this[149] - dbl_FB1D08;
  this[149] = v2;
  if ( v2 <= 0.0 )
  {
    sub_497320();
    this[149] = 3.5;
  }
  return 0;
}
