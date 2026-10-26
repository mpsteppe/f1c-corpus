double __thiscall sub_578630(float *this)
{
  double result; // st7

  result = fabs(this[4290] / this[4291]);
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
