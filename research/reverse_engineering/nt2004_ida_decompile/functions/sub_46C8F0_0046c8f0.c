void __thiscall sub_46C8F0(float *this, float a2)
{
  this[13] = this[13] - a2;
  if ( this[13] >= 0.0 )
  {
    if ( this[13] > (double)a2 )
      this[13] = a2;
  }
  else
  {
    this[13] = 0.0;
  }
}
