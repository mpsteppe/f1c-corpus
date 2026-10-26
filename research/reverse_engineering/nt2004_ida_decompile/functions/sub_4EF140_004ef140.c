void __thiscall sub_4EF140(float *this, float a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7

  v2 = a2 * 0.125;
  if ( v2 >= 0.050000001 )
    v2 = 0.050000001;
  if ( this[1] >= 1.0 )
  {
    v4 = this[1] - v2;
    this[1] = v4;
    if ( v4 < 1.0 )
      this[1] = 1.0;
  }
  else
  {
    v3 = v2 + this[1];
    this[1] = v3;
    if ( v3 > 1.0 )
      this[1] = 1.0;
  }
}
