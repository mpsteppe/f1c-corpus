long double __thiscall sub_439470(double *this, long double a2, double a3)
{
  long double result; // st7
  long double v4; // st5
  double v5; // [esp+0h] [ebp-8h]

  result = 1.0;
  if ( this[3] != 0.0 )
  {
    v5 = fabs(atan2(a2, -a3));
    if ( v5 < this[1] )
      result = (1.0 - cos(v5 * this[2])) * this[3] + 1.0;
  }
  v4 = a2 * a2 + a3 * a3;
  if ( v4 > 0.0 )
    return result * (1.0 - (1.0 - a3 * a3 / v4 * (a3 * a3 / v4) * (a3 * a3 / v4 * (a3 * a3 / v4))) * *this);
  return result;
}
