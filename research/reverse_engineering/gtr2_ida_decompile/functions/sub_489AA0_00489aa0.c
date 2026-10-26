void __thiscall sub_489AA0(float *this, float a2)
{
  this[3] = this[3] - a2;
  if ( this[3] >= 0.0 )
  {
    if ( this[3] > (double)a2 )
      this[3] = a2;
  }
  else
  {
    this[3] = 0.0;
  }
}
