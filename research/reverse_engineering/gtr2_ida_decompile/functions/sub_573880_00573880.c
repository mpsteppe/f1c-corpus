int __thiscall sub_573880(float *this, float a2)
{
  int result; // eax
  double v3; // st7

  if ( a2 == 0.0 )
    a2 = 0.1;
  result = LODWORD(a2);
  v3 = this[4295] * 0.74000001;
  this[4017] = a2;
  this[4009] = v3 + this[4008] + a2;
  return result;
}
