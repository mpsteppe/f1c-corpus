double __thiscall sub_51E730(float *this)
{
  double result; // st7

  result = fabs(this[4672] / this[4673]);
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
