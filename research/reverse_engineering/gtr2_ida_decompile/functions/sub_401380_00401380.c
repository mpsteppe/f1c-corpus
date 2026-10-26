void __thiscall sub_401380(float *this)
{
  long double v1; // st4

  v1 = sqrt(*this * *this + this[1] * this[1] + this[2] * this[2]);
  *this = 1.0 / v1 * *this;
  this[1] = 1.0 / v1 * this[1];
  this[2] = 1.0 / v1 * this[2];
}
