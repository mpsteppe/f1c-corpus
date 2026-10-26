void __thiscall sub_40B040(float *this, float a2)
{
  if ( a2 >= 0.001 )
  {
    if ( a2 <= 10.0 )
      this[35] = a2;
    else
      this[35] = 10.0;
  }
  else
  {
    this[35] = 0.001;
  }
}
