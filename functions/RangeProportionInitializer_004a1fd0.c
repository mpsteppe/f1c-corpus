void __thiscall sub_4A1FD0(float *this, float a2, float a3)
{
  double v3; // st7

  v3 = a3 - a2;
  *this = a2;
  this[1] = a3;
  if ( v3 <= 0.0 )
    this[2] = 0.0;
  else
    this[2] = 1.0 / v3;
}
