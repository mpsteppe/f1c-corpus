int __thiscall sub_4521D0(float *this, int a2, float a3, float a4, float a5)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7

  v5 = a4;
  if ( a4 >= 0.0 )
  {
    if ( v5 > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  this[a2 + 8] = v5;
  v6 = a3;
  if ( a3 < 0.0 )
    v6 = 0.0;
  this[a2 + 190] = v6;
  v7 = a5;
  if ( a5 >= 0.0 )
  {
    if ( v7 > 1.0 )
      v7 = 1.0;
    this[a2] = v7;
    return sub_451E80((int)this);
  }
  else
  {
    this[a2] = 0.0;
    return sub_451E80((int)this);
  }
}
