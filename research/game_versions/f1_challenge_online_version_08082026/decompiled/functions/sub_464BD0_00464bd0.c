void __thiscall sub_464BD0(float *this, float a2)
{
  this[26] = this[26] - a2;
  if ( this[26] >= 0.0 )
  {
    if ( this[26] > (double)a2 )
      this[26] = a2;
  }
  else
  {
    this[26] = 0.0;
  }
}
