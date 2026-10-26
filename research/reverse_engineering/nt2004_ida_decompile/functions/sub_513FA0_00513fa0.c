double __thiscall sub_513FA0(float *this)
{
  double result; // st7

  if ( this[4690] == 0.0 )
    return 0.0;
  result = -(this[4689] / this[4690]);
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
