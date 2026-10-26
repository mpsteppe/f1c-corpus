double __thiscall sub_439AD0(double *this)
{
  double v1; // st7
  double v2; // st6

  if ( this[150] <= this[310] )
    v1 = this[310];
  else
    v1 = this[150];
  if ( this[470] <= this[630] )
    v2 = this[630];
  else
    v2 = this[470];
  if ( v1 <= v2 )
  {
    if ( this[470] <= this[630] )
      return this[630];
    else
      return this[470];
  }
  else if ( this[150] <= this[310] )
  {
    return this[310];
  }
  else
  {
    return this[150];
  }
}
