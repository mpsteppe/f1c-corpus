double *__thiscall sub_43A590(double *this, double *a2, double *a3)
{
  double *result; // eax

  result = a3;
  *a3 = a2[2] * this[17] - a2[1] * this[18];
  a3[1] = *a2 * this[18] - this[16] * a2[2];
  a3[2] = this[16] * a2[1] - *a2 * this[17];
  *a3 = this[13] + *a3;
  a3[1] = this[14] + a3[1];
  a3[2] = this[15] + a3[2];
  return result;
}
