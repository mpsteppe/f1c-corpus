void __thiscall sub_4FECD0(float *this, float a2, float a3)
{
  double v3; // st7

  if ( a3 <= 0.0 )
    v3 = 3.4028235e38;
  else
    v3 = a3;
  this[1] = v3;
  *this = (a2 - 1.0) / v3;
}
