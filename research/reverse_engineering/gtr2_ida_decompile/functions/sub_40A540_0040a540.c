void __thiscall sub_40A540(float *this, float a2)
{
  if ( a2 >= 0.0 )
  {
    if ( a2 <= 1.0 )
      this[20] = a2;
    else
      this[20] = 1.0;
  }
  else
  {
    this[20] = 0.0;
  }
}
