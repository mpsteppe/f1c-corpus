void __thiscall sub_409390(float *this)
{
  long double v1; // st4
  long double v2; // st7

  v1 = *this * *this + this[1] * this[1] + this[2] * this[2];
  if ( v1 > 0.0 )
  {
    v2 = 1.0 / sqrt(v1);
    *this = v2 * *this;
    this[1] = v2 * this[1];
    this[2] = v2 * this[2];
  }
}
