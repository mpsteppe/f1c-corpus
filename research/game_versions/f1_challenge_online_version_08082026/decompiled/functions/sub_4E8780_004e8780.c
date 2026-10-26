double __thiscall sub_4E8780(float *this)
{
  double result; // st7

  if ( this[3691] == 0.0 )
    return 0.0;
  result = -(this[3690] / this[3691]);
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
