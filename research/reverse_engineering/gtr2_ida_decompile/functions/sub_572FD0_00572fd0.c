double __thiscall sub_572FD0(float *this)
{
  double result; // st7

  if ( this[4309] == 0.0 )
    return 0.0;
  result = -(this[4308] / this[4309]);
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
