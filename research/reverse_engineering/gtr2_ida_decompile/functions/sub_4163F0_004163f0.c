int __thiscall sub_4163F0(float *this, float a2)
{
  double v2; // st7

  v2 = 1.0 / a2;
  *this = v2 * *this;
  this[1] = v2 * this[1];
  this[2] = v2 * this[2];
  return nullsub_3(LODWORD(a2));
}
