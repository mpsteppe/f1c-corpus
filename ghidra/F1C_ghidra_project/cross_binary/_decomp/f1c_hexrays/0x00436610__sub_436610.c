// f1c  0x00436610  size=208
double __thiscall sub_436610(double *this, double a2, double a3)
{
  double v3; // st6
  double result; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st6
  double v9; // st6

  if ( a3 <= 0.0 )
  {
    if ( a3 >= this[7] )
      v3 = a3 * this[6];
    else
      v3 = a3 * this[5] + this[8];
  }
  else if ( a3 <= this[3] )
  {
    v3 = a3 * this[2];
  }
  else
  {
    v3 = a3 * this[1] + this[4];
  }
  result = a2 * *this + v3;
  if ( a2 <= this[14] )
    v5 = this[14] - a2;
  else
    v5 = a2 - this[13];
  if ( v5 > 0.0 )
  {
    v6 = v5 * this[10] + this[9];
    v7 = v5 * this[12] + this[11];
    if ( a2 <= 0.0 )
    {
      v9 = v7 * a3 - v6 * v5;
      if ( v9 < 0.0 )
        return result + v9;
    }
    else
    {
      v8 = v5 * v6 + v7 * a3;
      if ( v8 > 0.0 )
        return result + v8;
    }
  }
  return result;
}
