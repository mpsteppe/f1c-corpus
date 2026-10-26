double __thiscall sub_578E80(float *this)
{
  double result; // st7

  result = this[4303] / this[4304];
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
