void __thiscall sub_58BCB0(float *this, float a2, float a3)
{
  double v3; // st7
  double v4; // st6

  v3 = a2;
  v4 = a3;
  if ( a2 >= (double)a3 )
  {
    v3 = (v3 + v4) * 0.5;
    v4 = v3 + 0.001;
  }
  *this = v3;
  this[1] = v4;
  this[2] = 1.0 / (v4 - v3);
}
