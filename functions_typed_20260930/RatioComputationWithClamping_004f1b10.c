double __thiscall sub_4F1B10(float *this)
{
  double result; // st7

  result = fabs(this[3673] / this[3674]);
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}

