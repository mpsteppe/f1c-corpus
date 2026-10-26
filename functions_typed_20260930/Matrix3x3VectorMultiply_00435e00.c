double *__thiscall sub_435E00(double *this, double *a2, double *a3)
{
  double *result; // eax

  result = a2;
  *a3 = this[2] * a2[2] + this[1] * a2[1] + *a2 * *this;
  a3[1] = this[3] * *a2 + this[5] * a2[2] + this[4] * a2[1];
  a3[2] = this[6] * *a2 + this[8] * a2[2] + this[7] * a2[1];
  return result;
}

