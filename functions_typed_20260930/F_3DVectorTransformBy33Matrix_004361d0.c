double *__thiscall sub_4361D0(double *this, double *a2, double *a3, double *a4)
{
  double v4; // st7
  double v5; // st6
  double *result; // eax
  double v7; // st5

  v4 = *a3 - *a2;
  v5 = a3[1] - a2[1];
  result = a4;
  v7 = a3[2] - a2[2];
  *a4 = v7 * this[6] + v5 * this[3] + v4 * *this;
  a4[1] = v7 * this[7] + v5 * this[4] + v4 * this[1];
  a4[2] = v7 * this[8] + v5 * this[5] + v4 * this[2];
  return result;
}

