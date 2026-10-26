void __thiscall sub_4FF040(float *this, float a2, float a3)
{
  this[63] = 1.0 - a2;
  if ( this[63] >= 0.0 )
  {
    if ( this[63] > 1.0 )
      this[63] = 1.0;
  }
  else
  {
    this[63] = 0.0;
  }
  this[64] = 1.0 - a3;
  if ( this[63] <= (double)this[64] )
  {
    if ( this[64] > 1.0 )
      this[64] = 1.0;
  }
  else
  {
    this[64] = this[63];
  }
}

