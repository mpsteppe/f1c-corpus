float *__thiscall sub_5D1DF0(float *this)
{
  long double v1; // st3
  long double v2; // st7
  long double v3; // st7
  float *result; // eax

  v1 = *this * *this + this[1] * this[1] + this[2] * this[2] + this[3] * this[3];
  if ( v1 == 0.0 )
    v2 = 0.0;
  else
    v2 = sqrt(v1);
  v3 = 1.0 / v2;
  result = this;
  *this = v3 * *this;
  this[1] = v3 * this[1];
  this[2] = v3 * this[2];
  this[3] = v3 * this[3];
  return result;
}
