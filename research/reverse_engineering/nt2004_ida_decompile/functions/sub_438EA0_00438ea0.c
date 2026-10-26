double __thiscall sub_438EA0(double *this, double a2, double a3)
{
  double v3; // st6
  double result; // st7
  double v5; // st6
  double v6; // st6
  double v7; // st6
  double v8; // st5

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
  {
    v7 = this[14] - a2;
    if ( v7 > 0.0 )
    {
      v8 = (v7 * this[12] + this[11]) * a3 - (v7 * this[10] + this[9]) * v7;
      if ( v8 < 0.0 )
        return result + v8;
    }
  }
  else
  {
    v5 = a2 - this[13];
    if ( v5 > 0.0 )
    {
      v6 = (v5 * this[10] + this[9]) * v5 + (v5 * this[12] + this[11]) * a3;
      if ( v6 > 0.0 )
        return result + v6;
    }
  }
  return result;
}
