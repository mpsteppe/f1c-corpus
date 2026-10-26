double __thiscall sub_406020(float *this, float a2)
{
  double v2; // st7

  v2 = this[7] * a2 + this[8];
  if ( v2 >= 1.0 )
    return (1.0 / v2 + (1.0 / v2 * (1.0 / v2) * (1.0 / v2) - 1.0 / v2) * this[9]) * this[16];
  else
    return this[16];
}

