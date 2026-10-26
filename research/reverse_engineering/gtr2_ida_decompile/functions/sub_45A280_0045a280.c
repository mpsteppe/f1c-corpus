float *__thiscall sub_45A280(double *this, float a2, float a3, float *a4)
{
  float *result; // eax
  double v5; // st7
  double v6; // st6
  long double v7; // st5

  result = a4;
  v5 = a2 * *this + a2 * *this + a3 * this[2] + this[3];
  v6 = a3 * this[1] + a3 * this[1] + a2 * this[2] + this[4];
  v7 = 1.0 / sqrt(v6 * v6 + v5 * v5 + 1.0);
  *a4 = -(v7 * v5);
  a4[1] = v7;
  a4[2] = -(v7 * v6);
  return result;
}
