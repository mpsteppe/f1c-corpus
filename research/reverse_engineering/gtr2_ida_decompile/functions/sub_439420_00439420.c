void __thiscall sub_439420(double *this, double a2, double a3, double a4)
{
  double v4; // st7

  *this = a2;
  this[1] = a3 + a3;
  if ( a3 <= 0.0 )
    v4 = 0.0;
  else
    v4 = 3.141592653589793 / a3;
  this[2] = v4;
  this[3] = (a4 - 1.0) * 0.5;
}
