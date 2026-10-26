double *__thiscall sub_43A530(double *this, double *a2, double *a3)
{
  double *result; // eax

  result = a2;
  *a3 = this[10] * a2[2] + this[7] * a2[1] + this[4] * *a2;
  a3[1] = this[5] * *a2 + this[11] * a2[2] + this[8] * a2[1];
  a3[2] = this[6] * *a2 + this[12] * a2[2] + this[9] * a2[1];
  return result;
}
