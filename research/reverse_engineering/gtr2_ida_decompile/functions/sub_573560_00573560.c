double __thiscall sub_573560(float *this)
{
  long double v1; // st4

  v1 = sqrt(this[3999] * this[3999] + this[4000] * this[4000] + this[4001] * this[4001]);
  if ( v1 == 0.0 )
    return 0.0;
  else
    return (this[4001] * this[3992] + this[4000] * this[3989] + this[3986] * this[3999]) * (-1.0 / v1);
}
