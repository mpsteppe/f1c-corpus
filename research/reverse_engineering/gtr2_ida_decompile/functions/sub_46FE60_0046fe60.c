double *__thiscall sub_46FE60(double *this, double *a2, double *a3)
{
  double *result; // eax

  result = a2;
  *a3 = this[32] * a2[2] + this[31] * a2[1] + this[30] * *a2;
  a3[1] = this[33] * *a2 + this[35] * a2[2] + this[34] * a2[1];
  a3[2] = this[36] * *a2 + this[38] * a2[2] + this[37] * a2[1];
  return result;
}
